#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=1000005;

int n,f[N],s[N],a[N],last[N],cnt,val[N];
struct edge{int to,next;}e[N*2];
bool vis[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

bool cmp(int x,int y)
{
	return val[x]<val[y];
}

int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) val[i]=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	for (int i=1;i<=n;i++) f[i]=i,s[i]=1,a[i]=i;
	sort(a+1,a+n+1,cmp);
	LL ans=0;
	for (int i=n;i>=1;i--)
	{
		int x=a[i];vis[x]=1;
		for (int j=last[x];j;j=e[j].next)
			if (vis[e[j].to])
			{
				int p=find(x),q=find(e[j].to);
				ans-=(LL)s[p]*s[q]*val[x];
				s[q]+=s[p];f[p]=q;
			}
	}
	for (int i=1;i<=n;i++) f[i]=i,s[i]=1,vis[i]=0;
	for (int i=1;i<=n;i++)
	{
		int x=a[i];vis[x]=1;
		for (int j=last[x];j;j=e[j].next)
			if (vis[e[j].to])
			{
				int p=find(x),q=find(e[j].to);
				ans+=(LL)s[p]*s[q]*val[x];
				s[q]+=s[p];f[p]=q;
			}
	}
	printf("%I64d",ans);
	return 0;
}