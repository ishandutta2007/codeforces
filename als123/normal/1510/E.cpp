#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;
const int N=4000;
const double eps=1e-6;
int n,n2;
double x,y;
int X,Y;
int lim;
bool check (int t)
{
	X=(int)(t*x+0.5);Y=(int)(t*y*2+n/6.0+0.5);
	if (abs(X-x*t)>eps) return false;
	if (abs(Y-t*y*2-n/6.0)>eps) return false;
	return true;
}
int ans[N];
struct qq
{
	int sum,X,Y;
}t[N];int nn;
struct qt
{
	int c,d,e,h;
	qt () {}
	qt (int _c,int _d,int _e,int _h)	{c=_c;d=_d;e=_e;h=_h;}
};
bool operator < (qt x,qt y)
{
	if (x.c!=y.c) return x.c<y.c;
	if (x.d!=y.d) return x.d<y.d;
	if (x.e!=y.e) return x.e<y.e;
	return x.h<y.h;
}
map<qt,int> mp;
void solve1 (int now,int a,int b,int c,int d,int e,int tmp)
{
	if (now>=n2) 
	{
		//printf("YES:%d %d %d %d\n",a-b,c,d,e);
		mp[qt(c,d,e,a-b)]=tmp;
		return ;
	}
	int h;
	now++;
	if (b+1<=a)
	{
		h=a-b-1;
		solve1(now,a,b+1,now*h+c,d+h*h,e+h,tmp);
	}
	if (a<n/2)
	{
		h=a+1-b;
		solve1(now,a+1,b,now*h+c,d+h*h,e+h,tmp|(1<<now-1));
	}
}
void print (int now,int now1)
{
	for (int u=0;u<n2;u++)
	{
		if ((now&(1<<u))!=0) printf("(");
		else printf(")");
	}
	for (int u=0;u<n-n2;u++)
	{
		if ((now1&(1<<u))!=0) printf("(");
		else printf(")");
	}
	exit(0);
}
void check1 (int h,int c,int d,int e,int tmp)
{
	//printf("%d\n",h);
	
	for (int u=1;u<=nn;u++)
	{
		int e1=t[u].sum-e;
		int d1=t[u].Y-d;
		int c1=t[u].X-c;
		if (mp[qt(c1,d1,e1,h)]!=0)
		{
			print(mp[qt(c1,d1,e1,h)],tmp);
			exit(0);
		}
	}
}
void solve2 (int now,int a,int b,int c,int d,int e,int tmp)
{
	if (now<=n2+1)	{check1(a-b-1,c,d,e,tmp|(1<<(now-n2-1)));check1(a-b+1,c,d,e,tmp);return ;}
	int h;
	now--;
	if (b+1<=a)
	{
		h=a-b-1;
		solve2(now,a,b+1,now*h+c,d+h*h,e+h,tmp|(1<<(now-n2)));
	}
	if (a<n/2)
	{
		h=a+1-b;
		solve2(now,a+1,b,now*h+c,d+h*h,e+h,tmp);
	}
}
int main()
{
	scanf("%d%lf%lf",&n,&x,&y);n2=max(n-14,n/2);
	for (int u=(1+n)*n;u>=n/2;u--)
	{
		if (!check(u)) continue;
		t[++nn].sum=u;
		t[nn].X=X;t[nn].Y=Y;
	}
	solve1(0,0,0,0,0,0,0);
	//printf("YES!\n");
	solve2(n,0,0,0,0,0,0);
	return 0;
}