#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 200015, mod = 998244353;

int qpow(int a, int b) {
	int res = 1;

	while (b) {
		if (b & 1) res = (ll) res * a % mod;

		a = (ll) a * a % mod;
		b >>= 1;
	}

	return res;
}

vector<int> fac[N];

int pri[N], tot, all;

int t, n, cur[N], Min[N], inv[N], ans = 0;

vector<tuple<int, int, int>> e[N];

void dfs(int u, int pa, int val) {
	(ans += val) %= mod;

	for (auto [v, x, y] : e[u]) {
		if (v == pa) continue;

		for (int o : fac[x]) cur[o]--, val = (ll) val * inv[o] % mod;

		for (int o : fac[y]) cur[o]++, val = (ll) val * pri[o] % mod;

		for (int o : fac[x]) Min[o] = min(Min[o], cur[o]);

		for (int o : fac[y]) Min[o] = min(Min[o], cur[o]);

		dfs(v, u, val);

		for (int o : fac[x]) cur[o]++, val = (ll) val * pri[o] % mod;

		for (int o : fac[y]) cur[o]--, val = (ll) val * inv[o] % mod;
	}
}

void solve() {
	scanf("%d", &n);
	ans = 0;
	rep(i, 1, n) e[i].clear();
	rep(i, 1, n) {
		if (pri[i] <= n) all = i;
		else break;
	}
	fill(cur, cur + all + 1, 0);
	rep(i, 2, n) {
		int u, v, x, y;
		scanf("%d%d%d%d", &u, &v, &x, &y);
		e[u].emplace_back(v, x, y); // / x * y
		e[v].emplace_back(u, y, x);

		for (int o : fac[x]) cur[o]++;

		for (int o : fac[y]) cur[o]++;
	}
	rep(i, 1, all) Min[i] = cur[i];
	int val = 1;
	rep(i, 1, all) val = (ll) val * qpow(pri[i], cur[i]) % mod;
	dfs(1, 0, val);
	rep(i, 1, all) ans = (ll) ans * qpow(inv[i], Min[i]) % mod;
	printf("%d\n", ans);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	rep(i, 2, 200000) {
		if (SZ(fac[i]) == 0) {
			pri[++tot] = i;
			inv[tot] = qpow(i, mod - 2);

			for (int j = i; j <= 200000; j += i) {
				int x = j;

				while (x % i == 0) {
					fac[j].pb(tot);
					x /= i;
				}
			}
		}
	}
	scanf("%d", &t);

	while (t--) solve();

	return 0;
}