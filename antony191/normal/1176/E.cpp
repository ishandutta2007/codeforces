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

const int maxn = 200'000;
vector<int> g[maxn], used, h;
vector<int> c1, c2;
void dfs(int v) {
	used[v] = 1;
	if (h[v] & 1) c1.push_back(v);
	else c2.push_back(v);
	for (auto to : g[v]) {
		if (used[to]) continue;
		h[to] = h[v] + 1;
		dfs(to);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		forn(i, m) {
			int v, u;
			cin >> v >> u;
			v--; u--;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		used.assign(n, 0); h.assign(n, 0);
		dfs(0);
		if (c1.size() > c2.size()) c1.swap(c2);
		cout << (int)c1.size() << el;
		for (auto i : c1) cout << i + 1 << ' ';
		cout << el;
		forn(i, n) {
			g[i].clear(); g[i].shrink_to_fit();
			c1.clear(); c2.clear();
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}