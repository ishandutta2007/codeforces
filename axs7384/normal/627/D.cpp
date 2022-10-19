#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int l,r,la[N],pr[N*2],to[N*2],f[N],g[N],ans,n,x,a[N],cnt,y,sz[N],m,fa[N],sum,mid;
inline void read(int &x)
{
	char c=getchar();
	x=0;
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
	static int a[10];
	a[0]=0;
	if (x==0)
		putchar('0');
	while (x)
	{
		a[++a[0]]=x%10;
		x/=10;
	}
	while (a[0])
		putchar(a[a[0]--]+'0');
}
inline void add(int x,int y)
{
	to[++cnt]=y;
	pr[cnt]=la[x];
	la[x]=cnt;
}
void dfs(int x)
{
	sz[x]=1;
	for (int i=la[x];i;i=pr[i])
		if (to[i]!=fa[x])
		{
			fa[to[i]]=x;
			dfs(to[i]);
			sz[x]+=sz[to[i]];
		}
}
void Dfs(int x)
{
	int mx0=0,mx1=0,mx2=0,pd=f[x];
	for (int i=la[x];i;i=pr[i])
		if (to[i]!=fa[x])
		{
			Dfs(to[i]);
			f[x]+=f[to[i]];
			if (sz[to[i]]==g[to[i]])
				mx0+=g[to[i]];
			else
			{
				if (g[to[i]]>mx1)
				{
					mx2=mx1;
					mx1=g[to[i]];
				}
				else
				{
					if (g[to[i]]>mx2)
						mx2=g[to[i]];
				}
			}
		}	
	if (pd)
		g[x]=mx1+mx0+1;
	if (n-sz[x]==sum-f[x])
		mx0+=n-sz[x];//cout<<mid<<' '<<x<<' '<<sz[x]<<' '<<sum<<' '<<f[x]<<' '<<mx0<<' '<<mx1<<' '<<mx2<<'\n';
	if (pd)
	{
		/*if (mid==683826)
			cout<<x<<' '<<g[x]<<'
			 '<<sz[x]<<' '<<mx0<<' '<<mx1<<' '<<mx2<<' '<<n-sz[x]<<' '<<sum-f[x]<<'\n';	*/
		ans=max(ans,mx1+mx0+mx2+1);
	}

}
int main()
{
	read(n);
	read(m);
	for (int i=1;i<=n;++i)
		read(a[i]);
	for (int i=1;i<n;++i)
	{
		read(x);
		read(y);
		add(x,y);
		add(y,x);
	}
	dfs(1);
	l=1;
	r=1000000;
	while (l<=r)
	{
		mid=(l+r)/2;
		sum=0;
		for (int i=1;i<=n;++i)
		{
			f[i]=a[i]>=mid;
			sum+=f[i];
		}
		memset(g,0,sizeof(g));
		ans=0;
		Dfs(1);
		if (ans>=m)
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<r;
}