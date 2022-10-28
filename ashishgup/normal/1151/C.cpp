#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int MOD = 1e9 + 7;

int l, r;

int sumodd(int x)
{
	x %= MOD;
	return (x * x) % MOD;
}

int sumeven(int x)
{
	x %= MOD;
	return (x + x * x) % MOD;
}

int f(int x)
{
	int o = 1, e = 2, otaken = 0, etaken = 0;
	int sz = 1;
	int sum = 0, cur = 0;
	while(x > 0)
	{
		int take = min(sz, x);
		x -= take;
		if(cur == 0) //odd
		{
			sum += sumodd(take + otaken) - sumodd(otaken);
			sum += MOD;
			sum %= MOD;
			otaken += take;
		}
		else
		{
			sum += sumeven(take + etaken) - sumeven(etaken);
			sum += MOD;
			sum %= MOD;
			etaken += take;
		}
		sz *= 2;
		cur ^= 1;
	}
	return sum;
}

int32_t main()
{
	IOS;
	cin >> l >> r;
	int ans = f(r) - f(l - 1) + MOD;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}