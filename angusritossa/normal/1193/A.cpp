#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define mod 998244353
typedef long long ll;
tr1::unordered_map<ll, ll> memo[1 << 18];
ll adj[20];
int n, m;
ll dp(ll a, ll b)
{
	if (memo[a].find(b) != memo[a].end()) return memo[a][b];
	ll c = ((1 << n)-1)^(a | b);
	if (!b && !c) return memo[a][b] = 1;
	ll ans = 0;
	ll newa, newb, newc;
	for (int i = 0; i < n; i++)
	{
		if (!(b & (1 << i))) continue;
		newa = a, newb = b, newc = c;
		ll removefromb = newb & ((1 << i)-1);
		newb ^= removefromb;
		newc ^= removefromb;
		removefromb = newc & adj[i];
		newb ^= removefromb;
		newb ^= (1 << i);
		newa ^= (1 << i);
		ans += dp(newa, newb);
	}
	return memo[a][b] = ans;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u-1] |= (1 << (v-1));
		adj[v-1] |= (1 << (u-1));
	}
	ll ans = dp(0, (1 << n)-1);
	ans*=m;
	ans/=2;
	ans%=mod;
	printf("%lld\n", ans);
}