#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

typedef long long LL;

const int N=100005;
const int MOD=1000000007;

int n,q,k,m,r,cnt,c1,last[N],ls1[N],fa[N][18],dep[N],dfn[N],tim,stack[N],a[N],h[N],f[N][305],tot;
struct edge{int to,next;}e[N*2],e1[N*2];
std::vector<int> rub;
bool tag[N];

void addedge(int u,int v)
{
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}

void add(int u,int v)
{
	e1[++c1].to=v;e1[c1].next=ls1[u];ls1[u]=c1;
	e1[++c1].to=u;e1[c1].next=ls1[v];ls1[v]=c1;
}

int get_lca(int x,int y)
{
	if (dep[x]<dep[y]) std::swap(x,y);
	for (int i=16;i>=0;i--)
		if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=16;i>=0;i--)
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

bool cmp(int x,int y) {return dfn[x]<dfn[y];}

void build()
{
    std::sort(a+1,a+k+1,cmp);
    int top=0;stack[++top]=1;rub.push_back(1);
    for (int i=1;i<=k;i++)
    {
        if (a[i]==stack[top]) continue;
        int lca=get_lca(a[i],stack[top]);
        if (lca==stack[top]) {stack[++top]=a[i];rub.push_back(a[i]);continue;}
        while (dep[stack[top-1]]>=dep[lca]) add(stack[top-1],stack[top]),top--;
        if (dep[stack[top]]>dep[lca]) add(lca,stack[top]),top--;
        if (stack[top]!=lca) stack[++top]=lca,rub.push_back(lca);
        stack[++top]=a[i];rub.push_back(a[i]);
    }
    while (top>1) add(stack[top-1],stack[top]),top--;
}

void dfs(int x)
{
	dep[x]=dep[fa[x][0]]+1;dfn[x]=++tim;
	for (int i=1;i<=16;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=last[x];i;i=e[i].next)
	{
		if (e[i].to==fa[x][0]) continue;
		fa[e[i].to][0]=x;
		dfs(e[i].to);
	}
}

void dfs1(int x,int fa,int s)
{
	if (tag[x]) h[++tot]=s,s++;
	for (int i=ls1[x];i;i=e1[i].next)
		if (e1[i].to!=fa) dfs1(e1[i].to,x,s);
}

void clear()
{
	c1=0;
	for (int i=0;i<rub.size();i++)
	{
		int x=rub[i];
		tag[x]=0;
		ls1[x]=0;
	}
	rub.clear();
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	dfs(1);
	while (q--)
	{
		scanf("%d%d%d",&k,&m,&r);
		for (int i=1;i<=k;i++) scanf("%d",&a[i]),tag[a[i]]=1;
		if (!tag[r]) a[++k]=r;
		build();
		tot=0;
		dfs1(r,0,0);
		f[1][1]=1;
		for (int i=2;i<=tot;i++)
			for (int j=1;j<=std::min(i,m);j++)
			{
				f[i][j]=0;
				if (j>h[i]) (f[i][j]+=(LL)f[i-1][j]*(j-h[i])%MOD)%=MOD;
				if (j) (f[i][j]+=f[i-1][j-1])%=MOD;
			}
		int ans=0;
		for (int i=1;i<=m;i++) (ans+=f[tot][i])%=MOD;
		printf("%d\n",ans);
		clear();
	}
	return 0;
}