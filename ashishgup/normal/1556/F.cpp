#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 14;
const int MOD = 1e9 + 7;

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

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}


int n;
int a[N];
int cache[1 << N];
int cache2[N][N];

int get(int i, int j)
{
	if(cache2[i][j] != -1)
		return cache2[i][j];
	return cache2[i][j] = (a[i] * modinv(a[i] + a[j])) % MOD;
}

//[2, 3, 5]: 
//001101

int dp(int bitmask) //We need to form a cycle of these vertices
{
	int &ans = cache[bitmask];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int sub = bitmask; sub > 0; sub = (sub - 1) & bitmask)
	{
		if(sub == bitmask)
			continue;
		vector<int> a, b;
		for(int i = 0; i < n; i++)
		{
			if(bitmask >> i & 1)
			{
				if(sub >> i & 1)
					a.push_back(i);
				else
					b.push_back(i);
			}
		}
		int prob = 1;
		for(auto &i:a)
			for(auto &j:b)
				prob = (prob * get(i, j)) % MOD;
		if(a.size() == 1)
			;
		else if(a.size() == 2)
			prob = 0;
		else
			prob = (prob * dp(sub)) % MOD;
		ans += prob;
	}
	ans %= MOD;
	ans = (1 - ans + MOD) % MOD;
	return ans;
}


int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	for(int mask = 1; mask < (1 << n); mask++) //Mask over winners. For all X set bits, Y unset bits, X has to beat Y by definition.
	{
		vector<int> winners, losers;
		for(int i = 0; i < n; i++)
		{
			if(mask >> i & 1)
				winners.push_back(i);
			else
				losers.push_back(i);
		}
		if(winners.size() == 2)
			continue;
		int prob = 1;
		for(auto &i:winners)
			for(auto &j:losers)
				prob = (prob * get(i, j)) % MOD;
		if(winners.size() > 2)
		{
			prob *= dp(mask);
			prob %= MOD;
		}
		ans += winners.size() * prob;
	}
	ans %= MOD;
	cout << ans;
	return 0;
}