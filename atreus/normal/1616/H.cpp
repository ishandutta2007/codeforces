#include <bits/stdc++.h>
#define bit(n, k) (((n)>>(k))&1)
using namespace std;

const int maxn = 150 * 1000 * 30 + 10;
const int mod = 998244353;

int x, lastBit, child[maxn][2], h[maxn], cnt[maxn], pw[maxn];
int newint = 2;
int DP[maxn];

int dp(int);

int pd(int v, int u) {
	if (v == 0 || u == 0)
		return 0;
	if (h[v] == -1)
		return 1LL * (pw[cnt[v]] - 1 + mod) * (pw[cnt[u]] - 1 + mod) % mod;
	if (!bit(x, h[v])) {
		int ret = pd(child[v][0], child[u][0]) + pd(child[v][1], child[u][1]);
		if (ret >= mod)
			ret -= mod;
		return ret;
	}
	else {
		int b4 = 1LL * pd(child[v][0], child[u][1]) * pd(child[v][1], child[u][0]) % mod;
		int b3 = 1LL * pd(child[v][0], child[u][1]) * (DP[child[u][0]] + DP[child[v][1]] - 1LL + mod) % mod;
		int b2 = 1LL * pd(child[v][1], child[u][0]) * (DP[child[u][1]] + DP[child[v][0]] - 1LL + mod) % mod;
		int b1 = (1LL * (DP[child[v][0]] - 1 + mod) * (DP[child[u][0]] - 1 + mod) + 
				  1LL * (DP[child[v][1]] - 1 + mod) * (DP[child[u][1]] - 1 + mod)) % mod;
		int r = b1 + b2;
		if (r >= mod)
			r -= mod;
		r += b3;
		if (r >= mod)
			r -= mod;
		r += b4;
		if (r >= mod)
			r -= mod;
		return r;
	}
}

int dp(int v) {
	if (DP[v] != -1)
		return DP[v];
	if (lastBit > h[v]) {
		dp(child[v][0]);
		dp(child[v][1]);
		return DP[v] = pw[cnt[v]];
	}
	if (!bit(x, h[v])) {
		int ret = dp(child[v][0]) + dp(child[v][1]) - 1;
		if (ret >= mod)
			ret -= mod;
		if (ret < 0)
			ret += mod;
		return DP[v] = ret;
	}
	else { 
		int ret = dp(child[v][0]) + dp(child[v][1]) - 1;
		if (ret >= mod)
			ret -= mod;
		if (ret < 0)
			ret += mod;
		ret += pd(child[v][0], child[v][1]);
		if (ret >= mod)
			ret -= mod;
		return DP[v] = ret;
	}
}

void add(int k) {
	int root = 1;
	cnt[root]++;
	h[root] = 29;
	for (int i = 29; i >= 0; i--) {
		int c = bit(k, i);
		if (child[root][c] == 0) {
			child[root][c] = newint++;
			h[child[root][c]] = i - 1;
		}
		root = child[root][c];
		cnt[root]++;
	}
}

void solve() {
	memset(DP, -1, sizeof DP);
	DP[0] = 1;
	pw[0] = 1;
	for (int i = 1; i < maxn; i++)
		pw[i] = (pw[i - 1] + pw[i - 1]) % mod;
	int n;
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		add(a);
	}
	if (x == 0) {
		int answer = 0;
		for (int i = 0; i < maxn; i++)
			if (h[i] == -1)
				answer = (0LL + answer + pw[cnt[i]] - 1 + mod) % mod;
		cout << answer << '\n';
		return;
	}
	lastBit = -1;
	for (int i = 0; i < 30; i++)
		if (bit(x, i))
			lastBit = i;
	cout << (dp(1) - 1 + mod) % mod << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc = 1;
	while (tc --) {
		solve();
	}
}