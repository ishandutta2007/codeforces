#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

string s;
int cache[12][2][2];

int dp(int idx, int carry, int carry2)
{
	if(idx >= s.size())
	{
		if(carry | carry2)
			return 0;
		return 1;
	}
	int &ans = cache[idx][carry][carry2];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int d1 = 0; d1 <= 9; d1++)
	{
		for(int d2 = 0; d2 <= 9; d2++)
		{
			int sum = carry + d1 + d2;
			if(sum % 10 != (s[idx] - '0'))
				continue;
			ans += dp(idx + 1, carry2, sum / 10);
		}
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
		memset(cache, -1, sizeof(cache));
		cin >> s;
		reverse(s.begin(), s.end());
		int ans = dp(0, 0, 0);
		cout << ans - 2 << endl;
	}
	return 0;
}