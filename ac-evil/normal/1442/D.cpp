#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;
const int N = 3e3 + 5, LG = 15;
int n, m, t[N]; ll f[LG][N];
std::vector<ll> vec[N];
ll ans = 0;
auto chkmax = [](ll &x, ll y) {
	if (x < y) return x = y, true;
	return false;
};
void solve(int l, int r, int dep) {
	if (l == r) {
		for (int i = 0; i < t[l]; i++) {
			if (i + 1 > m) break;
			chkmax(ans, f[dep - 1][m - i - 1] + vec[l][i]);
		}
		return;
	}
	int mid = l + r >> 1;
	std::copy(f[dep - 1], f[dep - 1] + m + 1, f[dep]);
	for (int i = mid + 1; i <= r; i++)
		for (int j = m; j >= t[i]; j--)
			chkmax(f[dep][j], f[dep][j - t[i]] + vec[i][t[i] - 1]);
	solve(l, mid, dep + 1);
	std::copy(f[dep - 1], f[dep - 1] + m + 1, f[dep]);
	for (int i = l; i <= mid; i++)
		for (int j = m; j >= t[i]; j--)
			chkmax(f[dep][j], f[dep][j - t[i]] + vec[i][t[i] - 1]);
	solve(mid + 1, r, dep + 1);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		for (int j = 0; j < t[i]; j++) {
			int x; scanf("%d", &x); vec[i].pb(x);
		}
		std::partial_sum(vec[i].begin(), vec[i].end(), vec[i].begin());
	}
	solve(1, n, 1);
	printf("%lld\n", ans);
	return 0;
}