#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

int n;
double x1, y1, x2, y2;
double rx[N], ry[N], vx[N], vy[N];
double minxt[N], maxxt[N], minyt[N], maxyt[N];

void workx(int i, double x, double v)
{
	minxt[i]=-1e15;
	maxxt[i]=1e15;
	if(v>0)
	{
		double t=(x1-x)/v;
		t=max(0.0l, t);
		minxt[i]=t;
		t=(x2-x)/v;
		if(t<0)
		{
			cout<<"-1";
			exit(0);
		}
		maxxt[i]=t;
	}
	else if(v<0)
	{
		double t=(x2-x)/v;
		t=max(0.0l, t);
		minxt[i]=t;
		t=(x1-x)/v;
		if(t<0)
		{
			cout<<"-1";
			exit(0);
		}
		maxxt[i]=t;
	}
	else
	{
		if(x<=x1 || x>=x2)
		{
			cout<<"-1";
			exit(0);
		}
	}
}

void worky(int i, double y, double v)
{
	minyt[i]=-1e15;
	maxyt[i]=1e15;
	if(v>0)
	{
		double t=(y1-y)/v;
		t=max(0.0l, t);
		minyt[i]=t;
		t=(y2-y)/v;
		if(t<0)
		{
			cout<<"-1";
			exit(0);
		}
		maxyt[i]=t;
	}
	else if(v<0)
	{
		double t=(y2-y)/v;
		t=max(0.0l, t);
		minyt[i]=t;
		t=(y1-y)/v;
		if(t<0)
		{
			cout<<"-1";
			exit(0);
		}
		maxyt[i]=t;
	}
	else
	{
		if(y<=y1 || y>=y2)
		{
			cout<<"-1";
			exit(0);
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>x1>>y1>>x2>>y2;
	for(int i=1;i<=n;i++)
		cin>>rx[i]>>ry[i]>>vx[i]>>vy[i];
	for(int i=1;i<=n;i++)
	{
		workx(i, rx[i], vx[i]);
		worky(i, ry[i], vy[i]);
	}	
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans, max(minxt[i], minyt[i]));
	}
	for(int i=1;i<=n;i++)
	{
		if(ans>=maxyt[i] || ans>=maxxt[i])
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;   
}