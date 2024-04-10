#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define iter iterator
inline void read(int &x)
{
	x=0;
	char c=getchar();
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
inline void write(ll x)
{
	if (x==0)
		putchar('0');
	int a[30];
	a[0]=0;
	while (x!=0)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
	{
		putchar(a[a[0]]+'0');
		--a[0];
	}
}
const int N=1000;
int f[N],n,m,x,y;
ll ans;
inline int gf(int x)
{
	return x==f[x]?x:f[x]=gf(f[x]);
}
inline void hb(int x,int y)
{
	x=gf(x);
	y=gf(y);
	if (x!=y)
		f[x]=y;
}
int main()
{
	// freopen("1.in","r",stdin);
	read(n);
	read(m);
	for (int i=1;i<=n;++i)
		f[i]=i;
	for (int i=1;i<=m;++i)
	{
		read(x);
		read(y);
		hb(x,y);
	}
	int nn=n;
	for (int i=1;i<=n;++i)
	{
		f[i]=gf(i);
		if (f[i]==i)
			--nn;
	}
	ans=1LL<<nn;
	write(ans);
	return 0;
}