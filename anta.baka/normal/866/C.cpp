#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int n, r, f[50], s[50];
ld p[50], dp[50][5001];

int main() {
	cin >> n >> r;
	for(int i = 0; i < n; i++) {
		cin >> f[i] >> s[i] >> p[i];
		p[i] *= 0.01;
	}
	ld bl = 0, br = 1e15;
	for(int cc = 0; cc < 120; cc++) {
		ld bm = 0.5 * (bl + br);
		auto get = [&](int i, int j) {
			if(i == n) return j <= r ? 0 : bm;
			return j <= r ? dp[i][j] : bm;
		};
		for(int i = n - 1; i >= 0; i--)
			for(int j = 0; j <= r; j++) {
				dp[i][j] = (get(i + 1, j + f[i]) + f[i]) * p[i] + (get(i + 1, j + s[i]) + s[i]) * (1 - p[i]);
				if(i != 0) dp[i][j] = min(dp[i][j], bm);
			}
		if(dp[0][0] > bm) bl = bm;
		else br = bm;
	}
	cout.precision(15);
	cout << fixed << bl;
}