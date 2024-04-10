#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;

namespace NTT {
const int MaxN = 2500 * 1000 + 555;
const int LOGN = 22;
const int g = 3;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define sz(a) int((a).size())

inline int mul(int a, int b) {
	return int(a * 1ll * b % mod);
}

inline int norm(int a) {
	if (a >= mod)
		a -= mod;
	if (a < 0)
		a += mod;
	return a;
}

inline int binPow(int a, int k) {
	int ans = 1;
	while (k > 0) {
		if (k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}

inline int inv(int a) {
	return binPow(a, mod - 2);
}

vector<int> w[LOGN];
vector<int> rv[LOGN];

void init() {
	int wb = binPow(g, (mod - 1) / (1 << LOGN));

	for (int st = 0; st < LOGN - 1; st++) {
		w[st].assign(1 << st, 1);

		int bw = binPow(wb, 1 << (LOGN - st - 1));
		int cw = 1;

		for (int k = 0; k < (1 << st); k++) {
			w[st][k] = cw;
			cw = mul(cw, bw);
		}
	}
	for (int st = 0; st < LOGN; st++) {
		rv[st].assign(1 << st, 0);

		if (st == 0) {
			rv[st][0] = 0;
			continue;
		}
		int h = (1 << (st - 1));
		for (int k = 0; k < (1 << st); k++)
			rv[st][k] = (rv[st - 1][k & (h - 1)] << 1) | (k >= h);
	}
}

inline void fft(int a[MaxN], int n, bool inverse) {
	int ln = 0;
	while ((1 << ln) < n)
		ln++;

	assert((1 << ln) < MaxN);
	n = (1 << ln);

	forn(i, n)
	{
		int ni = rv[ln][i];
		if (i < ni)
			swap(a[i], a[ni]);
	}

	for (int st = 0; (1 << st) < n; st++) {
		int len = (1 << st);
		for (int k = 0; k < n; k += (len << 1)) {
			for (int pos = k; pos < k + len; pos++) {
				int l = a[pos];
				int r = mul(a[pos + len], w[st][pos - k]);

				a[pos] = norm(l + r);
				a[pos + len] = norm(l - r);
			}
		}
	}

	if (inverse) {
		int in = inv(n);
		forn(i, n)
			a[i] = mul(a[i], in);
		reverse(a + 1, a + n);
	}
}

int aa[MaxN], bb[MaxN], cc[MaxN];

inline vector<int> multiply(const vector<int> a, const vector<int> b) {
	int ln = 1;
	while (ln < (sz(a) + sz(b)))
		ln <<= 1;

	forn(i, ln)
		aa[i] = (i < sz(a) ? a[i] : 0);

	forn(i, ln)
		bb[i] = (i < sz(b) ? b[i] : 0);

	fft(aa, ln, false);
	fft(bb, ln, false);

	forn(i, ln)
		cc[i] = mul(aa[i], bb[i]);

	fft(cc, ln, true);

	vector<int> c(ln, 0);
	forn(i, sz(c))
		c[i] = cc[i];

	while (sz(c) > 1 && c.back() == 0)
		c.pop_back();
	return c;
}

vector<int> pow(vector<int> v, int k) {
	vector<int> res = { 1 };
	for (; k; k >>= 1) {
		if (k & 1)
			res = multiply(res, v);
		v = multiply(v, v);
	}
	return res;
}
}
;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	NTT::init();

	int n, k;
	cin >> n >> k;

	vector<int> v(10, 0);
	while (k--) {
		int d;
		cin >> d;
		v[d] = 1;
	}

	v = NTT::pow(v, n / 2);
	ll ans = 0;
	for (int i = 0; i < (int) v.size(); ++i) {
		ans += (ll) v[i] * v[i];
		ans %= mod;
	}

	cout << (ans % mod + mod) % mod;

	return 0;
}