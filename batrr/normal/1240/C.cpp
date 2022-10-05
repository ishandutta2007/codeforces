#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector< pii > g[N];
int n, k;
ll a[N], b[N];

void dfs(int v, int p){
	for(auto it : g[v]){
		int to = it.f;
		int w = it.s;
		if(to == p)
			continue;
		dfs(to, v);
	}
	
	ll sum = 0;
	vector< ll > vv;
	for(auto it : g[v]){
		int to = it.f;
		int w = it.s;
		if(to == p)
			continue;
		sum += a[to];		
		vv.pb(b[to] + w - a[to]);
	}
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	
	a[v] = sum;
	for(int i = 0; i < min(k, (int)vv.size()); i++)
		a[v] += max(0ll, vv[i]);	
	b[v] = sum;
	for(int i = 0; i < min(k - 1, (int)vv.size()); i++)
		b[v] += max(0ll, vv[i]);	
}
int main()
{
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <n; i++){
			int v, u, w;
			scanf("%d%d%d", &v, &u, &w);
			g[v].pb({u, w});
			g[u].pb({v, w});
		}
		dfs(1, 1);
		printf("%lld\n", max(a[1], b[1]));
	}
	return 0;
}