#include<GL/glut.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

float x1,y1,x2,y2;

void display()
{
  float x,y,dx,dy,e,i;
  dx=x2-x1;
  dy=y2-y1;
  e=2*dy-dx;
  x=x1;
  y=y1;
  
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  glBegin(GL_POINTS);
  glVertex2i(x,y);
  
  
  for(i=0;i<dx;i++)
  {
    if(e>0)
    {
    y=y+1;
    e=e-2*dx;
    }
  
  x=x+1;
  e=e+2*dy;
  
  
  glBegin(GL_POINTS);
  glVertex2i(x,y);  
  }
  

glEnd();
glFlush();
}

void init()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-100,100,-100,100);
  glPointSize(1.0);
}

int main(int argc,char**argv)
{
  cout<<"Enter value of x1:";
  cin>>x1;
  cout<<"ENter value of y1:";
  cin>>y1;
  cout<<"Enter value of x2:";
  cin>>x2;
  cout<<"Enter value of y2:";
  cin>>y2;
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(500,500);
  glutCreateWindow("Bresenhams Line Algo.");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
  
}

