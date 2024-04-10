#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
inline void write(int x)
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
	putchar('\n');
}
struct da
{
	int v;
	char c;
	bool operator==(const da &a)const
	{
		return v==a.v&&c==a.c;
	}
	bool operator!=(const da &a)const
	{
		return !(v==a.v&&c==a.c);
	}
}a[N],b[N];
int ne[N],n,m,x,ans,l,j;
char c[10];
signed main()
{
	scanf("%d%d",&n,&m);
	l=0;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%s",&x,c);
		if (c[1]==a[l].c)
			a[l].v+=x;
		else
		{
			a[++l].v=x;
			a[l].c=c[1];
		}
	}
	n=l;
	l=0;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%s",&x,c);
		if (c[1]==b[l].c)
			b[l].v+=x;
		else
		{
			b[++l].v=x;
			b[l].c=c[1];
		}
	}
	m=l;
	if (m==1)
	{
		for (int i=1;i<=n;++i)
			if (a[i].c==b[1].c)
				if (a[i].v>=b[1].v)
					ans+=a[i].v-b[1].v+1;
		write(ans);
	}
	if (m==2)
	{
		for (int i=1;i<n;++i)
			if (a[i].c==b[1].c&&a[i+1].c==b[2].c&&a[i].v>=b[1].v&&a[i+1].v>=b[2].v)
				++ans;
		write(ans);
	}
	if (m>=3)
	{
		for (int i=1;i<=m;++i)
			b[i-1]=b[i];
		m-=2;
		j=0;
		for (int i=2;i<=m;++i)
		{
			while (j&&b[i]!=b[j+1])
				j=ne[j];
			if (b[i]==b[j+1])
				++j;
			ne[i]=j;
		}
		j=0;
		for (int i=2;i<n;++i)
		{
			while (j&&a[i]!=b[j+1])
				j=ne[j];
			if (a[i]==b[j+1])
				++j;
			if (j==m)
			{
				if (a[i+1].c==b[m+1].c&&a[i+1].v>=b[m+1].v&&a[i-m].c==b[0].c&&a[i-m].v>=b[0].v)
					++ans;
				j=ne[j];
			}
		}
		write(ans);
	}
	return 0;
}