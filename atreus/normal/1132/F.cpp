#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 500 + 10;
const ll inf = 1e18;

int dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for (int len = 1; len <= n; len++){
		for (int i = 0; i + len - 1 < n; i++){
			int j = i + len - 1;
			if (len == 1){
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i + 1][j] + 1;
			for (int k = i + 1; k <= j; k++)
				if (s[i] == s[k])
					dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
		}
	}
	cout << dp[0][n - 1] << endl;
}