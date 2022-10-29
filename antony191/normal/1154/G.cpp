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
const ll llinf = 3e18, mod = 1000'000'007, maxn = 1e5;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
//#define int ll

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

const int MAX = 10'000'001;
int sum[MAX];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> b(n);
	forn(i, n) {
		int a;
		cin >> a;
		b[i] = a;
		sum[a]++;
	}
	ll ans = llinf, x, y;
	firn(i, MAX) {
		int cnt = 0, xx = -1, yy = -1;
		ll tmp = 1ll;
		for (int j = i; j < MAX; j += i)
			if (sum[j]) {
				tmp *= 1ll * j;
				if (!cnt) xx = j;
				else yy = j;
				if (sum[j] > 1 && !cnt) tmp *= 1ll * j, yy = j;
				cnt += sum[j];
				if (cnt > 1) break;
			}
		tmp /= i;
		if (cnt > 1 && uin(ans, tmp)) {
			x = xx; y = yy;
		}
	}
	int l = -1, r = -1;
	forn(i, n) {
		if (r == -1 && b[i] == y && (l >= 0 || x != y)) r = i;
		if (l == -1 && b[i] == x) l = i;
	}
	if (l > r) swap(l, r);
	cout << l + 1 << ' ' << r + 1 << el;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}