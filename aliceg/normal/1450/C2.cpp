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
#include <random>
#include <bitset>
#include <numeric>
#include <complex>

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int ll

//#ifndef LOCALFILE
//#define _getchar_nolock getchar_unlocked
//#define _putchar_nolock putchar_unlocked
//#endif

#pragma warning(disable : 4996)
#pragma optimize("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld PI = 3.141592653589793;
const ld EPS = 1e-8;
const int N = (int)1e2 + 10;
const int INF = (int)1e14 + 10;
const int MOD = (int)1e9 + 7;

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	int t;
	cin >> t;
	for (int j1 = 0; j1 < t; ++j1) {
		int n;
		cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		if (n <= 2) {
			for (int i = 0; i < n; ++i)
				cout << a[i] << endl;
			continue;
		}
		int k = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] != '.')
					++k;
			}
		}
		for (int i = 0; i < 3; ++i) {
			vector<string> ans = a;
			int cnt = 0;
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < n; ++y) {
					if ((x + y) % 3 == i && ans[x][y] == 'X') {
						ans[x][y] = 'O';
						++cnt;
					}
					if ((x + y) % 3 == (i + 1) % 3 && ans[x][y] == 'O') {
						ans[x][y] = 'X';
						++cnt;
					}
				}
			}
			if (cnt <= k / 3) {
				for (int x = 0; x < n; ++x)
					cout << ans[x] << endl;
				break;
			}
		}
	}

	return 0;
}