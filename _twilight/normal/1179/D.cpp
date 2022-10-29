#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const ll llf = (signed ll) (~0ull >> 1);

const int N = 5e5 + 5;

int n;
ll f[N];
int sz[N];
vector<int> G[N];

ll ans = llf;

ll comb2(int n) {
	return (n * 1ll * (n - 1)) >> 1;
}

void solve(int l, int r, int ql, int qr, int p) {
	if (l > r)
		return;
	int mid = (l + r) >> 1, u = G[p][mid], idx = ql;
	ll mi = llf, tmp;
	for (int i = ql; i <= qr && i < mid; i++) {
		int v = G[p][i];
		tmp = f[u] + f[v] + comb2(n - sz[u] - sz[v]);
		if (tmp < mi) {
			mi = tmp;
			idx = i;
		}
	}
	ans = min(ans, mi);
	solve(l, mid - 1, ql, idx, p);
	solve(mid + 1, r, idx, qr, p);
}

void dfs(int p, int fa) {
	for (int i = 0; i < (signed) G[p].size(); i++) {
		if (G[p][i] == fa) {
			G[p].erase(G[p].begin() + i);
			break;
		}
	}
	sz[p] = 1;
	for (auto e : G[p]) {
		dfs(e, p);
		sz[p] += sz[e];
		ans = min(ans, f[e] + comb2(n - sz[e]));
	}
	f[p] = comb2(sz[p]);
	for (auto e : G[p]) {
		f[p] = min(f[p], f[e] + comb2(sz[p] - sz[e]));
	}
	sort(G[p].begin(), G[p].end(), [&] (int a, int b) {
			return sz[a] < sz[b];	
		});
	solve(1, (signed) G[p].size() - 1, 0, (signed) G[p].size() - 1, p);
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	ll res = comb2(n) * 2 - ans;
	printf("%lld\n", res);
	return 0;
}