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

vector<int> g[1000], used;
int k = -1;
void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v]) {
		if (used[to]) {
			if (used[to] == 2) k = to;
		}
		else dfs(to);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		forn(i, n - 1) {
			int v, u;
			cin >> v >> u;
			v--; u--;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		used.assign(n, 0);
		int k1;
		cin >> k1;
		forn(i, k1) {
			int v;
			cin >> v;
			used[v - 1] = 2;
		}
		int k2;
		cin >> k2;
		vector<int> b(k2);
		forn(i, k2) {
			cin >> b[i];
			b[i]--;
		}
		cout << "B " << b[0] + 1 << endl;
		int v;
		cin >> v;
		v--;
		if (used[v] == 2) {
			cout << "C " << v + 1 << endl;
		}
		else {
			dfs(v);
			cout << "A " << k + 1 << endl;
			int u;
			cin >> u;
			u--;
			bool ok = 0;
			forn(i, k2)
				if (b[i] == u) ok = 1;
			if (ok) cout << "C " << k + 1 << endl;
			else cout << "C -1" << endl;
		}
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