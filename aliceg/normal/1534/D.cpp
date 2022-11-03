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
	int n;
	cin >> n;
	cout << "? " << 1 << endl;
	vi d1(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> d1[i];
		if (d1[i] % 2)
			++cnt;
	}
	vii ans;
	if (cnt >= n - cnt) {
		for (int i = 0; i < n; ++i) {
			if (d1[i] == 1)
				ans.push_back({ 0, i });
			if (d1[i] % 2 == 0 && i != 0) {
				cout << "? " << i + 1 << endl;
				for (int j = 0; j < n; ++j) {
					int x;
					cin >> x;
					if (x == 1)
						ans.push_back({ i, j });
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			if (d1[i] % 2) {
				cout << "? " << i + 1 << endl;
				for (int j = 0; j < n; ++j) {
					int x; 
					cin >> x;
					if (x == 1)
						ans.push_back({ i, j });
				}
			}
		}
	}
	cout << "!" << endl;
	for (int i = 0; i < n - 1; ++i)
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;

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