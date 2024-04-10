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
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		vector<int> x(n), y(n);
		for (int j = 0; j < n; ++j)
			cin >> x[j] >> y[j];
		int ans = -1;
		for (int j = 0; j < n; ++j) {
			bool flag = 1;
			for (int j1 = 0; j1 < n; ++j1) {
				if (abs(x[j] - x[j1]) + abs(y[j] - y[j1]) > k) {
					flag = 0;
					break;
				}
			}
			if (flag)
				ans = 1;
		}
		cout << ans << endl;
	}

	return 0;
}