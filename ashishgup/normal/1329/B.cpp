#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 35;

int d, m, n, MOD;
int cache[N][N];

int get(int x)
{
	if((1LL << x) > d)
		return 0;
	int ans = min((1LL << (x + 1)) - 1, d) - (1LL << x) + 1;
	ans %= MOD;
	return ans;
}

int dp(int idx, int prv)
{
	if(idx == 0)
		return 1;
	int &ans = cache[idx][prv];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int j = 0; j < prv; j++)
		ans += (get(j) * dp(idx - 1, j)) % MOD;
	ans %= MOD;
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
		cin >> d >> m;
		MOD = m;
		int ans = 0;
		for(int n = 1; n <= 31; n++)
		{
			for(int j = 0; j <= 31; j++)
			{
				ans += get(j) * dp(n - 1, j);
				ans %= MOD;
			}
		}
		cout << ans << endl;
	}
	return 0;
}