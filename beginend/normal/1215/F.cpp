#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

const int N=1600005;

int n,m,M,p,cnt,last[N],low[N],dfn[N],top,stack[N],bel[N],con[N],deg[N],cho[N],tim,tot,lef[N],rig[N];
struct edge{int to,next,from;}e[N*4];
std::vector<int> vec[N],bac[N];
bool ins[N];

void addedge(int u,int v)
{
	e[++cnt].from=u;e[cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
}

void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	stack[++top]=x;ins[x]=1;
	for (int i=last[x];i;i=e[i].next)
		if (!dfn[e[i].to]) tarjan(e[i].to),low[x]=std::min(low[x],low[e[i].to]);
		else if (ins[e[i].to]) low[x]=std::min(low[x],dfn[e[i].to]);
	if (dfn[x]==low[x])
	{
		tot++;int y=0;
		while (y!=x)
		{
			y=stack[top--];ins[y]=0;
			bel[y]=tot;
		}
	}
}

void build()
{
	for (int i=1;i<=p;i++) con[bel[i]]=bel[i+p],con[bel[i+p]]=bel[i];
	for (int i=1;i<=M;i++) con[bel[p*2+i]]=bel[p*2+i+M],con[bel[p*2+i+M]]=bel[p*2+i];
	for (int i=1;i<=cnt;i++)
	{
		int x=bel[e[i].from],y=bel[e[i].to];
		if (x!=y) vec[x].pb(y),bac[y].pb(x);
	}
}

void fill(int x,int y)
{
	cho[x]=y;
	if (y==1)
	{
		for (int i=0;i<vec[x].size();i++)
			if (!cho[vec[x][i]]) fill(vec[x][i],y);
	}
	else
	{
		for (int i=0;i<bac[x].size();i++)
			if (!cho[bac[x][i]]) fill(bac[x][i],y);
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&p,&M,&m);
	for (int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x+p,y);addedge(y+p,x);
	}
	for (int i=1;i<=M;i++)
	{
		if (i>1) addedge(p*2+i+M,p*2+i-1+M);
		if (i<M) addedge(p*2+i,p*2+i+1);
	}
	for (int i=1;i<=p;i++)
	{
		scanf("%d%d",&lef[i],&rig[i]);
		if (lef[i]>1) addedge(p*2+lef[i]-1,i+p),addedge(i,p*2+lef[i]-1+M);
		addedge(p*2+rig[i]+M,i+p);addedge(i,p*2+rig[i]);
		
	}
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y+p);addedge(y,x+p);
	}
	for (int i=1;i<=p*2;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=p;i++) if (bel[i]==bel[i+p]) {puts("-1");return 0;}
	for (int i=1;i<=M;i++) if (bel[p*2+i]==bel[p*2+i+M]) {puts("-1");return 0;}
	build();
 	for (int i=1;i<=tot;i++)
		if (!cho[i]) fill(i,1),fill(con[i],2);
	int k=0,f;
	for (int i=M;i>=1;i--) if (cho[bel[p*2+i+M]]==1) {f=i+1;break;}
	for (int i=1;i<=p;i++)
		if (cho[bel[i]]==1) k++;
	printf("%d %d\n",k,f);
	for (int i=1;i<=p;i++)
		if (cho[bel[i]]==1) printf("%d ",i);
	return 0;
}