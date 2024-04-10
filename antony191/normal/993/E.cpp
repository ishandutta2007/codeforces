#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 998244353, md = 998244352;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

#define int ll
struct complex {
	ld r, i;
	complex() { r = i = .0; }
	complex(ld a) { r = a, i = .0; }
	complex(ld a, ld b) { r = a, i = b; }
	ld real() { return r; }
	ld imag() { return i; }
	friend complex operator +(const complex & a, const complex & b) {
		return { a.r + b.r, a.i + b.i };
	}
	friend complex operator -(const complex & a, const complex & b) {
		return { a.r - b.r, a.i - b.i };
	}
	friend complex operator *(const complex & a, const complex & b) {
		return { a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r };
	}
};
int n;
vector<complex> f1, f2;
complex x, y;
vector<int> inv_bit;
void init(int m) {
	int k = 0;
	for (; (1 << k) < m; ++k);
	n = 1 << k;
	inv_bit.resize(n);
	f1.resize(n); f2.resize(n);
	forn(i, n) {
		int tmp = 0;
		forn(j, k)
			if (i & (1 << j))
				tmp += 1 << (k - j - 1);
		inv_bit[i] = tmp;
		// w[i] = complex(cos(2.0 * pi * (ld)i / (ld)n), sin(2.0 * pi * (ld)i / (ld)n));
	}
}

void fft(vector<complex> & f) {
	forn(i, n) if (inv_bit[i] < i) swap(f[i], f[inv_bit[i]]);
	for (int s = 1; s + s <= n; s <<= 1) {
		double angle = 2.0 * pi / (double)(s + s);
		complex wn = complex(cos(angle), sin(angle));
		for (int st = 0; st < n; st += s + s) {
			complex w = complex(1);
			for (int i = 0; i < s; ++i) {
				x = f[st + i], y = f[st + s + i] * w;
				f[st + i] = x + y;
				f[st + s + i] = x - y;
				w = w * wn;
			}
		}
	}
}

void mult(vector<int> & a, vector<int> & b, vector<int> & c) {
	int m = (int)a.size(), k = (int)b.size();
	//reverse(all(a)); reverse(all(b));
	forn(i, n) f1[i] = i < m ? a[i] : 0;
	fft(f1);
	forn(i, n) f2[i] = i < k ? b[i] : 0;
	fft(f2);
	forn(i, n) f1[i] = f1[i] * f2[i];
	fft(f1);
	reverse(f1.begin() + 1, f1.end());
	c.resize(n);
	forn(i, n) c[i] = round(f1[i].r / (ld)n);
	//while (c.back() == 0) c.pop_back();
	//reverse(all(c));
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<int> a;
	init(n + n);
	forn(i, n) {
		int c;
		cin >> c;
		if (c < x) a.push_back(i);
	}
	int m = n;
	n = (int)a.size();
	vector<int> b(n), c(n);
	forn(i, n) {
		b[i] = a[i] - (i > 0 ? a[i - 1] : -1);
	}
	forn(i, n) {
		c[i] = (i > 0 ? a[n - i] : m) - a[n - 1 - i];
	}
	vector<int> d;
	mult(b, c, d);
	reverse(d.begin(), d.begin() + n + 1);
	d[0] = 0;
	a.push_back(m);
	forn(i, n + 1) {
		if (i > 0) d[0] += (a[i] - a[i - 1]) * (a[i] - a[i - 1] - 1) / 2;
		else d[0] += (a[0]) * (a[0] + 1) / 2;
	}
	forn(i, m + 1) {
		cout << (i > n ? 0 : d[i]) << ' ';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}