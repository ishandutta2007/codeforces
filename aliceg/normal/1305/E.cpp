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
//#define int ll

#ifndef LOCALFILE
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

const ld EPS = 1e-6;
const int N = (int)1e6 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	int n, m;
	cin >> n >> m;
	if (n == 1) {
		if (m == 0)
			cout << 1;
		else
			cout << -1;
		return 0;
	}
	vector<int> a(n);
	a[0] = 1; a[1] = 2;
	int cnt = 0;
	int maxx = 3;
	for (int i = 2; i < n; ++i) {
		if (cnt + i / 2 <= m) {
			cnt += i / 2;
			a[i] = i + 1;
			maxx = a[i] + 1;
			continue;
		}
		if (m != cnt) {
			int x = m - cnt;
			a[i] = a[i - 1] + a[i - x * 2];
			cnt = m;
			maxx = a[i] + 1;
		}
		else
			a[i] = (int)1e9 - (n - i - 1) * maxx;
	}
	if (cnt != m)
		cout << -1;
	else {
		for (int i = 0; i < n; ++i)
			cout << a[i] << ' ';
	}

	return 0;
}