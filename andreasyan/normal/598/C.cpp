#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
struct ban
{
	long double x,y;
	long double xh;
	int i;
};
const int N=100003,INF=999999999;
bool operator<(const ban& a,const ban& b)
{
	return a.xh<b.xh;
}

int n,m;
ban a[N];
long double ans=INF;
int ans1,ans2;
int main()
{
	int i,j,k;
	cin>>n;
	for(i=0;i<n;++i)
	{
		a[i].i=i+1;
		cin>>a[i].x>>a[i].y;
		if(a[i].x==0 && a[i].y>0)
		{
			a[i].xh=acos(-1.0)/2;
			continue;
		}
		if(a[i].x==0 && a[i].y<0)
		{
			a[i].xh=acos(-1.0)*1.5;
			continue;
		}
		if(a[i].y==0 && a[i].x<0)
		{
			a[i].xh=acos(-1.0);
			continue;
		}
		if(a[i].y==0 && a[i].x>0)
		{
			continue;
		}
		if(a[i].x>=0 && a[i].y>=0)
		{
			a[i].xh=atan(a[i].y/a[i].x+0.0);
			continue;
		}
		if(a[i].x<=0 && a[i].y>=0)
		{
			a[i].xh=acos(-1.0)-atan(a[i].y/abs(a[i].x)+0.0);
			continue;
		}
		if(a[i].x<=0 && a[i].y<=0)
		{
			a[i].xh=acos(-1.0)+atan(abs(a[i].y)/abs(a[i].x)+0.0);
			continue;
		}
		if(a[i].x>=0 && a[i].y<=0)
		{
			a[i].xh=acos(-1.0)*2-atan(abs(a[i].y)/a[i].x+0.0);
		}
	}
	sort(a,a+n);
	for(i=1;i<n;++i)
	{
		if(min(a[i].xh-a[i-1].xh,acos(-1.0)*2-(a[i].xh-a[i-1].xh))<ans)
		{
			ans=min(a[i].xh-a[i-1].xh,acos(-1.0)*2-(a[i].xh-a[i-1].xh));
			ans1=a[i].i;
			ans2=a[i-1].i;
		}
	}
	if(min(a[n-1].xh-a[0].xh,acos(-1.0)*2-(a[n-1].xh-a[0].xh))<ans)
	{
		ans=min(a[n-1].xh-a[0].xh,acos(-1.0)*2-(a[n-1].xh-a[0].xh));
		ans1=a[0].i;
		ans2=a[n-1].i;
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}