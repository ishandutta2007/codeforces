#include<bits/stdc++.h>
#define int long long
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

const int N = 500015;

int n, q, a[3][N];

ll sum[3][N], f[N], g[N], h[N];

void solve(int L, int R, vector<tuple<int, int, int>> vec, int ck) {
	if (L == R) return;

	vector<tuple<int, int, int>> nvec;
	int tk = ck;

	for (auto [l, r, k] : vec) {
		if (r < L || l > R) continue;

		if (l <= L && R <= r) tk = min(tk, k);
		else nvec.emplace_back(max(L, l), min(R, r), k);
	}

	int M = (L + R) >> 1;
	solve(L, M, nvec, tk);
	nvec.emplace_back(L, R, tk);
	fill(g + L, g + R + 2, infll);

	per(i, L, M) g[i] = min(f[i], h[i]);

	per(i, L, M - 1) g[i] = min(g[i], g[i + 1]);

	for (auto [l, r, k] : nvec) if (l <= M && r > M) g[r] = min(g[r], g[l] + k);

	per(i, M + 1, R - 1) g[i] = min(g[i], g[i + 1]);

	rep(i, M + 1, R) f[i] = min(f[i], g[i]);

	nvec.pop_back();
	solve(M + 1, R, nvec, tk);
}

signed main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%lld%lld", &n, &q);
	rep(j, 0, 2) rep(i, 1, n) scanf("%lld", &a[j][i]), a[j][i] *= -1;
	rep(j, 0, 2) rep(i, 1, n) sum[j][i] = sum[j][i - 1] + a[j][i];
	vector<tuple<int, int, int>> vec;
	memset(f, 0x3f, sizeof f);
	rep(_, 1, q) {
		int l, r, k;
		scanf("%lld%lld%lld", &l, &r, &k);
		vec.emplace_back(l, r + 1, k);
	}
	rep(i, 1, n) h[i] = sum[0][i] - sum[1][i - 1];
	h[n + 1] = infll;
	solve(1, n + 1, vec, infll);
	ll ans = infll;

	rep(i, 1, n) ans = min(ans, f[i + 1] + sum[1][i] + sum[2][n] - sum[2][i - 1]);

	printf("%lld\n", -ans);
	return 0;
}