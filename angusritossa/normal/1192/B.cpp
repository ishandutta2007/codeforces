#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
int n, q;
ll w;
vector<pair<int, int> > adj[100010];
int u[100010], v[100010], seen[100010], subtree[20][100010], hei[20][100010], iscentroid[100010], ownedby[20][100010];
pair<int, int> inpre[20][100010];
set<pair<ll, int> > bestchildren[100010];
ll weight[100010];
ll rangetree[20][100010*4][2];
ll was[20][100010];
void push(int t, int curr)
{
	if (!rangetree[t][curr][1]) return;
	rangetree[t][2*curr][0] += rangetree[t][curr][1];
	rangetree[t][2*curr][1] += rangetree[t][curr][1];
	rangetree[t][2*curr+1][0] += rangetree[t][curr][1];
	rangetree[t][2*curr+1][1] += rangetree[t][curr][1];
	rangetree[t][curr][1] = 0;
}
void update(int t, int s, int e, ll val, int curr = 1, int cstart = 0, int cend = 100000)
{
	if (s <= cstart && cend <= e)
	{
		rangetree[t][curr][0] += val;
		rangetree[t][curr][1] += val;
		return;
	}
	push(t, curr);
	int mid = (cstart+cend)/2;
	if (e <= mid) update(t, s, e, val, 2*curr, cstart, mid);
	else if (s > mid) update(t, s, e, val, 2*curr+1, mid+1, cend);
	else
	{
		update(t, s, e, val, 2*curr, cstart, mid);
		update(t, s, e, val, 2*curr+1, mid+1, cend);
	}
	rangetree[t][curr][0] = max(rangetree[t][2*curr][0], rangetree[t][2*curr+1][0]);
}
ll query(int t, int s, int e, int curr = 1, int cstart = 0, int cend = 100000)
{
	if (s <= cstart && cend <= e) return rangetree[t][curr][0];
	push(t, curr);
	int mid = (cstart+cend)/2;
	if (e <= mid) return query(t, s, e, 2*curr, cstart, mid);
	else if (s > mid) return query(t, s, e, 2*curr+1, mid+1, cend);
	else
	{
		return max(query(t, s, e, 2*curr, cstart, mid), query(t, s, e, 2*curr+1, mid+1, cend));
	}
}
int upto;
void dfs(int t, int a, int c, int centroid, ll w, int h = 1)
{
	if (seen[a] == t) return;
	seen[a] = t;
	hei[t][a] = h;
	subtree[t][a] = c;
	ownedby[t][a] = centroid;
	inpre[t][a].first = ++upto;
	update(t, upto, upto, w);
	for (auto b : adj[a])
	{
		if (seen[b.first] != t && !iscentroid[b.first])
		{
			dfs(t, b.first, c, centroid, w+weight[b.second], h+1);
		}
	}
	inpre[t][a].second = upto;
}
ll findbest(int a)
{
	auto it = prev(bestchildren[a].end());
	auto it2 = prev(it);
	return it->first + it2->first;	
}
int sz[100010];
int findsz(int a)
{
	if (sz[a]) return sz[a];
	sz[a] = 1;
	for (auto b : adj[a])
	{
		if (!iscentroid[b.first] && !sz[b.first]) sz[a] += findsz(b.first);
	}
	return sz[a];
}
int findcentroid(int a, int par, int all)
{
	pair<int, int> mx = { -1, -1 };
	for (auto b : adj[a])
	{
		if (!iscentroid[b.first] && b.first != par)
		{
			mx = max(mx, {sz[b.first], b.first});
		}
	}
	if (mx.first <= all/2) return a;
	return findcentroid(mx.second, a, all);
}
priority_queue<pair<ll, int> > pq;
int main()
{
	scanf("%d%d%lld", &n, &q, &w);
	for (int i = 0; i < n-1; i++)
	{
		scanf("%d%d%lld", &u[i], &v[i], &weight[i]);
		adj[u[i]].push_back({ v[i], i });
		adj[v[i]].push_back({ u[i], i});
	}
	for (int i = 1; i <= n; i++) bestchildren[i].insert({0, -1}), bestchildren[i].insert({0, -2});
	for (int t = 1; t < 20; t++)
	{
		fill_n(sz, n+1, 0);
		upto = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!sz[i] && !iscentroid[i])
			{
				findsz(i);
				int c = findcentroid(i, i, sz[i]);
				iscentroid[c] = 1;
				D("centroid %d, %d\n", c, t);
				for (auto b : adj[c])
				{
					if (iscentroid[b.first]) continue;
					dfs(t, b.first, b.first, c, weight[b.second]);
					ll best = query(t, inpre[t][b.first].first, inpre[t][b.first].second);
					bestchildren[c].insert({best, b.first});
					was[t][b.first] = best;
				}
				pq.emplace(findbest(c), c);
			}
		}
	}
	ll ans = 0;
	D("best %lld\n", pq.top().first);
	for (int i = 0; i < q; i++)
	{
	//	ans = 0;
		int e;
		ll wei;
		scanf("%d%lld", &e, &wei);
		e = ((ll)(e) + ans)%(ll)(n-1);
		D("%d %lld\n", e, wei);
		wei = (wei+ans)%w;
		ll diff = wei-weight[e];
		for (int t = 1; t < 20; t++)
		{
			int a, b;
			a = u[e], b = v[e];
			if ((ownedby[t][a] == ownedby[t][b] && ownedby[t][b] )|| ownedby[t][a] == b || ownedby[t][b] == a)
			{
				if (hei[t][a] < hei[t][b]) swap(a, b);
				D("a %d b %d t %d (%d %d)\n", a, b, t, hei[t][a], hei[t][b]);
				update(t, inpre[t][a].first, inpre[t][a].second, diff);
				int c = subtree[t][a];
				int owner = ownedby[t][a];
				ll best = query(t, inpre[t][c].first, inpre[t][c].second);
				D("best %lld (diff %lld), a %d c %d\n", best, diff, a, c);
				bestchildren[owner].erase({was[t][c], c});
				bestchildren[owner].insert({best, c});
				was[t][c] = best;
				D("%lld\n", findbest(owner));
				pq.emplace(findbest(owner), owner);
			}
		}
		weight[e] = wei;
		while (1)
		{
			if (pq.top().first != findbest(pq.top().second)) pq.pop();
			else break;
		}
		ans = pq.top().first;
		printf("%lld\n", ans);
	}
}