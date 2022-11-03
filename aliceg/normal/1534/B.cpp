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
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int ll

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
	int n;
	cin >> n;
	vi a(n + 2);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			ans += a[i] - max(a[i - 1], a[i + 1]);
			a[i] = max(a[i - 1], a[i + 1]);
		}
		ans += abs(a[i] - a[i - 1]);
	}
	ans += a[n];
	cout << ans << endl;
	return;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;
	
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();

	return 0;
}