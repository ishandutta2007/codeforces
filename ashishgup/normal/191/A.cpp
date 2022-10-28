#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

int n, ans = 0;
string s[N];
int dp[256];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(char ch = 'a'; ch <= 'z'; ch++)
	{
		for(char temp = 'a'; temp <= 'z'; temp++)
			dp[temp] = -1e9;
		for(int i = 1; i <= n; i++)
		{
			dp[s[i].back()] = max(dp[s[i].back()], dp[s[i][0]] + s[i].size());
			if(s[i][0] == ch)
				dp[s[i].back()] = max(dp[s[i].back()], (int)s[i].size());
		}
		ans = max(ans, dp[ch]);
	}
	cout << ans;
	return 0;
}