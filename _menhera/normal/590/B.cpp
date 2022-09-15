#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std; 
double solveeq(double a, double b, double c)
{
	return ( -b + sqrt( b*b - 4*a*c ) ) / (2*a);
}
int main()
{
	int xx,yy,x,y;
	scanf("%d%d%d%d",&xx,&yy,&x,&y);
	x-=xx; y-=yy;
	if(x==0 && y==0)
	{
		puts("0");
		return 0;
	}
	int v, t;
	scanf("%d%d",&v,&t);
	int vx,vy,wx,wy;
	scanf("%d%d%d%d",&vx,&vy,&wx,&wy);
	//assume reachable within t;
	double est = solveeq(x*x+y*y, -2*(x*vx+y*vy), vx*vx+vy*vy-v*v);
	double r = 1/est;
	if(r<=(double)t)
	{
		printf("%.15f\n",r);
		return 0;
	}
	int driftx = (vx - wx) * t;
	int drifty = (vy - wy) * t;
	x-=driftx, y-=drifty;
	double dest = solveeq((double)x*x+(double)y*y, -2*((double)x*wx+(double)y*wy), wx*wx+wy*wy-v*v);
	printf("%.15f\n",1/dest);
	return 0;
}