#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

int n, m, k;
vector<vi> a, p, dp, pref, suf;

int get(int i, int l, int r) {
	return (p[i][r] - (l ? p[i][l - 1] : 0));
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	a.resize(n + 1, vi(m));
	p.resize(n + 1, vi(m));
	dp.resize(n + 1, vi(m));
	pref.resize(n + 1, vi(m));
	suf.resize(n + 1, vi(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			p[i][j] = a[i][j] + (j > 0 ? p[i][j - 1] : 0);
		}
	}
	for (int j = k - 1; j < m; j++) {
		dp[1][j] = get(0, j - k + 1, j) + get(1, j - k + 1, j);
	}
	for (int i = 2; i < n + 1; i++) {
		for (int j = 0; j < m; j++) {
			pref[i - 1][j] = max(dp[i - 1][j], (j > 0 ? pref[i - 1][j - 1] : 0));
		}
		for (int j = m - 1; j >= 0; j--) {
			suf[i - 1][j] = max(dp[i - 1][j], (j < m - 1 ? suf[i - 1][j + 1] : 0));
		}
		for (int j = k - 1; j < m; j++) {
			int add = get(i, j - k + 1, j) + get(i - 1, j - k + 1, j);
			if (j - k >= 0) {
				dp[i][j] = max(dp[i][j], pref[i - 1][j - k] + add);
			}
			if (j + k < m) {
				dp[i][j] = max(dp[i][j], suf[i - 1][j + k] + add);
			}
			for (int jj = j - k + 1; jj < j + k; jj++) {
				if (jj < 0 || jj >= m) continue;
				int l = max(j - k + 1, jj - k + 1);
				int r = min(j, jj);
				dp[i][j] = max(dp[i][j], dp[i - 1][jj] + add - get(i - 1, l, r));
			}
		}
	}
	cout << *max_element(all(dp[n]));
}