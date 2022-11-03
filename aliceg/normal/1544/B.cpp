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

	int h, w;
	cin >> h >> w;
	vector<string> ans(h);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j)
			ans[i] += '0';
	}
	ans[0][0] = ans[h - 1][0] = ans[0][w - 1] = ans[h - 1][w - 1] = '1';
	for (int i = 2; i < h - 2; i += 2)
		ans[i][0] = ans[i][w - 1] = '1';
	for (int j = 2; j < w - 2; j += 2)
		ans[0][j] = ans[h - 1][j] = '1';
	for (int i = 0; i < h; ++i)
		cout << ans[i] << endl;

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