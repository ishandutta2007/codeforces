#include<bits/stdc++.h>
using namespace std;

int n, m;
string s[2005];

int f[2][2005][2005], pref[2][2005][2005];
vector<int> r[2005], c[2005];

const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = " " + s[i];
	}
	if (m== 1&& n == 1) return cout << 1, 0;
	for (int i = 1; i <= n; i++) {
		r[i].resize(m + 2);
		r[i][0] = -1e9;
		for (int j = m; j >= 1; j--) {
			r[i][j] = r[i][j + 1] - (s[i][j] == 'R');
		} 
		//r[i].resize(m + 1);
	}
	for (int j = 1; j <= m; j++) {
		c[j].resize(n + 2);
		c[j][0] = -1e9;
		for (int i = n; i >= 1; i--) {
			c[j][i] = c[j][i + 1] - (s[i][j] == 'R');
		}
		//c[j].resize(n + 1);
	}
	f[0][1][1] = 1;
	f[1][1][1] = 1;
	pref[0][1][1] = 1;
	pref[1][1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			int nRock = j - m - 1;
			int k = upper_bound(r[i].begin(), r[i].end(), nRock) - r[i].begin() - 1;
			//cout << k << endl;
			//cout << i << ' ' << j << ' ' << k << endl;
			//cout << k << endl;
			if (k >= j) f[0][i][j] = 0;
			else {
				 f[0][i][j] = (pref[1][i][j - 1] - pref[1][i][max(k - 1, 0)] + MOD) % MOD;
			}
			nRock = i - n - 1;
			k = upper_bound(c[j].begin(), c[j].end(), nRock) - c[j].begin() - 1;
			//cout << i << ' ' << j << ' ' << k << endl;
			if (k >= i) f[1][i][j] = 0;
			else {
				f[1][i][j] = (pref[0][i - 1][j] - pref[0][max(k - 1, 0)][j] + MOD) % MOD;
				//if (i == 4 && j == 3) cout << pref[0][3][3] << ' ' << k << ' ' << pref[]
			}
			pref[0][i][j] = (pref[0][i - 1][j] + f[0][i][j]) % MOD;
			pref[1][i][j] = (pref[1][i][j - 1] + f[1][i][j]) % MOD; 
			//cout << i << ' ' << j << ' ' << f[0][i][j] << ' ' << f[1][i][j] << endl;
		}
	}
	cout << (f[0][n][m] + f[1][n][m]) % MOD;
	return 0;
}