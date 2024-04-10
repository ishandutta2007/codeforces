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
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
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
int gcd(int a, int b) {
	while (b > 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}
int gcdex(int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcdex(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
const int T1 = 100000, T2 = 100000;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		pair<int, int> ans(inf, inf);
		int k = gcd(p, q);
		p /= k; q /= k;
		int w = 0;
		if (b - a >= q) b = a + q - 1;
		if (b - a <= T1) {
			for (int x = a; x <= b; ++x) {
				int tmp = x * p % q;
				if (tmp < 0) tmp += q;
				uin(ans, { max(tmp, q - tmp), x });
			}
		}
		else {
			w = (a / q) * q;
			a %= q;
			b %= q;
			if (a < 0) a += q;
			if (b < 0) b += q;
			int tmp = a * p % q;
			if (tmp < 0) tmp += q;
			uin(ans, { max(tmp, q - tmp), a });
			tmp = b * p % q;
			if (tmp < 0) tmp += q;
			uin(ans, { max(tmp, q - tmp), b >= a ? b : b + q });
			int x, y;
			gcdex(p, q, x, y);
			x = (x % q + q) % q;
			int lt = max(0ll, (q - T2) / 2), rt = min(q - 1, (q + T2) / 2);
			for (int i = lt; i <= rt; ++i) {
				int j = i * x % q;
				if (j < 0) j += q;
				if ((a <= j && j <= b) || (a > b && !(b < j && j < a)))
					uin(ans, { max(i, q - i), j >= a ? j : j + q });
			}
		}
		cout << ans.y + w << el;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}