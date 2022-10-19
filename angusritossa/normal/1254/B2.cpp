#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define int ll
int n, a[1000010], sum;
int twofactors(int a)
{
	int ans = 0;
	while (a)
	{
		if (a%2 == 0)
		{
			ans++;
			a/=2;
		}
		else break;
	}
	return ans;
}	
ll fastmult2(ll n, ll k, ll mod)
{
	if (k == 1) return n;
	ll ans = fastmult2(n, k/2, mod);
	ans *= 2;
	if (k%2) ans += n;
	ans %= mod;
	return ans;
}
ll fastmult(ll n, ll k, ll mod)
{
	if (!k) return 1;
	ll ans = fastmult(n, k/2, mod);
	ans = fastmult2(ans, ans, mod);
	if (k%2)
	{
		ans = fastmult2(ans, n, mod);
	}
	return ans;
}
vector<ll> as = { 2, 3, 5, 7, 11 };
int isprime(ll n)
{
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n%2 == 0) return 0;
	ll r = twofactors(n-1);
	ll d = (n-1)/(1ll << r);
	for (ll a : as)
	{
		if (a >= n-1) break;
		ll x = fastmult(a, d, n);
		if (x == 1 || x == n-1) continue;
		for (int i = 0; i < r; i++)
		{
			x = fastmult2(x, x, n);
			if (x == 1) return 0;
			else if (x == n-1) break;
			if (i+1 == r) return 0;
		}
	}
	return 1;
}
vector<int> primefactors;
int ans = 1e18;
#undef int
int main()
{
	#define int ll
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	if (sum == 1)
	{
		printf("-1\n");
		exit(0);
	}
	int s = sqrt(sum+1);
	for (int i = 1; i <= min(s, sum); i++)
	{
		if (sum%i == 0)
		{
			if (i != 1 && isprime(i)) primefactors.push_back(i);
			if (sum/i != 1 && isprime(sum/i)) primefactors.push_back(sum/i);
		}
	}
	for (auto p : primefactors)
	{
		int am = 0;
		int sofar = 0;
		D("%lld\n", p);
		for (int i = 0; i < n; i++)
		{
			sofar += a[i];
			sofar %= p;
			am += min(sofar, p-sofar);
		}
		ans = min(ans, am);
	}
	printf("%lld\n", ans);
}