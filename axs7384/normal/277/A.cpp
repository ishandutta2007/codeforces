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
}
const int N=205;
int a[N][N],f[N],n,m,x,y,ans,kkk;
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
	read(n);
	read(m);
	for (int i=1;i<=n;++i)
	{
		read(x);
		if (x)
			kkk=1;
		for (int j=1;j<=x;++j)
		{
			read(y);
			a[y][++a[y][0]]=i;
		}
	}
	if (!kkk)
	{
		write(n);
		return 0;
	}
	for (int i=1;i<=n;++i)
		f[i]=i;
	for (int i=0;i<=m;++i)
		for (int j=1;j<a[i][0];++j)
			for (int k=j+1;k<=a[i][0];++k)
				hb(a[i][j],a[i][k]);
	for (int i=1;i<=n;++i)
	{
		f[i]=gf(i);
		if (f[i]==i)
			++ans;
	}
	write(ans-1);
	return 0;
}