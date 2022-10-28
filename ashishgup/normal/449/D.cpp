#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = (1 << 20) + 5;
const int M = (1 << 20) + 5;
const int MOD = 1e9 + 7;

int n;
int a[N];
string s[N];
int f[M], dp[M];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n;
	int mx = (1 << 20) - 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = mx ^ a[i];
		f[a[i]]++;
	}
	int rmask = mx;
	for(int i = 0; i < 20; i++)
	{
		for(int mask = 0; mask < (1 << 20); mask++)
			if(mask >> i & 1)
				f[mask] += f[mask ^ (1 << i)];
	}
	vector<int> v;
	for(int i = 0; i < 20; i++)
		if(rmask >> i & 1)
			v.push_back(i);
	int sz = v.size();
	int ans = 0;
	for(int i = 0; i < (1 << sz); i++)
	{
		int sum = 0;
		int sign = 1;
		int val = 0;
		int cnt = 0;
		for(int j = 0; j < sz; j++)
		{
			if(i >> j & 1)
			{
				cnt++;
				val |= (1 << v[j]);
			}
		}
		if((sz - cnt) % 2)
			sign = -1;
		ans += sign * (pow(2LL, f[val], MOD) - 1);
		ans += MOD;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}