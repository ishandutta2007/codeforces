#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int cache[N];

int dp(int idx)
{
	if(idx == 0)
		return 1;
	if(idx < 0)
		return 0;
	int &ans = cache[idx];
	if(ans != -1)
		return ans;
	ans = dp(idx - 1) + dp(idx - 2);
	ans %= MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	string s;
	cin >> s;
	int n = s.size();
	int ans = 1;
	for(int i = 0; i < n;)
	{
		int j = i;
		while(j < n && s[i] == s[j])
			j++;
		int len = j - i;
		if(s[i] == 'm')
		{
			cout << 0;
			return 0;
		}
		if(s[i] == 'w')
		{
			cout << 0;
			return 0;
		}
		if(s[i] != 'u' && s[i] != 'n')
		{
			i = j;
			continue;
		}
		ans *= dp(len);
		ans %= MOD;
		i = j;
	}
	cout << ans;
	return 0;
}