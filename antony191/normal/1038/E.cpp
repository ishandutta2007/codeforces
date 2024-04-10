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

vector<int> g[4][4], used;
int cnt = 0;
void dfs(int v) {
	used[v] = 1;
	forn(i, 4) {
		if (v <= i) {
			for (auto to : g[v][i]) cnt += to;
		}
		if (used[i] || g[v][i].empty()) continue;
		dfs(i);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> st(4);
	forn(i, n) {
		int v, u, w;
		cin >> v >> w >> u;
		v--; u--;
		st[v]++; st[u]++;
		g[v][u].push_back(w);
		if (v != u) g[u][v].push_back(w);
	}
	forn(i, 4) forn(j, 4) {
		sort(all(g[i][j]));
		reverse(all(g[i][j]));
	}
	int ans = 0;
	forn(i, 4)
		forn(j, i) {
		if (g[i][j].empty()) continue;
		auto tmp = g[i][j].back();
		g[i][j].pop_back();
		g[j][i].pop_back();
		used.assign(4, 0);
		cnt = 0;
		forn(k, 4) {
			if (!used[k]) {
				dfs(k);
				uax(ans, cnt);
				cnt = 0;
			}
		}
		g[i][j].push_back(tmp);
		g[j][i].push_back(tmp);
	}
	used.assign(4, 0); cnt = 0;
	dfs(0);
	if (!((st[0] & 1) && (st[1] & 1) && (st[2] & 1)) || !(used[0] && used[1] && used[2] && used[3])) {
		uax(ans, cnt); cnt = 0;
		forn(k, 4) {
			if (!used[k]) {
				dfs(k);
				uax(ans, cnt);
				cnt = 0;
			}
		}
	}
	cout << ans;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}