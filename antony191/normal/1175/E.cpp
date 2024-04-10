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
const ll llinf = 1e18, mod = 1000'000'007ll;
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

const int maxn = 2e5;
int p[maxn][20];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> b(n), a;
	forn(i, n) {
		cin >> b[i].x >> b[i].y;
	}
	sort(all(b));
	forn(i, n) {
		if (!i) a.push_back(b[i]);
		else {
			if (a.back().x == b[i].x) a.pop_back();
			if (a.empty() || a.back().y < b[i].y) a.push_back(b[i]);
		}
	}
	n = (int)a.size();
	forn(i, 20) p[n - 1][i] = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		int j = lower_bound(all(a), pair<int, int>{ a[i].y + 1, 0 }) - a.begin() - 1;
		p[i][0] = j;
		firn(j, 20)
			p[i][j] = p[p[i][j - 1]][j - 1];
	}
	forn(i, m) {
		int l, r;
		cin >> l >> r;
		int j = lower_bound(all(a), pair<int, int>{ l + 1, 0 }) - a.begin() - 1;
		if (j < 0) {
			cout << -1 << el;
			continue;
		}
		int v = j;
		int ans = 1;
		for (int k = 19; k >= 0; --k) {
			if (a[p[v][k]].y < r) {
				v = p[v][k];
				ans += (1 << k);
			}
		}
		if (a[v].y < r)
			v = p[v][0], ans++;
		if (a[v].y < r) cout << -1 << el;
		else {
			cout << ans << el;
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}