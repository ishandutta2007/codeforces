#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int dp[maxn];

int main(){
    ios_base::sync_with_stdio(false); 
	int tc;
	cin >> tc;
	while (tc --){
		int n, p, k;
		cin >> n >> p >> k;
		string s;
		cin >> s;
		int x, y;
		cin >> x >> y;
		for (int i = n-1; i >= 0; i--)
			dp[i] = dp[i+k] + x*(s[i] == '0');
		int answer = dp[p-1];
		for (int i = p-1; i < n; i++)
			answer = min(answer, dp[i]+(i-p+1)*y);
		cout << answer << endl;
		for (int i = 0; i < n; i++)
			dp[i] = 0;
	}
}