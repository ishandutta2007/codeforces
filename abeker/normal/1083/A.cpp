#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;
const ll INF = 1e18;

int N;
int w[MAXN];
vector <pii> adj[MAXN];
ll sum[MAXN], best[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", w + i);
	for (int i = 1; i < N; i++) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
}

ll dfs(int x, int p) {
	sum[x] += w[x];
	best[x] = sum[x];
	for (auto it : adj[x])
		if (it.first != p) {
			sum[it.first] = sum[x] - it.second;
			best[x] = max(best[x], dfs(it.first, x));
		}
	return best[x];
}

ll go(int x, int p) {
	ll mx1 = sum[x], mx2 = -INF;
	ll res = -INF;
	for (auto it : adj[x])	
		if (it.first != p) {
			res = max(res, go(it.first, x));
			if (best[it.first] >= mx1) {
				mx2 = mx1;
				mx1 = best[it.first];
			}
			else if (best[it.first] > mx2)
				mx2 = best[it.first];
		}
	res = max(res, max(mx1 + mx2 - 2 * sum[x], 0ll) + w[x]);
	return res;
}

ll solve() {
	dfs(1, 0);
	return go(1, 0);
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}