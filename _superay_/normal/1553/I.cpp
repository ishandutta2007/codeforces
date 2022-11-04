#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
using Poly = vector<int>;
namespace NTT {
	const int PN = 1 << 17;
	int W[2][PN + 5], rev[PN + 5], stk[PN + 5];
	struct Initializer_t {
		Initializer_t() {
			int x = qp(3, (mod - 1) / PN), y = qp(x, mod - 2);
			W[0][0] = W[1][0] = 1;
			for (int i = 1; i < PN; i++) {
				W[0][i] = 1ll * W[0][i - 1] * x % mod;
				W[1][i] = 1ll * W[1][i - 1] * y % mod;
			}
			rev[0] = 0;
		}
	} Initializer;
	void DFT(int n, int *a, int flag) {
		for (int i = 0; i < n; i++) if (rev[i] > i) swap(a[rev[i]], a[i]);
		for (int i = 2; i <= n; i <<= 1) {
			int i2 = i >> 1;
			for (int j = 0; j < i2; j++) stk[j] = W[flag][PN / i * j];
			for (int j = 0; j < n; j += i) {
				int *p1 = a + j, *p2 = a + j + i2, *p3 = stk;
				for (int k = 0; k < i2; k++, ++p1, ++p2, ++p3) {
					int x = *p1, y = 1ll * *p2 * *p3 % mod;
					*p1 = (x + y >= mod ? x + y - mod : x + y);
					*p2 = (x - y < 0 ? x - y + mod : x - y);
				}
			}
		}
		if (flag) {
			int t = qp(n, mod - 2);
			for (int i = 0; i < n; i++) a[i] = 1ll * a[i] * t % mod;
		}
	}
	Poly operator+(const Poly &a, const Poly &b) {
		Poly ret(max(a.size(), b.size()));
		for (int i = 0; i < (int)ret.size(); i++) {
			ret[i] = ((i < (int)a.size() ? a[i] : 0) + (i < (int)b.size() ? b[i] : 0)) % mod;
		}
		return ret;
	}
	int ta[PN + 5], tb[PN + 5];
	Poly operator*(const Poly &a, const Poly &b) {
		int n = a.size(), m = b.size();
		if (!n || !m) return {};
		for (int i = 0; i < n; i++) ta[i] = a[i];
		for (int i = 0; i < m; i++) tb[i] = b[i];
		int len, cnt;
		for (len = 1, cnt = 0; len < n + m - 1; len <<= 1, cnt++);
		for (int i = 1; i < len; i++) rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1)));
		for (int i = n; i < len; i++) ta[i] = 0;
		for (int i = m; i < len; i++) tb[i] = 0;
		DFT(len, ta, 0);
		DFT(len, tb, 0);
		for (int i = 0; i < len; i++) ta[i] = 1ll * ta[i] * tb[i] % mod;
		DFT(len, ta, 1);
		return Poly(ta, ta + n + m - 1);
	}
}
using NTT::operator+;
using NTT::operator*;
const int N = 100005;
int n, m, a[N], b[N];
vector<vector<Poly>> solve(int l, int r) {
	if (l == r) {
		if (b[l] == 1) return {{{0, 1}, {0, 2}}, {{1}, {1}}};
		else return {{{0, 2}, {0, 2}}, {{1}, {1}}};
	}
	int mid = (l + r) >> 1;
	vector<vector<Poly>> L = solve(l, mid), R = solve(mid + 1, r), res = {{{}, {}}, {{}, {}}};
	for (int a = 0; a < 2; a++) for (int b = 0; b < 2; b++) for (int c = 0; c < 2; c++) {
		res[a][c] = res[a][c] + L[a][b] * R[b][c];
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ) {
		b[++m] = a[i];
		for (int j = i; j < i + b[m]; j++) {
			if (j > n || a[j] != b[m]) {
				puts("0");
				return 0;
			}
		}
		i += b[m];
	}
	Poly res = solve(1, m)[0][0];
	int ans = 0;
	for (int i = 1, fct = 1; i <= m; i++) {
		fct = 1ll * fct * i % mod;
		ans = (ans + 1ll * ((m - i) % 2 ? mod - fct : fct) * res[i]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}