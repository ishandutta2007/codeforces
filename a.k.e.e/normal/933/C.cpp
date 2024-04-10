#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
#define pb push_back
const double eps=1e-8;

inline int dcmp(double x)
{
	if(x>eps)return 1;
	return x<-eps?-1:0;
}

int n;
struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
	bool operator ==(Point b)
		{return dcmp(x-b.x)==0 && dcmp(y-b.y)==0;} 
};
Point a[5];
double r[5];
Point in1,in2;
int getInter(Point a,double ar,Point b,double br)
{
	double A=2*(b.x-a.x),B=2*(b.y-a.y),C=a.x*a.x+a.y*a.y-b.x*b.x-b.y*b.y-ar*ar+br*br;
	int res=dcmp(fabs(A*a.x+B*a.y+C)/sqrt(A*A+B*B)-ar);
	if(res<=0)
	{
		if(dcmp(A)==0)
		{
			double t=ar*ar-(-C/B-a.y)*(-C/B-a.y);
			if(dcmp(t))t=sqrt(t);
			else t=0;
			in1.x=a.x-t;in1.y=-C/B;
			in2.x=a.x+t;in2.y=-C/B;
		}
		else
		{
			double tA=(B/A)*(B/A)+1,tB=2*(B/A*(C/A+a.x)-a.y)
				,tC=(C/A+a.x)*(C/A+a.x)+a.y*a.y-ar*ar;
			double delta=tB*tB-4*tA*tC;
			if(dcmp(delta))delta=sqrt(delta);
			else delta=0;
			in1.y=(-tB-delta)/(2*tA);in1.x=-(B*in1.y+C)/A;
			in2.y=(-tB+delta)/(2*tA);in2.x=-(B*in2.y+C)/A;
		}
		if(res<0)return 2;
		else return 1;
	}
	return 0;
}
vector<Point> pt[5];
void insert(int x,Point t)
{
	for(int i=0;i<pt[x].size();i++)
		if(t==pt[x][i])return;
	pt[x].pb(t);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%lf%lf%lf",&a[i].x,&a[i].y,&r[i]);
    if(n==1)return 0*printf("2\n");
    if(n==2)return 0*printf("%d\n",getInter(a[1],r[1],a[2],r[2])==2?4:3);
    for(int i=1;i<=3;i++)
    {
    	insert(i,Point(a[i].x-r[i],a[i].y));
    	insert(0,Point(a[i].x-r[i],a[i].y));
    }
    int add[5]={1,1,1,1,1};
    for(int i=1;i<=3;i++)
    	for(int j=i+1;j<=3;j++)
    	{
    		int t=getInter(a[i],r[i],a[j],r[j]);
    		if(t==2)
			{
				insert(i,in1);insert(i,in2);
				insert(j,in1);insert(j,in2);
				insert(0,in1);insert(0,in2);
			}
			else if(t==1)
			{
				insert(i,in1);
				insert(j,in1);
				insert(0,in1);
			}
			else add[i^j]=0;
    	}
    int t=add[1]+add[2]+add[3];
    if(t>=2)t=1;
    else if(t==1)t=2;
    else t=3;
    printf("%d\n",pt[1].size()+pt[2].size()+pt[3].size()-pt[0].size()+t+1);
    return 0;
}