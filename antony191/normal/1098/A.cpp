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
const int inf = 2e9;
const ll llinf = 1e18, mod = 1000'000'007;
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

vector<int> g[100000], p, s, h, a;
bool k = 1;
void dfs(int v) {
	if (v == 0) {
		a[v] = s[v];
	}
	else {
		if (h[v] & 1) {
			int mn = inf;
			for (auto to : g[v]) uin(mn, s[to]);
			if (mn == inf) mn = s[p[v]];
			if (mn < s[p[v]]) k = 0;
			a[v] = mn - s[p[v]];
			s[v] = s[p[v]] + a[v];
		}
		else {
			a[v] = s[v] - s[p[v]];
		}
	}
	for (auto to : g[v])
		dfs(to);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	p.resize(n); s.resize(n); h.resize(n); a.resize(n);
	h[0] = 0;
	firn(i, n) {
		int v;
		cin >> v;
		v--;
		p[i] = v;
		g[v].push_back(i);
		h[i] = h[v] + 1;
	}
	forn(i, n) cin >> s[i];
	dfs(0);
	ll sum = 0;
	forn(i, n) sum += a[i] * 1ll;
	cout << (k ? sum : -1);
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}