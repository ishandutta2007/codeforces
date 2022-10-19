#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll alwayszero, n, seen[300010], upto, q;
vector<pair<ll, ll> > adj[300010];
ll containsend[300010];
ll doesContainEnd(ll a)
{
	if (containsend[a]) return containsend[a];
	if (a == n) return 2;
	containsend[a] = 1;
	ll ans = 1;
	for (auto b : adj[a])
	{
		if (doesContainEnd(b.first) == 2)
		{
			ans = 2;
		}
	}
	return containsend[a] = ans;
}
ll distFromEnd[300010];
ll firstcheck(ll a)
{
	seen[a] = upto;
	ll ambelow = 0;
	for (auto b : adj[a])
	{
		if (seen[b.first] == upto) continue;
		if (doesContainEnd(b.first) == 1) ambelow += firstcheck(b.first);
		else
		{
			firstcheck(b.first);
		}
	}
	if (ambelow > 1) alwayszero = 1;
	return ambelow + 1;
}
ll thebest;
ll furtherestFromEndAns[300010];
ll furtherestFromEndAnsOnly[300010];
ll furtherestFromEnd(ll a)
{
	if (furtherestFromEndAns[a]) return furtherestFromEndAns[a];
	seen[a] = upto;
	furtherestFromEndAns[a] = furtherestFromEndAnsOnly[a] = -1e15;
	for (auto b : adj[a])
	{
		if (seen[b.first] != upto && doesContainEnd(b.first) == 2)
		{
	//		printf("%lld %lld - %lld\n", a, b.first, distFromEnd[b.first]);
			furtherestFromEndAnsOnly[a] = max(furtherestFromEnd(b.first), distFromEnd[b.first]);
		}
		else if (seen[b.first] != upto)
		{
			furtherestFromEndAns[a] = max(furtherestFromEnd(b.first), distFromEnd[b.first]);
		}
	}
	//printf(" %lld %lld\n", a, ans);
	return furtherestFromEndAns[a] = max(furtherestFromEndAnsOnly[a], furtherestFromEndAns[a]);
}
ll furtherest, bestam;
void calcDist(ll a, ll d = 0)
{
	if (seen[a] == upto) return;
//	printf("%lld - %lld\n", a, d);
	seen[a] = upto;
	if (a == n)
	{
		bestam = d;
		return;
	}
	for (auto b : adj[a])
	{
		if (seen[b.first] == upto) continue;
	//	printf("%lld %lld %lld\n", b.first, seen[b.first], upto);
		if (doesContainEnd(b.first) == 2)
		{
			ll am = furtherestFromEndAns[b.first] + d;
		//	printf(" am2 %lld - (%lld %lld)\n", am, a, b.first);
			furtherest = max(furtherest, am);
		}
		else
		{
			ll am = furtherestFromEndAnsOnly[a] + d + b.second;
		//	printf("am2 %lld - (%lld %lld), %lld d %lld - b.second %lld\n", am, a, b.first, furtherestFromEndAns[a], d, b.second);
			furtherest = max(furtherest, am);
		}
		calcDist(b.first, d + b.second);
	}
}
void calcDistFromEnd(ll a, ll d = 0)
{
	if (seen[a] == upto) return;
	seen[a] = upto;
	distFromEnd[a] = d;
	if (a == 1) return;
	for (auto b : adj[a])
	{
		calcDistFromEnd(b.first, d + b.second);
	}
}
int main()
{
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i < n; i++)
	{
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	doesContainEnd(1);
	for (int i = 0; i < n; i++) 
	{
		if (!containsend[i]) 
		{
			containsend[i] = 1;
		}
	}
	upto++;
	firstcheck(1);
	upto++;
	calcDistFromEnd(n);
	upto++;
	furtherestFromEnd(1);
	upto++;
	calcDist(1);
//	printf("%lld\n", alwayszero);
//	printf("%lld\n", furtherest);
	for (int i = 0; i < q; i++)
	{
		ll x;
		scanf("%lld", &x);
		if (alwayszero) printf("%lld\n", bestam);
		else
		{
		//	printf("%lld\n", furtherest);
			ll am = furtherest + x;			
			am = min(am, bestam);
			printf("%lld\n", am);
		}
	}
}