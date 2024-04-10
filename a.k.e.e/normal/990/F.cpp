#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=200005,MOD=1000000007;

int n,m,a[MAXN],f[MAXN<<1|1];
struct Node
{
	int v,id;
	Node *next;
}pool[MAXN<<1|1],*h[MAXN];
int etot=0;
inline void addEdge(int u,int v,int id)
{
	Node *p=&pool[++etot];
	p->v=v;p->id=id;p->next=h[u];h[u]=p;
}

bool vis[MAXN];
int dfs(int u)
{
	vis[u]=1;
	for(Node *p=h[u];p;p=p->next)
	{
		if(vis[p->v])continue;
		a[u]+=(f[p->id]=dfs(p->v));
	}
	return a[u];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&u,&v);
    	addEdge(u,v,i);
    	addEdge(v,u,i+m);
    }
	int t=dfs(1);
    if(t)return 0*printf("Impossible\n");
    printf("Possible\n");
    for(int i=1;i<=m;i++)
    	if(f[i])printf("%d\n",f[i]);
    	else printf("%d\n",-f[i+m]);
    return 0;
}