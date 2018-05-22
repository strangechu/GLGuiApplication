#include "GLWidget.h"
#include <GL/glut.h>
#include "QmouseEvent"
#include <math.h>

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
}


GLWidget::~GLWidget()
{
}

void GLWidget::initializeGL()
{
	glClearColor(0.2, 0.2, 0.2, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 0, 0, 0, -5, 0, 1, 0);

	glTranslatef(0.0, 0.0, -10.0);
	glColor3f(1, 0, 0);
	glutSolidSphere(1, 20, 20);
}

void GLWidget::resizeGL(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / h, 0.01, 1000.0);
}

void GLWidget::mousePressEvent(QMouseEvent* event)
{
	int x = event->x();
	int y = event->y();
	float width = 300;
	float height = 200;

	dx = x - width / 2;
	dy = height / 2 - y;
	dz = -(height / 2) / tan(3.14 / 4 * 0.5);
	update();
}