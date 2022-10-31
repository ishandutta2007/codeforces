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
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 100005;
const ll mod = 1000000007;

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

ll fact[maxn], invFact[maxn];

ll C(ll n, ll k)
{
	if (k > n)
		return 0;
	return ((fact[n] * invFact[k]) % mod) * invFact[n - k] % mod;
}

char s[maxn];

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	int n, k;
	scanf("%d %d\n", &n, &k);
	
	scanf("%s", s);
	
	fact[0] = invFact[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		fact[i] = fact[i - 1] * i % mod;
		invFact[i] = bpow(fact[i], mod - 2);
	}
	
	if (n == 1)
	{
		cout << int(s[0] - '0') << endl;
		return 0;
	}
	else if (n == 2)
	{
		if (k == 0)
			cout << int(10 * (s[0] - '0') + s[1] - '0') << endl;
		else
			cout << int(s[0] - '0' + s[1] - '0') << endl;
		return 0;
	}
	
	if (k == 0)
	{
		ll ans = 0;
		for (int i = 0; i < n; i++)
			ans = (ans * 10 + s[i] - '0') % mod;
		cout << ans << endl;
		return 0;
	}
	
	ll ans = 0;
	ll curr = 0;
	ll p = 1;
	ll g = 0;
	
	for (int i = n - 1; i >= 0; i--)
	{
		ll c = s[i] - '0';
		ans += (p * c % mod) * C(n - 1 - (n - 1 - i), k) % mod;
		
		ans %= mod;
		
		ans += curr * c % mod;
		ans %= mod;
		
		curr += p * C(n - 2 - g, k - 1) % mod;
		curr %= mod;
		p *= 10;
		g++;
		p %= mod;
		
		//cout << curr << endl;
	}
	
	cout << ans << endl;
	
	
	return 0;
}