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

const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007ll;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << '\n'; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> x(n), y(n);
	vector<pair<int, int>> r(n);
	vector<ll> ans(n);
	forn(i, n) cin >> x[i] >> y[i], r[i] = { y[i] - x[i], i };
	sort(all(r));
	vector<ll> pref(n + 1);
	forn(i, n) pref[i + 1] = pref[i] + y[r[i].second] * 1ll;
	vector<ll> suf(n + 1);
	for (int i = n - 1; i + 1; --i) suf[i] = suf[i + 1] + x[r[i].second] * 1ll;
	forn(i, n) {
		ans[r[i].second] += i * 1ll * x[r[i].second];
		ans[r[i].second] += (n - i - 1) * 1ll * y[r[i].second];
		ans[r[i].second] += pref[i] + suf[i + 1];
	}
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		int tmp = min(x[v] + y[u], y[v] + x[u]);
		ans[v] -= tmp;
		ans[u] -= tmp;
	}
	output(ans);
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}