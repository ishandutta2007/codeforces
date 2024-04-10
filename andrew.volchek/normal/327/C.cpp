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

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second

const ll mod = 1000000007;
char str[100005];

ll binpow(ll a, int n)
{
	if (n == 0)
		return 1;
	if (n & 1)
		return (binpow(a, n-1) * a) % mod;
	else
	{
		ll t = binpow(a, n / 2);
		t = t * t;
		t %= mod;
		return t;
	}
}

int phi(ll n)
{
	if (n == 1)
		return 1;
		
	for (ll i = 2; i*i <= n; i++)
	{
		ll nn = n;
		ll mm = 1;
		while (nn % i)
		{
			nn /= i;
			mm *= i;
		}
		if (nn == 1)
			return n - 1;
		else
			return phi(nn) * phi(mm);
	}
	
	return n - 1;
}

int main(int argc, char **argv)
{
	int k;
	gets(str);
	int len = strlen(str);
	cin >> k;
	
	ll curr = 0;
	ll pp = 1;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '5' || str[i] == '0')
		{
			curr += pp;
			curr %= mod;
		}
		pp *= 2;
		pp %= mod;
	}
	
	//cout << curr << endl;
	
	ll t = binpow(2, len);
	ll obr = binpow(t-1, mod-2);
	
	//cout << obr << endl;
	
	ll t2 = binpow(t, k);
	t2 -= 1;
	while (t2 < 0)
		t2 += mod;
		
	//cout << t2 << endl;;
		
	ll ans = curr * t2 ;
	ans %= mod;
	ans *= obr;
	ans %= mod;
	
	cout << ans;
	
	
	return 0;
}