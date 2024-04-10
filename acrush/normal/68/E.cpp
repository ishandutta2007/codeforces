#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

const double eps=1e-9;

struct Point
{
	double x,y;
	Point(double _x=0,double _y=0) { x=_x; y=_y; }
};

int result;
Point p[4][3],e[4][3],pts[12];
double dst[12][12];
int permutation[4];

void rotate(Point &p,double d)
{
	double cosd=cos(d);
	double sind=sin(d);
	double x=p.x*cosd-p.y*sind;
	double y=p.x*sind+p.y*cosd;
	p.x=x;
	p.y=y;
}
double ppDistance(const Point &a,const Point &b)
{
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}
double sqr(double x)
{
	return x*x;
}
int getIntersect(double X1,double Y1,double R1,double X2,double Y2,double R2,Point &P,Point &Q)
{
	double dst=ppDistance(Point(X1,Y1),Point(X2,Y2));
	if (dst>R1+R2+eps || dst<fabs(R1-R2)-eps) return 0;
	if (dst<=eps) return 0;
	//(x-X1)^2+(y-Y1)^2=sqr(R1)=x^2-2*X1*x+X1^2+y^2-2*Y1*y+Y1^2 (1)
	//(x-X2)^2+(y-Y2)^2=sqr(R2)=x^2-2*X2*x+X2^2+y^2-2*Y2*y+Y2^2 (2)
	//(2)-(1):  sqr(R2)-sqr(R1)=2*(X1-X2)*x+2*(Y1-Y2)*y+sqr(X2)-sqr(X1)+sqr(Y2)-sqr(Y1)
	//	 :  (X1-X2)*x+(Y1-Y2)*y-(sqr(X1)-sqr(X2)+sqr(Y1)-sqr(Y2)-sqr(R1)+sqr(R2))/2.0;
	double a=X1-X2;
	double b=Y1-Y2;
	double c=-(a*(X1+X2)+b*(Y1+Y2)-sqr(R1)+sqr(R2))/2.0;
	double CX=X1,CY=Y1;
	//ax+by+c=0
	//(+by+c+aCX)^2+(ay-aCY)^2=(aR)^2
	double x1,y1,x2,y2;
	if (fabs(a)>fabs(b))
	{
		double A=sqr(a)+sqr(b);
		double B=2.0*b*(c+a*CX)-2.0*sqr(a)*CY;
		double C=sqr(c+a*CX)+sqr(a)*(sqr(CY)-sqr(R1));
		double delta=sqr(B)-4*A*C;
		if (delta<-eps) return 0;
		if (delta<0) delta=0;
		delta=sqrt(delta);
		y1=(-B+delta)/(2*A);x1=(-c-b*y1)/a;
		y2=(-B-delta)/(2*A);x2=(-c-b*y2)/a;
		P.x=x1;P.y=y1;
		Q.x=x2;Q.y=y2;
	}
	else
	{
		swap(a,b);swap(CX,CY);
		double A=sqr(a)+sqr(b);
		double B=2.0*b*(c+a*CX)-2.0*sqr(a)*CY;
		double C=sqr(c+a*CX)+sqr(a)*(sqr(CY)-sqr(R1));
		double delta=sqr(B)-4*A*C;
		if (delta<-eps) return 0;
		if (delta<0) delta=0;
		delta=sqrt(delta);
		y1=(-B+delta)/(2*A);x1=(-c-b*y1)/a;
		y2=(-B-delta)/(2*A);x2=(-c-b*y2)/a;
		swap(x1,y1);swap(x2,y2);
		swap(a,b);swap(CX,CY);
		P.x=x1;P.y=y1;
		Q.x=x2;Q.y=y2;
	}
	return 2;
}
void DFS(int d)
{
	if (d==3)
	{
		int m=0;
		for (int i=0;i<d;i++) for (int j=0;j<3;j++)
		{
			bool is_exists=false;
			for (int k=0;!is_exists && k<m;k++) if (fabs(e[i][j].x-pts[k].x)<=eps && fabs(e[i][j].y-pts[k].y)<=eps) is_exists=true;
			if (!is_exists) pts[m++]=e[i][j];
		}
		if (m>=result) return;
		if (m+2<result) 
		{
			result=m+2;
			//printf("res = %d\n",result);
		}
		double l1=ppDistance(p[d][0],p[d][1]);
		double l2=ppDistance(p[d][0],p[d][2]);
		double l3=ppDistance(p[d][1],p[d][2]);
		for (int i=0;i<m;i++) for (int j=0;j<m;j++) dst[i][j]=(i==j)?0:((i>j)?dst[j][i]:ppDistance(pts[i],pts[j]));
		for (int i=0;i<m;i++) for (int j=i+1;j<m;j++) if (fabs(dst[i][j]-l1)<=eps) for (int k=0;k<m;k++) 
			if (fabs(dst[i][k]-l2)<=eps && fabs(dst[j][k]-l3)<=eps || fabs(dst[i][k]-l3)<=eps && fabs(dst[j][k]-l2)<=eps)
			{
				result=m;
				//printf("res = %d\n",result);
				return;
			}
		if (m+1>=result) return;
		for (int i=0;i<m;i++) for (int j=i+1;j<m;j++) if (fabs(dst[i][j]-l1)<=eps || fabs(dst[i][j]-l2)<=eps || fabs(dst[i][j]-l3)<=eps)
		{
			result=m+1;
			//printf("res = %d\n",result);
			return;
		}
		return;
	}
	bool dup[12];
	memset(dup,false,sizeof(dup));
	for (int i=0;i<d*3;i++) for (int j=i+1;j<d*3;j++) 
	{
		Point p1=e[i/3][i%3];
		Point p2=e[j/3][j%3];
		if (fabs(p1.x-p2.x)<=eps && fabs(p1.y-p2.y)<=eps) dup[j]=true;
	}
	for (int i=0;i<d*3;i++) if (!dup[i]) for (int j=0;j<d*3;j++) if (!dup[j]) 
	{
		if (i==j) continue;
		Point p1=e[i/3][i%3];
		Point p2=e[j/3][j%3];
		if (fabs(p1.x-p2.x)<=eps && fabs(p1.y-p2.y)<=eps) continue;
		Point g1=Point(p[d][1].x-p[d][0].x,p[d][1].y-p[d][0].y);
		Point g2=Point(p[d][2].x-p[d][0].x,p[d][2].y-p[d][0].y);
		double rot=atan2(p2.y-p1.y,p2.x-p1.x)-atan2(g1.y,g1.x);
		rotate(g1,rot);
		rotate(g2,rot);
		e[d][0]=p1;
		e[d][1]=Point(p1.x+g1.x,p1.y+g1.y);
		e[d][2]=Point(p1.x+g2.x,p1.y+g2.y);
		DFS(d+1);
	}
	if (d==1 && permutation[1]<permutation[2])
		for (int i=0;i<d*3;i++) if (!dup[i]) for (int j=0;j<d*3;j++) if (!dup[j])
		{
			if (i==j) continue;
			Point p1=e[i/3][i%3];
			Point p2=e[j/3][j%3];
			if (fabs(p1.x-p2.x)<=eps && fabs(p1.y-p2.y)<=eps) continue;
			double l1=ppDistance(p[d][0],p[d][1]);
			double l2=ppDistance(p[d+1][0],p[d+1][1]);
			Point h[2];
			int c=getIntersect(p1.x,p1.y,l1,p2.x,p2.y,l2,h[0],h[1]);
			for (int k=0;k<c;k++)
			{
				Point g1=Point(p[d][1].x-p[d][0].x,p[d][1].y-p[d][0].y);
				Point g2=Point(p[d][2].x-p[d][0].x,p[d][2].y-p[d][0].y);
				double rot=atan2(h[k].y-p1.y,h[k].x-p1.x)-atan2(g1.y,g1.x);
				rotate(g1,rot);
				rotate(g2,rot);
				e[d][0]=p1;
				e[d][1]=Point(p1.x+g1.x,p1.y+g1.y);
				e[d][2]=Point(p1.x+g2.x,p1.y+g2.y);
				DFS(d+1);
			}
		}
	if (d==2 && permutation[2]<permutation[3])
	{
		int m=0;
		for (int i=0;i<d;i++) for (int j=0;j<3;j++)
		{
			bool is_exists=false;
			for (int k=0;!is_exists && k<m;k++) if (fabs(e[i][j].x-pts[k].x)<=eps && fabs(e[i][j].y-pts[k].y)<=eps) is_exists=true;
			if (!is_exists) pts[m++]=e[i][j];
		}
		for (int i=0;i<m;i++) for (int j=0;j<m;j++) if (i!=j) for (int k=0;k<3;k++)
		{
			Point p1=pts[i];
			Point p2=pts[j];
			if (fabs(p1.x-p2.x)<=eps && fabs(p1.y-p2.y)<=eps) continue;
			double l1=ppDistance(p[d][0],p[d][1]);
			double l2=ppDistance(p[d+1][k],p[d+1][(k+1)%3]);
			Point h[2];
			int c=getIntersect(p1.x,p1.y,l1,p2.x,p2.y,l2,h[0],h[1]);
			for (int u=0;u<c;u++)
			{
				Point g1=Point(p[d][1].x-p[d][0].x,p[d][1].y-p[d][0].y);
				Point g2=Point(p[d][2].x-p[d][0].x,p[d][2].y-p[d][0].y);
				double rot=atan2(h[u].y-p1.y,h[u].x-p1.x)-atan2(g1.y,g1.x);
				rotate(g1,rot);
				rotate(g2,rot);
				e[d][0]=p1;
				e[d][1]=Point(p1.x+g1.x,p1.y+g1.y);
				e[d][2]=Point(p1.x+g2.x,p1.y+g2.y);
				DFS(d+1);
			}
		}
	}
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	Point a[4][3];
	for (int i=0;i<4;i++) for (int j=0;j<3;j++)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		a[i][j]=Point(x,y);
	}
	result=12;
	for (int i=0;i<4;i++) permutation[i]=i;
	do{
		for (int mset=0;mset<(1<<3);mset+=2) for (int set=0;set<(1<<3);set+=2) for (int rot=0;rot<27;rot+=3)
		{
			for (int i=0;i<4;i++) for (int j=0;j<3;j++) p[i][j]=a[permutation[i]][j];
			for (int i=0;i<4;i++) if (mset&(1<<i)) for (int j=0;j<3;j++) p[i][j].x=-p[i][j].x;
			for (int state=rot,i=0;i<4;i++,state/=3) for (int j=0;j<state%3;j++)
			{
				Point t=p[i][0];
				p[i][0]=p[i][1];
				p[i][1]=p[i][2];
				p[i][2]=t;
			}
			for (int i=0;i<4;i++) if (set&(1<<i)) swap(p[i][1],p[i][2]);
			for (int j=0;j<3;j++) e[0][j]=p[0][j];
			DFS(1);
		}
	}while (next_permutation(permutation+1,permutation+4)!=0);
	printf("%d\n",result);
	return 0;
}