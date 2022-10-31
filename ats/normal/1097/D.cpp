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
int powm(int n, int a) {
	int res = 1, exp = n;
	for (; a; a /= 2) {
		if (a & 1) res = res * exp % MOD;
		exp = exp * exp % MOD;
	}
	return res;
}
int inv(int n) { return powm(n, MOD - 2); }

bool solve2(int N, int K) {
	//cin >> N >> K;
	set<int> st;
	for (int i = 1; i*i <= N; i++) {
		if (N % i == 0) {
			st.insert(i);
			st.insert(N / i);
		}
	}
	//cerr << st.size() << endl;
	if (st.size() > 100)return false;

	vector<int> X;
	for (int s : st) {
		X.push_back(s);
	}

	vector<vector<int> > g(X.size());
	for (int i = 0; i < X.size(); i++) {
		for (int j = 0; j <= i; j++) {
			if (X[i] % X[j] == 0) {
				g[i].push_back(j);
			}
		}
	}
	vector<int> I(X.size());
	for (int i = 0; i < I.size(); i++) {
		I[i] = inv((int)g[i].size());
	}

	vector<int> dp(X.size(), 0);
	vector<int> ndp(X.size());
	dp.back() = 1;
	for (int i = 0; i < K; i++) {
		ndp.clear();
		ndp.resize(X.size(), 0);
		for (int j = 0; j < X.size(); j++) {
			for (int k : g[j]) {
				ndp[k] = (ndp[k] + dp[j] * I[j]) % MOD;
			}
			//cerr << g[j].size() << " " <<  inv((int)g[j].size()) << endl;
		}
		swap(dp, ndp);
	}
	int res = 0;
	for (int i = 0; i < dp.size(); i++) {
		//cerr << dp[i] << " ";
		res = (res + (X[i] % MOD) * dp[i]) % MOD;
	}
	//cerr << endl;

	cout << res << endl;
	return true;
}
int iv[60];
int dp[52][52][10002];
int solve(int from, int to, int k) {
	if (k == 0) {
		if (from == to)return 1;
		else return 0;
	}
	if (dp[from][to][k] == -1) {
		int res = 0;
		for (int i = from; i >= to; i--) {
			res = (res + iv[from + 1] * solve(i, to, k - 1)) % MOD;
		}
		dp[from][to][k] = res;
	}
	return dp[from][to][k];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	if (solve2(N, K))return 0;
	//cerr << ((int)1 << 49) << endl;
	set<int> st;
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < 10002; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	vector<pair<int, int> >vp;
	for (int i = 2; i*i <= N; i++) {
		if (N % i == 0) {
			int c = 1;
			N /= i;
			while (N % i == 0) {
				c++;
				N /= i;
			}
			vp.emplace_back(i, c);
		}
	}
	if (N > 1) {
		vp.emplace_back(N, 1);
	}

	for (int i = 1; i < 60; i++) {
		iv[i] = inv(i);
	}

	int res = 1;
	for (int i = 0; i < vp.size(); i++) {
		//cerr << vp[i].first << " " << vp[i].second << endl;
		int a = 1;
		int ans = 0;
		for (int j = 0; j <= vp[i].second; j++) {

			ans = (ans + (a % MOD) * solve(vp[i].second, j, K)) % MOD;
			a *= vp[i].first;
		}
		res = (res * ans) % MOD;
	}
	cout << res << endl;
}