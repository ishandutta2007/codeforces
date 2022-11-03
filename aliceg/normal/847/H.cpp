#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <functional>
#include <limits>

#define pb push_back
#define mp make_pair
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define forv(i, n) for (int i = 0; i < n; i++)
#define vi vector <int>
#define ll long long
#define uns unsigned
#define endl '\n'

#pragma warning (disable : 4996)

using namespace std;

const int N = 1e5 + 10;
const ll INF = LLONG_MAX;
int n, a[N], m;
pair <ll, int> dp[N], dp1[N];

int main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	fori(n) scanf("%d", &a[i]);
	dp[0] = mp(0ll, a[0]);
	dp1[n - 1] = mp(0ll, a[n - 1]);
	for (int i = 1; i < n; i++) {
		m = max(0, dp[i - 1].second - a[i] + 1);
		dp[i] = mp(dp[i - 1].first + m, a[i] + m);
	}
	for (int i = n - 2; i >= 0; i--) {
		m = max(0, dp1[i + 1].second - a[i] + 1);
		dp1[i] = mp(dp1[i + 1].first + m, a[i] + m);
	}
	ll res = INF;
	for (int i = 1; i < n - 1; i++) {
		res = min(res, dp[i - 1].first + dp1[i + 1].first + max(dp[i].second, dp1[i].second) - a[i]);
	}
	res = min(res, dp1[0].first);
	res = min(res, dp[n - 1].first);
	cout << res;
	return 0;
}