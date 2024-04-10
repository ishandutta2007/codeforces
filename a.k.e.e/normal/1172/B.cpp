#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=200005,MOD=998244353;

int n;
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

int f[MAXN],fac[MAXN],ind[MAXN];
void dfs(int u,int pa)
{
	int cnt=0;
	f[u]=1;
	for(Edge *p=h[u];p;p=p->next)
	{
		if(p->v==pa)continue;
		++cnt;
		dfs(p->v,u);
		f[u]=(ll)f[u]*f[p->v]%MOD;
	}
	if(cnt)f[u]=(ll)f[u]*fac[cnt+1]%MOD;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int u,v;
    scanf("%d",&n);
    fac[0]=1;
    for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%MOD;
    for(int i=1;i<n;i++)
    {
    	scanf("%d%d",&u,&v);
    	addEdge(u,v);addEdge(v,u);
    	++ind[u];++ind[v];
    }
    for(int i=1;i<=n;i++)
    	if(ind[i]==1)
		{
			u=i;
			v=h[u]->v;
			break;
		}
    dfs(v,u);
    cout<<(ll)f[v]*n%MOD<<endl;
    return 0;
}