#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <limits>
#include <ctime>
#include <cassert>

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n;
#define fi(n) for (int i = 0; i < n; ++i)
#define fie(n) for (int i = 1; i <= n; ++i)
#define fir(l, r) for (int i = (l); i <= (r); ++i)
#define fj(n) for (int j = 0; j < n; ++j)
#define fje(n) for (int j = 1; j <= n; ++j)
#define fjr(l, r) for (int j = (l); j <= (r); ++j)
#define fv(i, n) for (int i = 0; i < n; ++i)
#define fve(i, n) for (int i = 1; i <= n; ++i)
#define fvr(j, l, r) for (int j = (l); j <= (r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%lld", &n)
#define endl '\n'
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define fll(x, a) memset(x, a, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#ifndef _getchar_nolock
#define _putchar_nolock putchar_unlocked
#define _getchar_nolock getchar_unlocked
#endif
//#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:536870912")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;

const ld EPS = 1e-8;
const int INF = (int)1e11 + 10;
const int MOD = (int)1e9 + 7;
const int N = (int)2e3 + 10;

int dfs(int v, vvi & a, vc & used, int p = -1) {
	used[v] = 1;
	for (int u : a[v]) {
		if (used[u] && u != p)
			return 1;
		if (u == p)
			continue;
		dfs(u, a, used, v);
	}
	return 0;
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(t);
	for (int j1 = 0; j1 < t; ++j1) {
		int n, m;
		cin >> n >> m;
		int cnt = 0;
		vvi a(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			--x; --y;
			if (x != y) {
				a[x].push_back(y);
				a[y].push_back(x);
				++cnt;
			}
		}
		vc used(n);
		for (int i = 0; i < n; ++i) {
			if (!used[i] && dfs(i, a, used))
				++cnt;
		}
		cout << cnt << endl;
	}

	return 0;
}