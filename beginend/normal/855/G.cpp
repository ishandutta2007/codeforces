#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,size[N],dep[N],fa[N],cnt,last[N],s[N],f[N];
struct edge{int to,next;}e[N*2];
LL ans,val[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;size[x]=1;
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x]) continue;
		fa[e[i].to]=x;
		dfs(e[i].to);
		size[x]+=size[e[i].to];
		val[x]+=(LL)size[e[i].to]*size[e[i].to];
	}
	val[x]+=(LL)(n-size[x])*(n-size[x]);
	ans-=val[x];
}

LL get(int s)
{
	return (LL)s*(s-1)*(s-2);
}

void merge(int x,int y)
{
	ans-=(LL)(n-s[x])*(n-s[x])*s[x]+(LL)(n-s[y])*(n-s[y])*s[y]-val[x]*s[x]-val[y]*s[y]+get(s[x])+get(s[y])+(LL)s[x]*(s[x]-1)*(n-s[x])*2+(LL)s[y]*(s[y]-1)*(n-s[y])*2;
	f[y]=x;s[x]+=s[y];
	val[x]+=val[y]-(LL)size[y]*size[y]-(LL)(n-size[y])*(n-size[y]);
	ans+=(LL)(n-s[x])*(n-s[x])*s[x]-val[x]*s[x]+get(s[x])+(LL)s[x]*(s[x]-1)*(n-s[x])*2;
}

int main()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	ans=(LL)n*(n-1)*(n-1);
	dfs(1);
	printf("%lld\n",ans);
	for (int i=1;i<=n;i++) f[i]=i,s[i]=1;
	int q=read();
	while (q--)
	{
		int x=read(),y=read();
		x=find(x);y=find(y);
		if (dep[x]<dep[y]) std::swap(x,y);
		while (x!=y)
		{
			if (dep[x]<dep[y]) std::swap(x,y);
			merge(find(fa[x]),x);x=find(fa[x]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}