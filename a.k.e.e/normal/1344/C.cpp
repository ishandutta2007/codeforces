#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005;

int n;
vector<int> F[MAXN],G[MAXN];
int deg[MAXN],q[MAXN],f[MAXN],g[MAXN];
void solve(vector<int> *G,int *g)
{
	int front=1,rear=0;
	memset(deg,0,sizeof(deg));
	for(int i=1;i<=n;++i)for(auto j:G[i])++deg[j];
	for(int i=1;i<=n;++i)if(!deg[i])q[++rear]=i;
	for(int i=1;i<=n;++i)g[i]=i;
	while(front<=rear)
	{
		int u=q[front++];
		for(auto v:G[u])
		{
			--deg[v];
			chkmin(g[v],g[u]);
			if(!deg[v])q[++rear]=v;
		}
	}
	if(rear!=n)exit(0*printf("-1\n"));
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E,u,v;
	readint(n),readint(E);
	while(E--)readint(u),readint(v),F[u].pb(v),G[v].pb(u);
	solve(F,f);
	solve(G,g);
	int cnt=0;
	for(int i=1;i<=n;++i)if(f[i]==i && g[i]==i)++cnt;
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i)putchar( f[i]==i && g[i]==i ? 'A' : 'E' );
	return 0;
}