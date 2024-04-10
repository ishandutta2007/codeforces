#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
vector<map<int, int> > dp;
vector<vector<int> > g;
vector<vector<int> > s;
int res = 0;
vector<int> pa;
int dfs(int a, int p) {
	pa[a] = p;
	for (int i : g[a]) {
		if (i != p) {
			dfs(i, a);
		}
	}
}
int solve(int a, int p, int d) {
	bool ok = false;
	for (int i : s[a]) {
		if (i == d)ok = true;
	}
	if (!ok) {
		return 0;
	}
	if (dp[a].count(d) == 0) {
		int mx1 = 0;
		int mx2 = 0;
		for (int i : g[a]) {
			if (i != p) {
				int t = solve(i, a, d);
				if (mx1 < t) {
					mx2 = mx1;
					mx1 = t;
				}
				else if (mx2 < t) {
					mx2 = t;
				}
			}
		}
		res = max(res, mx1 + mx2 + 1);
		dp[a][d] = mx1 + 1;
	}
	return dp[a][d];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	dp.resize(N);
	g.resize(N);
	s.resize(N);
	pa.resize(N);
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		int t = A[i];
		for (int j = 2; j*j <= t; j++) {
			if (t % j == 0) {
				t /= j;
				s[i].push_back(j);
				while (t%j == 0)t /= j;
			}
		}
		if (t > 1) {
			s[i].push_back(t);
		}
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1);
	for (int j = 0; j < N; j++) {
		for (int i : s[j]) {
			solve(j, pa[j], i);
		}
	}
	cout << res << endl;
}