#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxM = (int) 1e6 + 9;

int m;
int b[MxM + 9];
int dp[2][9][9];

/*
 10 1
 1 1 1 1 1 1 1 1 1 1
 */
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	{
		int n;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			++b[x];
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; ++i)
		while (b[i] >= 9) {
			++ans;
			b[i] -= 3;
		}

	cerr << ans << endl;
	cerr << b[1] << endl;

	for (int i = m + 5; i >= 1; --i) {
		for (int j = 0; j <= 8; ++j)
			for (int k = 0; k <= 8; ++k) {
				int &res = dp[i & 1][j][k] = 0;

				for (int l = min(b[i], min(j, k)); l >= 0; --l)
					res = max(res, l + (j - l) / 3 + dp[~i & 1][k - l][b[i] - l]);
			}
	}

	cerr << ans << endl;
	cout << (ans + dp[1][0][0]);
	return 0;
}