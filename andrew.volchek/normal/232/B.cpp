#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const ll mod = 1000000007;
ll c[105][105];
ll dp[105][10005];

ll bpow(ll x, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	for (int i = 0; i < 105; i++)
		c[i][0] = c[i][i] = 1;
		
	for (int i = 1; i < 105; i++)
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
			
	ll n, m, k;
	cin >> n >> m >> k;
			
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		ll cnt = m / n + (i <= (m % n));
		for (int h = 0; h <= n; h++)
		{
			ll x = bpow(c[n][h], cnt);
			for (int j = h; j <= n * i; j++)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - h] * x) % mod;
		}
	}
	
	cout << dp[n][k] << endl;
	
	return 0;
}