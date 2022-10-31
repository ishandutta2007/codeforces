#include <bits/stdc++.h>
using namespace std;
signed main() {
	string s;
	cin >> s;
	vector<vector<int> > cnt;
	vector<vector<int> > dp;
	int n = s.size();
	cnt.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		cnt[i].resize(n, 0);
		dp[i].resize(n, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i] == s[j]) {
				cnt[i][j] = 1;
			}
		}
	}
	
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			if (cnt[i][j] > 0) {
				cnt[i][j] += cnt[i + 1][j + 1];
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << cnt[i][j] << " ";
		}
		cout << endl;
	}
	*/
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}
	int k;
	int l;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			k = j + (i + 2) / 2;
			l = (i + 1) / 2;
			if (dp[j][j + l - 1] == dp[k][k + l - 1]) {
				if (dp[k][k + l - 1] > 0) {
					if (cnt[j][k] >= l) {
						dp[j][i + j] = dp[j][j + l - 1] + 1;
					}
				}
			}
			if (dp[j][i + j] == 0) {
				if (i <= 1 || (dp[j + 1][j + i - 1] != 0)) {
					if (s[j] == s[i + j]) {
						dp[j][i + j] = 1;
					}
				}

			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/
	//cerr << "A" << endl;
	vector<int> res(n + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			res[dp[j][i + j]] += 1;
			//cerr << dp[i][i + j]<<" " ;
			//for(int x=i)
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		res[i] += res[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1)cout << " ";
		cout << res[i];
	}
	cout << endl;
	return 0;
}