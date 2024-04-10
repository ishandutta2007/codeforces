#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;
const int MOD = 998244353;

int n;
pair<int, int> a[N];
int fact[N], invfact[N];
map<int, int> f, f2;
map<int, int> f3;

int pow(int a, int b, int m)
{
	int ans = 1;
	while(b > 0)
	{
		if(b % 2)
		{
			ans *= a;
			ans %= m;
		}
		a *= a;
		a %= m;
		b /= 2;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD - 2, MOD);
}

void precompute()
{
	fact[0] = invfact[0] = 1;
	for(int i = 1; i < N; i++)
	{
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
		invfact[i] = modinv(fact[i]);
	}
}

int nCr(int n, int r)
{
	int ans = fact[n];
	ans *= invfact[n - r];
	ans %= MOD;
	ans *= invfact[r];
	ans %= MOD;
	return ans;
}


int32_t main()
{
	IOS;
	cin >> n;
	precompute();
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].first >> a[i].second;
		f[a[i].first]++;
		f2[a[i].second]++;
		f3[a[i].first * (n + 1) + a[i].second]++;
	}
	int ans = fact[n];
	int sub1 = 1;
	for(auto &it:f)
	{
		sub1 *= fact[it.second];
		sub1 %= MOD;
	}
	int sub2 = 1;
	for(auto &it:f2)
	{
		sub2 *= fact[it.second];
		sub2 %= MOD;
	}
	sort(a + 1, a + n + 1);
	int check = 1;
	for(int i = 2; i <= n; i++)
	{
		check &= (a[i].first >= a[i - 1].first);
		check &= (a[i].second >= a[i - 1].second);
	}
	if(check)
	{
		int add = 1;
		for(auto &it:f3)
		{
			add *= fact[it.second];
			add %= MOD;
		}
		ans += add;
	}
	ans -= sub1;
	ans += MOD;
	ans -= sub2;
	ans += MOD;
	ans %= MOD;
	cout << ans;
	return 0;
}