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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

ll phi(ll x)
{
	ll res = 1;
	for (int i = 2; i <= x; i++)
	{
		ll c = 1;
		while (x % i == 0)
		{
			c *= i;
			x /= i;
		}
		if (c > 1)
			res *= c - c / i;
	}
	return res;
}

ll gcd(ll a, ll b)
{
	return a ? gcd(b % a, a) : b;
}

ll bpow(ll x, ll n, ll mod)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * x) % mod;;
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n;
	cin >> n;
	
	if (n == 1)
	{
		cout << "YES" << endl;
		cout << 1 << endl;
		return 0;
	}
	
	
	vector < pair < ll, int > > g;
	for (int i = 2; i < n; i++)
		g.pb(mp(gcd(i, n), i));
		
	sort(g.begin(), g.end());
	
	vector < ll > ans;
	
	ans.pb(1);
	ll c = 1;
	ll mul = 1;
	ll cn = n;
	ll x = phi(n);
	
	for (pair < ll, int > d : g)
	{
		//cout << x << endl;
		ll y = bpow(c / mul, x - 1, cn);
		
		ans.pb((y * (d.snd / mul) % n));
		c = (c * y * (d.snd / mul)) % n;
		
		
		if (gcd(d.fst / mul, cn) != 1)
		{
			mul *= gcd(d.fst / mul, cn);
			cn /= gcd(d.fst / mul, cn);
			if (cn == 1)
				break;
			x = phi(cn);
		}
	}
	
	ans.pb(n);
	
	bool good = true;
	set < int > s;
	
	c = 1;
	for (int i = 0; i < ans.size(); i++)
	{
		c = (c * ans[i]) % n;
		s.insert(c);
		//cout << c << endl;
	}
	
	if (s.size() != n)
	{
		cout << "NO" << endl;
		return 0;
	}
	
	printf("YES\n");
	
	for (ll x : ans)
	{
		printf("%d\n", (int)x);
	}
	

	return 0;
}