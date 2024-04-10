#include<bits/stdc++.h>
#define eps 1e-12
using namespace std;
int n,Eg=0,Cn;
typedef pair<double,double> P;
set<P> S;
set<P> s[3];
struct aaa
{
	double x,y,r;
	int rt;
}c[3];
inline void getroot(int x)
{
	if(x==c[x].rt)return ;
	getroot(c[x].rt),c[x].rt=c[c[x].rt].rt;
}
inline void work(int a,int b)
{
	double A=2*(c[b].x-c[a].x),B=2*(c[b].y-c[a].y),C=c[a].r*c[a].r-c[b].r*c[b].r+c[b].x*c[b].x-c[a].x*c[a].x+c[b].y*c[b].y-c[a].y*c[a].y,D=A*A+B*B,E=2*(-A*C+A*B*c[a].y-B*B*c[a].x),F=C*C-2*B*c[a].y*C+B*B*c[a].x*c[a].x+B*B*c[a].y*c[a].y-B*B*c[a].r*c[a].r,delta=E*E-4*D*F,xa,ya,xb,yb,ta,tb;
	if(delta<0 || !D)return ;xa=(-E+sqrt(delta))/2/D,xb=(-E-sqrt(delta))/2/D,ta=c[a].r*c[a].r-(xa-c[a].x)*(xa-c[a].x),tb=c[a].r*c[a].r-(xb-c[a].x)*(xb-c[a].x);
	if(ta>=0)
	{
		ya=c[a].y+sqrt(ta);if(fabs((xa-c[b].x)*(xa-c[b].x)+(ya-c[b].y)*(ya-c[b].y)-c[b].r*c[b].r)>eps)ya=c[a].y-sqrt(ta);
		S.insert(P(xa,ya)),s[a].insert(P(xa,ya)),s[b].insert(P(xa,ya)),getroot(a),getroot(b);if(c[a].rt!=c[b].rt)--Cn,c[c[a].rt].rt=c[b].rt;
	}
	if(tb>=0)
	{
		yb=c[a].y-sqrt(tb);if(fabs((xb-c[b].x)*(xb-c[b].x)+(yb-c[b].y)*(yb-c[b].y)-c[b].r*c[b].r)>eps)yb=c[a].y+sqrt(tb);
		if(fabs(xb-xa)+fabs(yb-ya)>eps)S.insert(P(xb,yb)),s[a].insert(P(xb,yb)),s[b].insert(P(xb,yb));
	}
}
int main()
{
	scanf("%d",&n),Cn=n;
	for(int i=0;i<n;++i)
	{
		scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r),c[i].rt=i;
		for(int j=0;j<i;++j)work(i,j);
	}
	for(int i=0;i<n;++i)Eg+=s[i].size();
	printf("%d",Cn+1-S.size()+Eg);
	return 0;
}