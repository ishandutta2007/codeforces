#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=200005;
int n,q;
int a[N];
LL f[N];
int lb (int x)	{return x&(-x);}
void change (int x,int y)	{while (x<=n){f[x]=f[x]+y;x+=lb(x);}}
LL get (int x)	{LL lalal=0;while (x>0)	{lalal=lalal+f[x];x-=lb(x);}return lalal;}
void solve ()
{
	int now=1;
	LL now1=get(1);
	if (now1==0)	{printf("1\n");return ;}
	while (now<=n)
	{
		int l=now+1,r=n,lalal=-1;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			LL x=get(mid);
			if (x>=now1*2)	{lalal=mid;r=mid-1;}
			else l=mid+1;
		}
		if (lalal==-1) break;
		now=lalal;now1=get(lalal);
		if (now1==get(lalal-1)*2)
		{
			printf("%d\n",lalal);
			return ;
		}
	}
	printf("-1\n");
}
int read ()
{
	char ch=getchar();int x=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9')	{x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	n=read();q=read();
	for (int u=1;u<=n;u++)	
	{
		a[u]=read();
		change(u,a[u]);
	}
	for (int u=1;u<=q;u++)
	{
		int x,p;
		p=read();x=read();
		change(p,x-a[p]);a[p]=x;
		solve();
	}
	return 0;
}