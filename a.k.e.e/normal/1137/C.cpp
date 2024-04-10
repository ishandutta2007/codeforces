#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN=5000005,MAXD=53;

int n,d,m;
char str[MAXD];
bool cv[MAXN];
inline calc(int x,int y){return (x-1)*d+y;}
struct Edge
{
	int v;
	Edge *next;
}pool[MAXN<<1|1],*h[MAXN],*g[MAXN];
int etot=0;
inline void addEdge(int u,int v)
{
	Edge *p=&pool[++etot];
	p->v=v;p->next=h[u];h[u]=p;
}

int sta[MAXN],dfn[MAXN],dfn_cnt=0,low[MAXN],scc[MAXN],val[MAXN],top;
vector<int> jio[MAXN];
int las[MAXN];
void tarjan(int u)
{
	dfn[u]=low[u]=++dfn_cnt;
	sta[++top]=u;
	for(Edge *p=h[u];p;p=p->next)
		if(!dfn[p->v]){tarjan(p->v);low[u]=min(low[u],low[p->v]);}
		else if(!scc[p->v])low[u]=min(low[u],dfn[p->v]);
	if(dfn[u]==low[u])
	{
		ll x=0;
		++m;
		do
		{
			scc[u=sta[top--]]=m;
			if(las[(u-1)/d+1]<m && cv[u])++val[las[(u-1)/d+1]=m];
			jio[m].push_back(u);
		}while(low[u]!=dfn[u]);
	}
}

int f[MAXN];
int dp(int u)
{
	if(f[u]>=0)return f[u];
	f[u]=val[u];
	for(auto t:jio[u])
		for(Edge *p=h[t];p;p=p->next)
			if(u!=scc[p->v])f[u]=max(f[u],val[u]+dp(scc[p->v]));
	return f[u];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int E,u,v;
    scanf("%d%d%d",&n,&E,&d);
    while(E--)
    {
    	scanf("%d%d",&u,&v);
    	for(int i=1;i<d;i++)
    		addEdge(calc(u,i),calc(v,i+1));
    	addEdge(calc(u,d),calc(v,1));
    }
    for(int i=1;i<=n;i++)
    {
    	scanf("%s",str+1);
    	for(int j=1;j<=d;j++)
    		cv[calc(i,j)]=str[j]-'0';
    }
/*for(int i=1;i<=n*d;i++)
{
	printf("%d:",i);
	for(Edge *p=h[i];p;p=p->next)
		printf("%d ",p->v);
	printf("\n");
}*/
	for(int i=1;i<=n*d;i++)
    	if(!dfn[i])tarjan(i);
    memset(f,-1,sizeof(f));
    printf("%d\n",dp(scc[calc(1,1)]));
    return 0;
}