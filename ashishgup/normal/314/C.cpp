#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val)
	{
		idx++;
		while(idx <= N)
		{
			bit[idx] += val;
			bit[idx] %= MOD;
			idx += idx & -idx;
		}
	}

	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int pref(int idx)
	{
		idx++;
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		ans %= MOD;
		return ans;
	}

	int rsum(int l, int r)
	{
		return (pref(r) - pref(l - 1) + MOD) % MOD;
	}

	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};

int n;
int a[N], dp[N];
BIT bit;

int32_t main()
{
	IOS;
	bit.init(1e6 + 5);
	dp[0] = 1;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		dp[i] = bit.pref(a[i]) * a[i] + a[i];
		dp[i] %= MOD;
		dp[i] += MOD;
		dp[i] %= MOD;
		bit.update(a[i], (dp[i] - bit.rsum(a[i], a[i]) + MOD) % MOD);
	}
	int ans = bit.pref(1e6);
	cout << ans;
	return 0;
}