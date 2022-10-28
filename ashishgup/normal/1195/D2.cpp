#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
const int MOD = 998244353;

int n;
int a[N];
vector<int> g[15];

int len(int x)
{
	int cnt = 0;
	while(x > 0)
	{
		cnt++;
		x /= 10;
	}
	return cnt;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		g[len(a[i])].push_back(a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			if(i == j)
			{
				int sz = g[i].size();
				for(auto &it:g[i])
				{
					int pw = 1;
					int x = it;
					while(x > 0)
					{
						int dig = x % 10;
						ans += (sz * pw * dig) % MOD;
						ans %= MOD;
						pw *= 10;
						ans += (sz * pw * dig) % MOD;
						ans %= MOD;
						pw *= 10;
						pw %= MOD;
						x /= 10;
					}
				}
			}
			else if(i < j)
			{
				int sz2 = g[j].size();
				int sz1 = g[i].size();
				for(auto &it:g[i])
				{
					int pw = 10;
					int x = it;
					while(x > 0)
					{
						int dig = x % 10;
						ans += (sz2 * pw * dig) % MOD;
						ans %= MOD;
						pw *= 100;
						pw %= MOD;
						x /= 10;
					}
				}
				for(auto &it:g[j])
				{
					int pw = 1;
					int x = it;
					int left = i;
					while(x > 0)
					{
						int dig = x % 10;
						ans += (sz1 * pw * dig) % MOD;
						ans %= MOD;
						if(left > 0)
							pw *= 100;
						else
							pw *= 10;
						pw %= MOD;
						left--;
						x /= 10;
					}
				}
			}
			else
			{
				int sz2 = g[j].size();
				int sz1 = g[i].size();
				for(auto &it:g[j])
				{
					int pw = 1;
					int x = it;
					while(x > 0)
					{
						int dig = x % 10;
						ans += (sz1 * pw * dig) % MOD;
						ans %= MOD;
						pw *= 100;
						pw %= MOD;
						x /= 10;
					}
				}
				for(auto &it:g[i])
				{
					int pw = 10;
					int x = it;
					int left = j - 1;
					while(x > 0)
					{
						int dig = x % 10;
						ans += (sz2 * pw * dig) % MOD;
						ans %= MOD;
						if(left > 0)
							pw *= 100;
						else
							pw *= 10;
						pw %= MOD;
						left--;
						x /= 10;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}