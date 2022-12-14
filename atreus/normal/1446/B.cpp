#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 10;

int dp[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	int answer = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			char A = s[i-1], B = t[j-1];
			if (A == B)
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+2);
			else
				dp[i][j] = max({0,dp[i-1][j]-1,dp[i][j-1]-1});
			answer = max(answer, dp[i][j]);
		}
	}
	cout << answer << '\n';
}