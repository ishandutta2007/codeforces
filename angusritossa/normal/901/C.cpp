#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll par[1000000];
ll hei[1000000];
bool done[1000000];
set<pair<ll, int> > s;
struct rtree
{
ll rangetree[2000000], lazy[2000000]; 
void init(ll n)
{
	fill_n(rangetree,2000000, 999999999999999);
	fill_n(lazy,2000000, 999999999);
}
ll findval(ll val, ll cstart, ll cend, ll curr)
{
//	printf("%lld %d %d\n", val, cstart, cend);
	val-=cstart;
	cend-=cstart;
	if (val < 0) return 0;
	if (val <= cend)
	{
//		printf(" %lld\n", ((val+1)*(val+2))/2);
		return ((val+1)*(val+2))/2;
	}
	else
	{
	//	printf("%lld\n", (((cend+1)*(cend+2))/2) + (val-cend)*(cend+1));
		return (((cend+1)*(cend+2))/2) + (val-cend)*(cend+1);
	}
}
void push(ll curr, ll sz1, ll sz2)
{
	rangetree[2*curr] -= lazy[curr]*sz1;
	rangetree[2*curr+1] -= lazy[curr]*sz2;
	lazy[2*curr] += lazy[curr];
	lazy[2*curr+1] += lazy[curr];
	lazy[curr] = 0;
}
void setproperly(int curr = 1, ll val = 999999999, int cstart = 0, int cend = 300010)
{
	lazy[curr] = 0;
	if (cstart == cend)
	{
		rangetree[curr] = min(rangetree[curr], val);
		s.insert(make_pair(min(rangetree[curr], val), cstart));
		rangetree[curr] = max((ll)0, rangetree[curr]-cstart+1);
		return;
	}
	val = min(val, rangetree[curr]);
	ll mid = (cstart+cend)/2;
	setproperly(2*curr, val, cstart, mid);
	setproperly(2*curr+1, val, mid+1, cend);
	rangetree[curr] = (rangetree[2*curr] + rangetree[2*curr+1]);
}
void sub1(ll s, ll e, ll curr = 1, ll cstart = 0, ll cend = 300010)
{
	if (s <= cstart && cend <= e)
	{
		rangetree[curr]-=(cend-cstart+1);
		lazy[curr]++;
		return;
	}
	ll mid = (cstart+cend)/2;
	push(curr, (mid-cstart+1), (cend-mid));
	if (e <= mid) sub1(s, e, 2*curr, cstart, mid);
	else if (s > mid) sub1(s, e, 2*curr+1, mid+1, cend);
	else
	{
		sub1(s, e, 2*curr, cstart, mid);
		sub1(s, e, 2*curr+1, mid+1, cend);
	}
	rangetree[curr] = (rangetree[2*curr] + rangetree[2*curr+1]);
}
void update(ll s, ll e, ll val, ll curr = 1, ll cstart = 0, ll cend = 300010)
{
	if (s <= cstart && cend <= e)
	{
		rangetree[curr] = min(rangetree[curr], val);
	//	printf("%d %d to %d\n", cstart, cend, val);
		return;
	}
	ll mid = (cstart+cend)/2;
	//push(curr, cstart, mid, cend);
	if (e <= mid) update(s, e, val, 2*curr, cstart, mid);
	else if (s > mid) update(s, e, val, 2*curr+1, mid+1, cend);
	else
	{
		update(s, e, val, 2*curr, cstart, mid);
		update(s, e, val, 2*curr+1, mid+1, cend);
	}
}
ll query(ll s, ll e, ll curr = 1, ll cstart = 0, ll cend = 300010)
{
	if (s <= cstart && cend <= e) return rangetree[curr];
	ll mid = (cstart+cend)/2;
	push(curr, (mid-cstart+1), (cend-mid));
	if (e <= mid) return query(s, e, 2*curr, cstart, mid);
	else if (s > mid) return query(s, e, 2*curr+1, mid+1, cend);
	else
	{
		return (query(s, e, 2*curr, cstart, mid) + query(s, e, 2*curr+1, mid+1, cend));
	}
}
};
rtree mntree;
ll n, m, q;
vector<ll> adj[1000010];
void dfs(ll a, ll p = -1, ll h = 0)
{
	par[a] = p;
	hei[a] = h;
	done[a] = true;
	for (ll ad: adj[a])
	{
		if (ad == p) continue;
		if (done[ad] && hei[ad] < h)
		{
			ll mn = ad;
			ll mx = ad;
			ll b = a;
			while (b != ad)
			{
				mn = min(mn, b);
				mx = max(mx, b);
				b = par[b];
			}
			mntree.update(0, mn, mx-1);
			//printf("%lld %lld %lld %lld\n", a, ad, mn, mx);
		}
		else if (!done[ad])
		{
			dfs(ad, a, h+1);
		}
	}
}
pair<pair<ll, ll>, ll> queries[500010];
ll ans[500010];
int main()
{
	scanf("%lld%lld", &n, &m);
	mntree.init(n);
	mntree.update(0, n, n);
//	printf("%lld\n", mntree.query(0, n));
	//return 0;
	for (ll i = 0; i < m; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (ll i = 1; i <= n; i++)
	{
		if (!done[i]) dfs(i);
	}
	scanf("%lld", &q);
	for (ll i = 0; i < q; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		queries[i] = make_pair(make_pair(b, a), i);
	}
	sort(queries, queries+q);
	reverse(queries, queries+q);
	int oldy = n;
	mntree.setproperly();
	for (ll i = 0; i < q; i++)
	{
		ll x = queries[i].first.second;
		ll y = queries[i].first.first;
		for (int j = oldy-1; j >= y; j--)
		{
			auto it = s.lower_bound(make_pair(j+1, 0));
			if (it == s.end()) continue;
			if (it->second <= n) mntree.sub1(it->second, n);
		}
		oldy = y;
		ans[queries[i].second] = mntree.query(x, y);
	}
	for (ll i = 0; i < q; i++)
	{
		printf("%lld\n", ans[i]);
	}
}