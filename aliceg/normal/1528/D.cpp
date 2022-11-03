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
#define endl '\n'
#define sqr(x) ((x) * (x))
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
const int N = (int)5e5 + 10;
const int INF = (int)2e9;
const int MOD = 998244353;

int input() {
	char c = ' ';
	int x = 0;
	while (!isdigit(c))
		c = _getchar_nolock();
	while (isdigit(c)) {
		x = x * 10 + (c - '0');
		c = _getchar_nolock();
	}
	return x;
}

void print(int x) {
	for (char c : to_string(x))
		_putchar_nolock(c);
	return;
}

void solve() {
	int n = input(), m = input();
	vector<vii> a(n);
	for (int i = 0; i < m; ++i) {
		int u = input(), v = input(), c = input();
		a[u].pb({ v, c });
	}
	for (int s = 0; s < n; ++s) {
		vi d(n, INF);
		d[s] = 0;
		vc g(n, 1);
		while (true) {
			int v = -1;
			for (int i = 0; i < n; ++i) {
				if (g[i] && (v == -1 || d[i] < d[v]))
					v = i;
			}
			if (v == -1)
				break;
			g[v] = 0;
			int k = a[v].size();
			vi b(n, INF);
			for (int i = 0; i < k; ++i)
				b[(a[v][i].first + d[v]) % n] = a[v][i].second;
			int minn = INF;
			for (int i = 0; i < n; ++i) {
				b[i] = b[i] + n - i;
				minn = min(minn, b[i]);
			}
			int r = 0;
			for (int u = 0; u < n; ++u) {
				b[u] -= n;
				minn = min(minn, b[u]);
				d[u] = min(d[u], d[v] + minn + u);
			}
		}
		for (int i = 0; i < n; ++i) {
			print(d[i]);
			_putchar_nolock(' ');
		}
		_putchar_nolock(endl);
	}

	return;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	solve();

	return 0;
}