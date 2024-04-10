#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const int N = 2e5 + 5;

int n, m, s;
int a[N];
ll f[N];
vector<int> G[N];
boolean in[N], vis[N];

void dfs(int p, int fa) {
	vis[p] = true;
	for (auto e : G[p]) {
		if (e ^ fa) {
			if (!vis[e]) {
				dfs(e, p);
				in[p] |= in[e];
			} else {
				in[p] = true;
			}
		}
	}
	if (!in[p]) {
		for (auto e : G[p]) {
			if (e ^ fa) {
				f[p] = max(f[p], f[e]);
			}
		}
		f[p] += a[p];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d", &s);
	dfs(s, 0);
	ll ans = 0, mx = 0;
	for (int i = 1; i <= n; i++) {
		if (in[i]) {
			ans += a[i];
		} else {
			mx = max(mx, f[i]);
		}
	}
	printf("%lld\n", ans + mx);
	return 0;
}