#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,x[MAXN];
struct Edge
{
	int v;
	Edge *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v)
{
	Edge *p=&pool[++etot];
	p->v=v;p->next=h[u];h[u]=p;
}

int fa[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}

int ans[MAXN*5],cnt=0;
inline void insert(int u){x[u]^=1,ans[++cnt]=u;}
void dfs(int u,int pa)
{
	insert(u);
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa)continue;
		dfs(p->v,u);
		insert(u);
		if(x[p->v])insert(p->v),insert(u);
	}
}
void print(int l,int r)
{
	printf("%d\n",r-l+1);
	for(int i=l;i<=r;i++)printf("%d ",ans[i]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int E,u,v;
    scanf("%d%d",&n,&E);
    for(int i=1;i<=n;i++)fa[i]=i;
    while(E--)
    {
    	scanf("%d%d",&u,&v);
    	int tu=getfa(u),tv=getfa(v);
    	if(tu==tv)continue;
    	fa[tu]=tv;
    	addEdge(u,v);addEdge(v,u);
    }
    u=0;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&x[i]);
    	if(x[i])
    	{
    		if(!u)u=getfa(i);
    		if(getfa(i)!=u)return 0*printf("-1\n");
    	}
    }
    dfs(u,-1);
    if(x[u])print(2,cnt);
    else print(1,cnt);
    return 0;
}