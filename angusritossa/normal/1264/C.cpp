#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353
#define int long long
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
int fmult(ll n, ll k)
{
	if (!k) return 1;
	ll ans = fmult(n, k/2);
	ans*=ans;
	ans%=mod;
	if (k%2)
	{
		ans *= n;
		ans %= mod;
	}
	return ans;
}
int rangetree[100010*8][2];
void update(int node, int val, int curr = 1, int cstart = 0, int cend = 200000)
{
	if (cstart == cend)
	{
		rangetree[curr][0] = rangetree[curr][1] = val;
		return;
	}
	int mid = (cstart+cend)/2;
	if (node <= mid) update(node, val, 2*curr, cstart, mid);
	else update(node, val, 2*curr+1, mid+1, cend);
	rangetree[curr][0] = (rangetree[2*curr][0]*rangetree[2*curr+1][0])%mod;
	rangetree[curr][1] = (rangetree[2*curr][1]*rangetree[2*curr+1][0] + rangetree[2*curr+1][1])%mod;
}
pair<int, int> query(int s, int e, int curr = 1, int cstart = 0, int cend = 200000)
{
	if (s <= cstart && cend <= e) return { rangetree[curr][0], rangetree[curr][1] } ;
	int mid = (cstart+cend)/2;
	if (e <= mid) return query(s, e, 2*curr, cstart, mid);
	else if (s > mid) return query(s, e, 2*curr+1, mid+1, cend);
	else
	{
		auto a = query(s, e, 2*curr, cstart, mid);
		auto b = query(s, e, 2*curr+1, mid+1, cend);
		int c = a.first*b.first;
		c %= mod;
		int d = a.second*b.first + b.second;
		d %= mod;
		return { c, d };
	}
}
set<int> s;
pair<int, int> around(int a)
{
	auto it = s.lower_bound(a);
	int i = *it;
	--it;
	int j = *it;
	return { j, i };
}
#undef int
int main()
{
	#define int long long
	int n, q;
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%lld", &a);
		a = fmult(a, mod-2);
		a *= 100;
		a %= mod;
		D("%lld\n", a);
		update(i, a);
	}
	s.insert(1);
	s.insert(n+1);
	int ans = query(1, n).second;
	for (int i = 0; i < q; i++)
	{
		int a;
		scanf("%lld", &a);
		D("A: %lld\n", a);
		if (s.find(a) == s.end())
		{
			auto stuff = around(a);
			D("adding %lld %lld\n", stuff.first, stuff.second-1);
			D("removing %lld %lld\n", stuff.first, a-1);
			D("removing %lld %lld\n", a, stuff.second-1);
			ans -= query(stuff.first, stuff.second-1).second;
			ans += query(stuff.first, a-1).second;
			ans += query(a, stuff.second-1).second;
			s.insert(a);
		}
		else
		{
			s.erase(a);
			auto stuff = around(a);
			D("removing %lld %lld\n", stuff.first, stuff.second-1);
			D("adding %lld %lld\n", stuff.first, a-1);
			D("adding %lld %lld\n", a, stuff.second-1);
			ans += query(stuff.first, stuff.second-1).second;
			ans -= query(stuff.first, a-1).second;
			ans -= query(a, stuff.second-1).second;
		}
		while (ans < 0) ans += mod;
		ans %= mod;
		printf("%lld\n", ans);

	}
}