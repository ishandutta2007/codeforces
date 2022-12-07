#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
int a[N],c[N];
int ans[N];
struct qq
{
	int x,y,id;
}s[N];
int n,Q;
bool cmp (qq x,qq y)	{return x.y<y.y;}
int q[N];
int st,ed,now;
double Y (int x)	{return a[x]*x-c[x];}
double X (int x)	{return -a[x];}
double get_k (int x,int y)
{
	return (double)(Y(x)-Y(y))/(double)(X(x)-X(y));
}
int calc (int xx,int x,int y)// 
{
	return c[y]-c[xx]+a[xx]*(x-y+xx);
}
void solve ()
{
	st=1;ed=0;now=1;
	for (int u=1;u<=n;u++)
	{
		while (st<=ed&&a[q[ed]]>=a[u]) ed--;
		while (st<ed&&get_k(q[ed-1],q[ed])<get_k(q[ed],u)) 	ed--;	
		q[++ed]=u;
		while (now<=Q&&s[now].y==u)// 
		{
			int l=st,r=ed,lalal;
			while (l<=r)
			{
				int mid=(l+r)>>1;
				if (mid==ed||calc(q[mid],s[now].x,s[now].y)<calc(q[mid+1],s[now].x,s[now].y)) {lalal=mid;r=mid-1;}
				else l=mid+1;
			}
			ans[s[now].id]=calc(q[lalal],s[now].x,s[now].y);
			now++;
		}
	}
}
int read()
{
	char ch=getchar();int x=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	n=read();
	for (int u=1;u<=n;u++)	{a[u]=read();c[u]=c[u-1]+a[u];}
	Q=read();
	for (int u=1;u<=Q;u++)
	{
		s[u].x=read();s[u].y=read();
		s[u].id=u;
	}
	sort(s+1,s+1+Q,cmp);
	solve();
	for (int u=1;u<=Q;u++)	printf("%d\n",ans[u]);
	return 0;
}