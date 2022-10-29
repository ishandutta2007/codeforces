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
const ll llinf = 3e18, mod = 1000'000'007;
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
const int maxn = 200'000;

vector<int> g[maxn], a;
map<int, int> fir[maxn], sec[maxn];
int ans = 0;
void dfs(int v, int p = 0) {
	vector<int> pr;
	int t = a[v];
	for (int i = 2; i * i <= t; i++) {
		if (t % i) continue;
		pr.push_back(i);
		while (!(t % i)) t /= i;
	}
	if (t > 1) pr.push_back(t);
	for (auto to : g[v])
		if (to != p) dfs(to, v);
	for (auto i : pr) {
		fir[v][i] = sec[v][i] = 1;
		for (auto to : g[v]) {
			if (to == p) continue;
			if (fir[to][i] >= fir[v][i]) {
				sec[v][i] = fir[v][i];
				fir[v][i] = fir[to][i] + 1;
			}
			else if (fir[to][i] >= sec[v][i]) {
				sec[v][i] = fir[to][i] + 1;
			}
		}
		uax(ans, fir[v][i] + sec[v][i] - 1);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	a.resize(n);
	forn(i, n) cin >> a[i];
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);
	cout << ans << el;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}