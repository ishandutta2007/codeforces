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
#define int ll

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

void solve() {
	int n;
	cin >> n;
	int m = n + 1, x = 0;
	vi sum(n + 2);
	for (int i = 1;; ++i) {
		sum[i] = sum[i - 1] + 2 * i - 1;
		if (sum[i] > n)
			break;
		if (sum[i] % 2 != n % 2)
			continue;
		int p = i + ((n - sum[i]) / 2 + i - 1) / i;
		if (p < m) {
			m = p;
			x = i;
		}
	}
	if (x == 0) {
		cout << -1;
		return;
	}
	vector<vc> a(m, vc(m, '.'));
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < x; ++j) {
			a[m - i - 1][j] = 'o';
		}
	}
	for (int i = x; i < m - 1; ++i) {
		for (int j = 0; j < x; ++j)
			a[m - i - 1][j] = a[m - j - 1][i] = 'o';
	}
	int c = (n - sum[x]) / 2 % x;
	if (!c) c = x;
	for (int i = 0; i < c; ++i)
		a[0][i] = a[m - i - 1][m - 1] = 'o';

	cout << m << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j)
			cout << a[i][j];
		cout << endl;
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