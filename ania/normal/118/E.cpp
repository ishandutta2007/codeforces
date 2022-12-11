#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define err(...) fprintf(stderr, __VA_ARGS__)

typedef pair<int,int> pi;
typedef long long int64;
typedef vector<int> vi;

#define fore(i,n) for(int i = 0; i < (n); i++)
#define tr(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define x first
#define y second
#define mp make_pair
#define pb push_back

void wrong()
{
	printf("0\n");
	exit(0);
}

#define maxn 300300

int n,m,a,b;
vi g[maxn];
int c[maxn], rank[maxn], low[maxn], par[maxn];

void dfs(int u, int p)
{
	c[u] = 1;
	par[u] = p;
	if(p==-1) rank[u] = 1;
	else rank[u] = rank[p] + 1;
	low[u] = rank[u];
	tr(i,g[u])
	{
		int v = *i;
		if(v == p) continue;
		if(c[v] == 0) dfs(v, u);
		low[u] = min(low[v], low[u]);
	}
	if(p != -1 && low[u] >= rank[u]) wrong();
}

int main()
{
	scanf("%d%d", &n, &m);
	fore(i,m)
	{
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	fore(i,n) if(c[i] == 0) wrong();
	fore(i,n) fore(j,g[i].size())
	{
		int u = g[i][j], v = i;;
		if(u<v) continue;
		if(rank[u] < rank[v]) swap(u,v);
		if(par[u] == v) printf("%d %d\n", u+1, v+1);
		else printf("%d %d\n", v+1, u+1);
	}
	return 0;
}