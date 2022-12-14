#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int dp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		string s;
		cin >> n >> s;
		dp[0] = 1;
		for (int i = 1; i < n; i++){
			if (s[i] == s[i-1])
				dp[i] = dp[i-1] + 1;
			else
				dp[i] = 1;
		}
		if (dp[n-1] == n){
			cout << (n+2)/3 << '\n';
			continue;
		}
		if (s[0] == s[n-1]){
			for (int i = 0; i < n-1; i++)
				if (s[i] != s[i+1]){
					dp[i] += dp[n-1];
					break;
				}
			dp[n-1] = 0;
		}
		int answer = 0;
		for (int i = 0; i < n; i++)
			if (i == n-1 or s[i] != s[i+1])
				answer += dp[i]/3;
		cout << answer << '\n';
	}
}