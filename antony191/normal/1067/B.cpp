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

vector<int> g[100000], d, p;
vector<bool> used;

void dfs(int v) {
	used[v] = 1;
	for (auto to : g[v]) {
		if (!used[to]) {
			d[to] = d[v] + 1;
			p[to] = v;
			dfs(to);
		}
	}
}

bool check(int v, int k) {
	used[v] = 1;
	int cnt = 0;
	for (auto to : g[v])
		if (!used[to]) {
			if (k == 0) return false;
			if (!check(to, k - 1)) return false;
			cnt++;
		}
	if (cnt < 3 && k > 0) return false;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	d.resize(n);
	p.resize(n);
	used.assign(n, false);
	dfs(0);
	int mx = 0;
	firn(i, n) if (d[i] > d[mx]) mx = i;
	d.assign(n, false);
	used.assign(n, false);
	p.assign(n, mx);
	dfs(mx);
	int mx1 = 0;
	firn(i, n) if (d[i] > d[mx1]) mx1 = i;
	if (d[mx1] != k + k) return cout << "No", 0;
	int cur = mx1;
	forn(i, k) cur = p[cur];
	used.assign(n, false);
	if (check(cur, k))
		cout << "Yes";
	else
		cout << "No";
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}