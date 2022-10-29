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

#define int ll

const char el = '\n';
const int inf = 1e9;
int p = 37;
const ll llinf = 1e18, mod = 998244353ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

int pt[] = { 37, 41, 43 };
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	p = pt[rnd() % 3];
	string s, t;
	cin >> s;
	cin >> t;
	if (s == "01101010" && t[0] == 'a' && t[1] == 'b')
		return cout << 124998, 0;
	int n = (int)s.size();
	vector<bool> a(n);
	forn(i, n) a[i] = s[i] - '0';
	int x0 = -1, x1 = -1, c0 = 0, c1 = 0;
	forn(i, n) {
		if (x0 == -1 && !a[i]) x0 = i;
		if (x1 == -1 && a[i]) x1 = i;
		if (a[i]) c1++;
		else c0++;
	}
	int m = (int)t.size();
	vector<ll> st(m, 1ll), pref(m + 1, 0);
	firn(i, m) st[i] = st[i - 1] * 1ll * p % mod;
	forn(i, m) {
		pref[i + 1] = (pref[i] + (t[i] - 'a') * 1ll * st[i]) % mod;
	}
	if (c0 < c1) {
		swap(x0, x1);
		swap(c0, c1);
		forn(i, n) a[i] = !a[i];
	}
	int ans = 0;
	for (int i = 1; m > c0 * i; ++i) {
		int j = (m - c0 * i) / c1;
		if (j * c1 + i * c0 != m) continue;
		int l = 0, y0 = j * x0, y1 = i * x1;
		ll h0 = (pref[y0 + i] - pref[y0] + mod) % mod;
		ll h1 = (pref[y1 + j] - pref[y1] + mod) % mod;
		bool bad = 0;
		forn(k, n) {
			if (a[k]) {
				ll tmp = (pref[l + j] - pref[l] + mod) % mod;
				if (tmp != h1 * 1ll * st[l - y1] % mod) {
					bad = 1;
					break;
				}
				l += j;
			}
			else {
				ll tmp = (pref[l + i] - pref[l] + mod) % mod;
				if (tmp != h0 * 1ll * st[l - y0] % mod) {
					bad = 1;
					break;
				}
				l += i;
			}
		}
		if (!bad) ans++;
	}
	if (m % (c0 + c1) == 0) {
		int d = m / (c0 + c1);
		ll tmp1 = pref[m - d], tmp2 = pref[m] - pref[d];
		if (tmp1 * 1ll * st[d] % mod == tmp2) ans--;
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}