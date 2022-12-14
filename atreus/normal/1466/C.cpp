#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e5 + 10;
const ll mod = 1e9 + 7;

int dp[maxn][5];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		string s;
		cin >> s;
		int n = s.size();
		if (n == 1){
			cout << 0 << '\n';
			continue;
		}
		dp[1][1] = dp[1][2] = 1;
		dp[1][3] = 2;
		if (s[0] == s[1])
			dp[1][0] = n;
		else
			dp[1][0] = 0;
		for (int i = 2; i < n; i++){
			for (int j = 0; j < 4; j++){
				dp[i][j] = n;
				if (j == 0 and s[i] == s[i-1])
					continue;
				for (int k = 0; k < 4; k++){
					int bef = (j&2) > 0;
					int feb = (k&1) > 0;
					if (bef != feb)
						continue;
					int befbef = (k&2)>0;
					int me = (j&1) > 0;
					if (me == 0 and befbef == 0 and s[i] == s[i-2])
						continue;
					dp[i][j] = min(dp[i][j],dp[i-1][k]+me);
				}
			}
		}
		int answer = n;
		for (int i = 0; i < 4; i++)
			answer = min(answer,dp[n-1][i]);
		cout << answer << '\n';
	}
}