#include <bits/stdc++.h>
#ifdef local
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

const int N = 3e4 + 5;

#define ll long long

typedef class Data {
	public:
		ll ans, len;
		bitset<N> pre, suf; 
		// pre_i : first (n - i - 1) characters
		// suf_i : last (i + 1) characters

		Data() : ans(0), len(0) {	}
} Data;

bitset<N> msk;

void debug(const bitset<N>& bs, int lim) {
	for (int i = lim - 1; ~i; i--) {
		putchar('0' + bs.test(i));
	}
}

int n, d, m;
int cnt = 1;
int *gen, *a;
Data f[66][65];
ll len[65], L, R;

ostream& operator << (ostream& os, const bitset<N>& bs) {
	debug(bs, n - 1);
	return os;
}

bitset<N> reserve(const bitset<N>& bs, int l, int r) {
	assert(l <= r);
	r++;
	return ((bs >> l) << (N - (r - l))) >> (N - r);;
}

Data operator + (const Data& a, const Data& b) {
	Data rt;
	rt.pre = a.pre, rt.suf = b.suf;
	rt.ans = a.ans + b.ans, rt.len = a.len + b.len;
	if (a.len < n - 1)
		rt.pre = ((b.pre >> a.len) & a.pre) | reserve(a.pre, n - a.len - 1, n);
	if (b.len < n - 1)
		rt.suf = ((a.suf << b.len) & b.suf) | reserve(b.suf, 0, b.len - 1);
	if (a.len + b.len > n - 1) {
// i <= a.len, n - i <= b.len
// i <= a.len, i >= n - b.len
		int l = max(1ll, n - b.len) - 1, r = min((ll) n, a.len) - 1; 
		if (l <= r) {
			rt.ans += (reserve(a.suf, l, r) & b.pre).count();
		}
	}
	return rt;
}

inline void init() {
	scanf("%d%d", &d, &m);
	gen = new int[(d + 1)];
	for (int i = 0; i < d; i++) {
		scanf("%d", gen + i);
	}
	scanf("%d", &n);
	a = new int[(n + 1)];
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	scanf(Auto""Auto, &L, &R);
}

ll Solve(ll L) {
	Data rt;
	rt.pre = msk, rt.suf = msk;
	int add = 0;
	for (int i = cnt; ~i; i--) {
		int dif = 0;
		for (int j = 0; L >= len[i]; j++, L -= len[i]) {
			dif = gen[j + 1];
			rt = rt + f[i][(add + gen[j]) % m];
		}
		add = (add + dif) % m;
	}
	return rt.ans;
}

inline void solve() {
	for (int i = 0; i < n - 1; i++)
		msk.set(i);
	len[0] = 1, len[1] = d;
	for (int i = 0; i < m; i++) {
		f[0][i].len = 1, f[0][i].ans = (n == 1 && i <= a[0]);
		for (int j = 0; j < n - 1; j++) {
			f[0][i].pre[j] = (i <= a[n - j - 1]);
			f[0][i].suf[j] = (i <= a[j]);
		}
	}
	for (int i = 0; i < m; i++) {
		f[1][i].len = d, f[1][i].ans = 0;
		if (d >= n) {
			for (int s = 0; s <= d - n; s++) {
				int dif = 1;
				for (int j = 0; j < n && dif == 1; j++) {
					dif -= (((gen[s + j] + i) % m) > a[j]);
				}
				f[1][i].ans += dif;
			}
		}
		for (int l = 0; l < n - 1; l++) {
			int sgn_pre = 1, sgn_suf = 1;
			for (int j = 0; j < d && j <= l && (sgn_pre + sgn_suf); j++) {
				sgn_suf = sgn_suf && (((gen[d - j - 1] + i) % m) <= a[l - j]);
				sgn_pre = sgn_pre && (((gen[j] + i) % m) <= a[n - l - 1 + j]);
			}
			f[1][i].suf[l] = sgn_suf;
			f[1][i].pre[n - l - 2] = sgn_pre;
		}
//		cerr << "> " << 1 << " " << i << '\n';
//		cerr << ">> ans: " << f[1][i].ans << '\n';
//		cerr << ">> pre: " << f[1][i].pre << '\n';
//		cerr << ">> suf: " << f[1][i].suf << '\n';
	}
	while (len[cnt] < R) {
		len[cnt + 1] = len[cnt] * d, cnt++;
		for (int i = 0; i < m; i++) {
			Data& F = f[cnt][i];
			F.pre = msk, F.suf = msk;
			for (int j = 0; j < d; j++) {
				F = F + f[cnt - 1][(i + gen[j]) % m];
			}
//			cerr << "> " << cnt << " " << i << '\n';
//			cerr << ">> ans: " << F.ans << '\n';
//			cerr << ">> pre: " << F.pre << '\n';
//			cerr << ">> suf: " << F.suf << '\n';
		}
	}
	ll _ = Solve(R);
	ll __ = Solve(L + n - 2);
//	cerr << _ << " " << __ << '\n';
	printf(Auto, _ - __);
}

int main() {
	init();
	solve();
	return 0;
}