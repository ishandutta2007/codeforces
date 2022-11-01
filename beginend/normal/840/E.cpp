#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAX(x,y) x=max(x,y)
using namespace std;

const int N=50005;
const int inf=1000000000;
const int B=8;

int n,bin[10],cnt,last[N],anc[N],fa[N],ans[N][256],dp[256][10],dep[N],a[N],q;
struct edge{int to,next;}e[N*2];

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

void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;
	for (int i=last[x];i;i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to);
	if (dep[x]<bin[B]) return;
	anc[x]=x;
	for (int i=0;i<bin[B];i++) dp[i][0]=-inf,anc[x]=fa[anc[x]];
	for (int i=0,y=x;i<bin[B];i++,y=fa[y]) MAX(dp[a[y]>>B][0],((dep[x]-dep[y])^a[y])&(bin[B]-1));
	for (int j=1;j<=B;j++)
		for (int i=0;i<bin[B];i++)
			dp[i][j]=max(dp[i][j-1],dp[i^bin[j-1]][j-1]+bin[j-1]*bin[B]);
	for (int i=0;i<bin[B];i++) ans[x][i]=dp[i][B];
}

int main()
{
	//freopen("a.in","r",stdin);
	bin[0]=1;
	for (int i=1;i<=8;i++) bin[i]=bin[i-1]*2;
	n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		addedge(x,y);
	}
	dfs(1);
	while (q--)
	{
		int u=read(),v=read(),x=v,mx=0,d=0;
		while (dep[anc[x]]>=dep[u]) MAX(mx,ans[x][d]),d++,x=anc[x];
		while (dep[x]>=dep[u]) MAX(mx,(dep[v]-dep[x])^a[x]),x=fa[x];
		printf("%d\n",mx);
	}
	return 0;
}