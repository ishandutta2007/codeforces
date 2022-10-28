#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e5 + 5;

int n, m;
string s, t;
int cache[401][401][401];

int dp(int i, int j, int k)
{
	if(i == n && k == 0)
		return 0;
	if(i == n)
		return -1e9;
	int &ans = cache[i][j][k];
	if(ans != -1)
		return ans;
	ans = 0;
	if(i < n)
		ans = dp(i + 1, j, k);
	if(i < n && s[i] == t[j])
		ans = max(ans, 1 + dp(i + 1, j + 1, k));
	if(i < n && k > 0 && s[i] == t[m - k])
		ans = max(ans, dp(i + 1, j, k - 1));
	return ans;
}

int32_t main()
{
	IOS;
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> s >> t;
		n = s.size();
		m = t.size();
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				for(int k = 0; k <= m; k++)
					cache[i][j][k] = -1;
		int flag = 0;
		for(int i = 0; i <= m; i++)
		{
			int reqd = m - i;
			if(dp(0, 0, i) >= reqd)
				flag = 1;
		}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}