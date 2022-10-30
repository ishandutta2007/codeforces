#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;
const int maxn = 1000005;

struct node {
	double x,y;
	void read()
	{
		int _x,_y;scanf("%d %d",&_x,&_y);x=_x;y=_y;
	}
}p[maxn],a,b,o;

double ans=1e50,sum;int n;
double ma=1e50,mb=1e50;
double dis(node &a,node &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("bottles.in","r",stdin);
		freopen("bottles.out","w",stdout);
	#endif
	a.read();b.read();o.read();scanf("%d",&n);
	for (int i=1;i<=n;i++) p[i].read();
	for (int i=1;i<=n;i++) {
		double d=dis(o,p[i]);sum+=2*d;
		double ad=dis(a,p[i]),bd=dis(b,p[i]);
		ans=min(ans,ma+bd-d);
		ans=min(ans,mb+ad-d);
		ma=min(ma,ad-d);mb=min(mb,bd-d);
	}
	ans=min(ans,ma);ans=min(ans,mb);
	printf("%.10lf",ans+sum);
	return 0;
}