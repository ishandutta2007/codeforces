#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

const ll mod = 1000000009;

ll binpow(ll a, ll n)
{
	ll res = 1;
	
	while (n)
	{
		if (n & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n /= 2;
	}
	
	return res;
}

int main()
{
	ll n, k, m;
	cin >> n >> m >> k;
	
	ll wrong = n - m;
	
	if (n / k <= wrong)
		cout << m % mod;
	else
	{
		ll b = n / k - wrong;
		ll ans = (binpow(2, b+1) - 2) % mod;
		while (ans < 0)
			ans += mod;
		ans *= k;
		ans %= mod;
		ans += m - k * b;
		ans %= mod;
		cout << ans;
	}
			
	return 0;
}