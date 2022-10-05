#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100500;

vector< int > g[N];
int n, m, q, deg[N];
ll ans;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		if(v > u)
			swap(v, u);
		g[v].pb(u);
		deg[v]++;
		deg[u]++;
	}
	for(int v = 1; v <= n; v++)
		ans += 1ll * g[v].size() * (deg[v] - g[v].size());
	scanf("%d", &q);
    printf("%lld\n", ans);
	while(q--){
		int v;
		scanf("%d", &v);
		ans -= 1ll * g[v].size() * (deg[v] - g[v].size());
		for(auto to : g[v]){
			ans -= g[to].size();
			g[to].pb(v);
			ans += deg[to] - g[to].size();
		}
		g[v].clear();
		printf("%lld\n", ans);
	}
	return 0;
}