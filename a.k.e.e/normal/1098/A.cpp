#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,s[MAXN],dep[MAXN];
ll ans=0,a[MAXN];
struct Edge
{
	int v;
	Edge *next;
}pool[MAXN],*h[MAXN];
int etot=0;
void addEdge(int u,int v)
{
	Edge *p=&pool[++etot];
	p->v=v;p->next=h[u];h[u]=p;
}

int pa[MAXN];
void dfs(int u)
{
	ll mx=1ll<<60;
	for(Edge *p=h[u];p;p=p->next)
	{
		dep[p->v]=dep[u]+1;
		pa[p->v]=u;
		mx=min(mx,1ll*s[p->v]-s[pa[u]]);
	}
	if(dep[u]%2==0)
	{
		if(mx<0)exit(0*printf("-1\n"));
		a[u]=(mx==(1ll<<60)?0:mx);
	}
	for(Edge *p=h[u];p;p=p->next)
	{
		if(dep[u]%2==0)a[p->v]=s[p->v]-s[pa[u]]-a[u];
		dfs(p->v);
	}
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int u;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
    	scanf("%d",&u);
    	addEdge(u,i);
    }
    for(int i=1;i<=n;i++)
    	scanf("%d",&s[i]);
    dep[1]=1;
    a[1]=s[1];
    dfs(1);
    for(int i=1;i<=n;i++)ans+=a[i];
    cout<<ans<<endl;
    return 0;
}