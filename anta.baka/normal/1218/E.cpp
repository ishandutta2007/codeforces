#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cassert>
#include <set>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
using vi = vector<int>;

const int mod = 998244353;
const int L = 22;	// can be 23 for 998244353
const int N = 1 << L;
bool fft_initialized = false;

using Poly = vector<long long>;

long long pw(long long a, long long b) {
	long long res = 1;
	while (b) {
		if (b & 1ll) {
			res = res * a % mod;
		}
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

int getRoot() {
	int root = 1;
	while (pw(root, 1 << L) != 1 || pw(root, 1 << (L - 1)) == 1) {
		++root;
	}
	return root;
}

const int root = getRoot();

long long angles[N + 1];
int bitrev[N];

void fft_init() {
	angles[0] = 1;
	for (int i = 1; i <= N; ++i) {
		angles[i] = angles[i - 1] * root % mod;
	}

	for (int i = 0; i < N; ++i) {
		int x = i;
		for (int j = 0; j < L; ++j) {
			bitrev[i] = (bitrev[i] << 1) | (x & 1);
			x >>= 1;
		}
	}

	fft_initialized = true;
}

inline int revBit(int x, int len) {
	return bitrev[x] >> (L - len);
}

int ctz(int x) {
	int r = 0;
	while (!(x & 1)) {
		r++;
		x >>= 1;
	}
	return r;
}

void fft(vector<long long>& a, bool inverse = false) {
	assert(fft_initialized && "you fucking cunt just write fft_init()");
	int n = a.size();
	assert(!(n & (n - 1)));	// work only with powers of two
	//int l = __builtin_ctz(n);
	int l = ctz(n);

	for (int i = 0; i < n; ++i) {
		int j = revBit(i, l);
		if (i < j) {
			swap(a[i], a[j]);
		}
	}

	for (int len = 1; len < n; len *= 2) {
		for (int start = 0; start < n; start += 2 * len) {
			for (int i = 0; i < len; ++i) {
				long long x = a[start + i], y = a[start + len + i];
				int idx = N / 2 / len * i;
				long long w = angles[inverse ? N - idx : idx];
				w = w * y % mod;
				a[start + i] = x + w;
				if (a[start + i] >= mod) {
					a[start + i] -= mod;
				}
				a[start + len + i] = x - w;
				if (a[start + len + i] < 0) {
					a[start + len + i] += mod;
				}
			}
		}
	}

	if (inverse) {
		int rev_deg = 1;
		for (int i = 0; i < l; ++i) {
			rev_deg = (rev_deg % 2) ? ((rev_deg + mod) / 2) : (rev_deg / 2);
		}
		for (auto& x : a) {
			x = x * rev_deg % mod;
		}
	}
}

Poly multiply(Poly a, Poly b) {
	int n = 1;
	while (n < (int)a.size() || n < (int)b.size()) {
		n *= 2;
	}
	a.resize(n + n);
	b.resize(n + n);
	fft(a);
	fft(b);
	for (int i = 0; i < n + n; ++i) {
		a[i] = a[i] * b[i] % mod;
	}
	fft(a, true);
	while (!a.empty() && a.back() == 0) {
		a.pop_back();
	}
	return a;
}

int add(int x, int y) {
	if ((x += y) >= mod) {
		x -= mod;
	}
	return x;
}

int sub(int x, int y) {
	if ((x -= y) < 0) {
		x += mod;
	}
	return x;
}

Poly solve(vi& a, int l, int r) {
	if (l == r) {
		return { 1, a[l] };
	}
	int m = (l + r) >> 1;
	return multiply(solve(a, l, m), solve(a, m + 1, r));
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	fft_init();
	int n, k;
	cin >> n >> k;
	vi a(n);
	for (auto& x : a) cin >> x;
	int qq;
	cin >> qq;
	while (qq--) {
		int type, q;
		cin >> type >> q;
		vi b = a;
		if (type == 1) {
			int i, d;
			cin >> i >> d;
			--i;
			b[i] = d;
		}
		else {
			int l, r, d;
			cin >> l >> r >> d;
			--l;
			for (int i = l; i < r; i++) {
				b[i] = add(b[i], d);
			}
		}
		for (auto& x : b) {
			x = sub(q, x);
		}
		cout << solve(b, 0, n - 1)[k] << '\n';
	}
}