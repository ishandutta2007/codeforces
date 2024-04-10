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
#include <numeric>
#include <functional>
#include <limits>
#include <ctime>
#include <random>
#include <bitset>
#include <numeric>
#include <complex>
#include <stdlib.h>
#include <cassert>

#define mp make_pair
//#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
//#define int ll

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
#pragma optimize("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const ld PI = 3.141592653589793;
const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

void solve() {
	
	int n, k;
	cin >> n >> k;
	if (n % 2 && k % 2 == 0) {
		cout << -1 << endl;
		return;
	}
	int x = (n + k - 1) / k;
	if (x * k % 2 != n % 2)
		++x;
	while ((x - 1) / 2 * n < (x * k - n) / 2) {
		++x;
		if (x * k % 2 != n % 2)
			++x;
	}
	vi c(n, 1);
	int p = (x * k - n) / 2;
	for (int i = 0; i < n; ++i)
		c[i] += p / n * 2;
	for (int i = 0; i < p % n; ++i)
		c[i] += 2;
	for (int i = 0; i < n; ++i) {
		if (c[i] > x)
			exit(1);
	}
	int cur = 0, cnt = 0;
	vvi a(x, vi(k));
	for (int j = 0; j < k; ++j) {
		for (int i = 0; i < x; ++i) {
			a[i][j] = cur + 1;
			++cnt;
			if (cnt == c[cur]) {
				++cur;
				cnt = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < x; ++i) {
		cout << "?";
		for (int j = 0; j < k; ++j) {
			cout << ' ' << a[i][j];
		}
		cout << endl;
		int p;
		cin >> p;
		ans = (ans ^ p);
	}
	cout << "! " << ans << endl;

	return;
}

signed main() {
#ifdef LOCAL
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
#endif
	IOboost;
	
	/*int t;
	cin >> t;
	for (int i = 0; i < t; ++i)*/
		solve();

	return 0;
}