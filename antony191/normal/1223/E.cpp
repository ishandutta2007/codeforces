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

#define int ll
const int maxn = 500'000;
vector<pair<int, int>> g[maxn];
int n, k;
vector<int> d, dn;
void dfs(int v, int p = -1) {
	int cnt = 0;
	for (auto to : g[v]) {
		if (to.x != p) {
			dfs(to.x, v); cnt++;
			d[v] += d[to.x];
			dn[v] += d[to.x];
		}
	}
	if (!cnt) {
		dn[v] = d[v] = 0;
		return;
	}
	vector<int> add;
	for (auto to : g[v]) {
		if (to.x != p)
			add.push_back(dn[to.x] + to.y - d[to.x]);
	}
	sort(all(add)); reverse(all(add));
	forn(i, min((int)add.size(), k)) {
		d[v] += max(add[i], 0ll);
		if (i < k - 1) dn[v] += max(add[i], 0ll);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	while (q--) {
		cin >> n >> k;
		forn(i, n - 1) {
			int u, v, w;
			cin >> u >> v >> w;
			v--; u--;
			g[v].emplace_back(u, w);
			g[u].emplace_back(v, w);
		}
		d.assign(n, 0);
		dn.assign(n, 0);
		dfs(0);
		cout << max(d[0], dn[0]) << el;
		forn(i, n) {
			g[i].clear();
			g[i].shrink_to_fit();
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}