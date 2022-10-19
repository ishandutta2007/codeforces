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
inline void write(int x)
{
	if (x==0)
		putchar('0');
	int a[10];
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
	putchar('\n');
}
const int N=505,M=10005;
int f[M][N],g[M][N],h[N],x[M],y[M],l,r,ans,n,m,p,q,Q;
inline int gf1(int x,int y)
{
	return y==f[x][y]?y:f[x][y]=gf1(x,f[x][y]);
}
inline int gf2(int x,int y)
{
	return y==g[x][y]?y:g[x][y]=gf2(x,g[x][y]);
}
inline int gf(int x)
{
	return x==h[x]?x:h[x]=gf(h[x]);
}
int main()
{
	read(n);
	read(m);
	for (int i=1;i<=m;++i)
	{
		read(x[i]);
		read(y[i]);
	}
	for (int i=1;i<=n;++i)
		f[0][i]=i;
	for (int i=1;i<=m;++i)
	{
		for (int j=1;j<=n;++j)
			f[i][j]=f[i-1][j];
		p=gf1(i,x[i]);
		q=gf1(i,y[i]);
		if (p!=q)
			f[i][p]=q;
	}
	for (int i=1;i<=n;++i)
		g[m+1][i]=i;
	for (int i=m;i;--i)
	{
		for (int j=1;j<=n;++j)
			g[i][j]=g[i+1][j];
		p=gf2(i,x[i]);
		q=gf2(i,y[i]);
		if (p!=q)
			g[i][p]=q;
	}
	read(Q);
	while (Q--)
	{
		read(l);
		read(r);
		--l;
		++r;
		for (int i=1;i<=n;++i)
			h[i]=f[l][i];
		for (int i=1;i<=n;++i)
		{
			p=gf(i);
			q=gf(g[r][i]);
			if (p!=q)
				h[p]=q;
		}
		ans=0;
		for (int i=1;i<=n;++i)
		{
			h[i]=gf(i);
			if (h[i]==i)
				++ans;
		}
		write(ans);
	}
	return 0;
}