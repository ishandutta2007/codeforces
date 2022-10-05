#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector< int > g[N];
ll ans, x[N];
pll a[N][100];
int n, sz[N];
void dfs(int v, int p, int depth){
	a[v][sz[v]++] = {x[v], depth};
	for(int i = 0; i < sz[v]; i++)
		a[v][i].f = __gcd(a[v][i].f, x[v]);
	int s = 0;
	for(int i = 0; i < sz[v]; i++)	
		if(i == 0 || a[v][i].f != a[v][i - 1].f)
			a[v][s++] = a[v][i];
	sz[v] = s;

	for(int i = 0; i < sz[v]; i++)
		if(i + 1 == sz[v])
        	ans = (ans + a[v][i].f * (depth - a[v][i].s + 1)) % mod;
		else
			ans = (ans + a[v][i].f * (a[v][i + 1].s - a[v][i].s)) % mod;
	
	for(auto to : g[v]){
		if(to == p)
			continue;
		for(int j = 0; j < sz[v]; j++)
			a[to][j] = a[v][j];
		sz[to] = sz[v];
		dfs(to, v, depth + 1);
	}
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &x[i]);
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1, 1, 0);
	printf("%lld", ans);
	return 0;
}