#include<iostream> 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200005;

int n,cnt,last[N],val[N],f[N];
struct edge{int to,next;}e[N*2];
struct data{int tot,a[25];}w[N];

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

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

void solve(int x,int fa)
{
	f[x]=gcd(f[fa],val[x]);
	w[x]=w[fa];
	for (int i=1;i<=w[x].tot;i++) w[x].a[i]=gcd(w[x].a[i],val[x]);
	if (f[x]!=f[fa]) w[x].tot++,w[x].a[w[x].tot]=f[fa];
	for (int i=last[x];i;i=e[i].next) if (e[i].to!=fa) solve(e[i].to,x);
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
	w[1].tot=1;w[1].a[1]=0;f[1]=val[1];
	for (int i=last[1];i;i=e[i].next) solve(e[i].to,1);
	for (int i=1;i<=n;i++)
	{
		int ans=f[i];
		for (int j=1;j<=w[i].tot;j++) ans=max(ans,w[i].a[j]);
		printf("%d ",ans);
	}
	return 0;
}