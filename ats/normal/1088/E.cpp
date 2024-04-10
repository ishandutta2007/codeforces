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
vector<vector<int> > g;
vector<int> A;
vector<int> dp;
vector<int> V;
int dfs(int a, int p) {
	dp[a] = A[a];
	for (int k : g[a]) {
		if (k != p) {
			dp[a] += max((int)0, dfs(k, a));
		}
	}
	return dp[a];
}
int mx;
int C;
int dfs2(int a, int p) {

	int t = A[a];
	for (int k : g[a]) {
		if (k != p) {
			t += max((int)0, dfs2(k, a));
		}
	}
	if (t == mx) {
		C++;
		t = 0;
	}
	return t;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	A.resize(N);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int a, b;
	g.resize(N);
	dp.resize(N);
	V.resize(N, 0);
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0, -1);


	mx = -((int)1 << 40);
	for (int i = 0; i < N; i++) {
		if (mx < dp[i]) {
			mx = dp[i];
		}
	}
	if (mx == 0) {
		C = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] == 0)C++;
		}
	}
	else {
		if (mx > 0) {
			C = 0;
			dfs2(0, -1);
		}
		else {
			for (int i = 0; i < N; i++) {
				if (mx == dp[i]) {
					C++;
				}
			}
		}
	}
	cout << C*mx << " " << C << endl;
}