#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, a, b;
string s;
int cache[N][2];

int dp(int idx, int cur)
{
	if(s[idx] == '1' && !cur)
		return 1e14;
	if(idx >= 1 && s[idx - 1] == '1' && !cur)
		return 1e14;
	if(idx == n)
	{
		if(cur == 0)
			return b;
		else
			return 1e14;
	}
	int &ans = cache[idx][cur];
	if(ans != -1)
		return ans;
	if(!cur)
	{
		ans = b + a + dp(idx + 1, 0);
		ans = min(ans, b + 2 * a + dp(idx + 1, 1));
	}
	else
	{
		ans = 2 * b + a + dp(idx + 1, 1);
		ans = min(ans, 2 * b + 2 * a + dp(idx + 1, 0));
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> a >> b;
		cin >> s;
		for(int i = 0; i <= n; i++)
			cache[i][0] = cache[i][1] = -1;
		int ans = dp(0, 0);
		cout << ans << endl;
	}
	return 0;
}