#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

vector <int> vec[10];
string s[N];
int mini[N];
int dp[N][N];
pair <int, int> par[N];
int b[N][15];
bool c[10][10];

int get(string s, int x) {
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1' && !c[x][i]) {
			return -1;
		}
	}
	for (auto y : vec[x]) {
		if (s[y - 1] == '0') {
			ans++;
		}
	}
	return ans;
}
int main() {
	ios :: sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vec[0] = {1, 2, 3, 5, 6, 7};
	vec[1] = {3, 6};
	vec[2] = {1, 3, 4, 5, 7};
	vec[3] = {1, 3, 4, 6, 7};
	vec[4] = {2, 3, 4, 6};
	vec[5] = {1, 2, 4, 6, 7};
	vec[6] = {1, 2, 4, 5, 6, 7};
	vec[7] = {1, 3, 6};
	vec[9] = {1, 2, 3, 4, 6, 7};
	vec[8] = {1, 2, 3, 4, 5, 6, 7};
	for (int i = 0; i < 10; i++) {
		for (auto x : vec[i]) {
			c[i][x - 1] = true;
		}
	}
/*	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		mini[i] = 7;
		for (int j = 1; j <= 9; j++) {
			mini[i] = min(mini[i], get(s[i], j));
		}
		k -= mini[i];
	}
	if (k < 0) {
		cout << -1;
		return 0;
	}*/
	dp[n + 1][0] = true;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 0; j < 10; j++) {
			b[i][j] = get(s[i], j);
		//	cout << "73 " << i << " " << j << " " << b[i][j] << endl;
		}
	}
	for (int i = n; i; i--) {
		for (int j = 0; j <= k; j++) {
			for (int q = 0; q <= 9; q++) {
				if (b[i][q] >= 0 && dp[i + 1][j - b[i][q]]) {
					dp[i][j] = true;
				}
			}
		}
	}
	if (!dp[1][k]) {
		cout << -1;
		return 0;
	}
	int x = k;
	for (int i = 1; i <= n; i++) {
		for (int j = 9; j >= 0; j--) {
			if (b[i][j] >= 0 && dp[i + 1][x - b[i][j]]) {
				cout << j;
				x -= b[i][j];
				break;
			}
		}
	}
	return 0;
}