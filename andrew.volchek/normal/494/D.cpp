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

const int maxn = 200005;
const ll mod = 1000000007;

vector < pair < int, ll > > g[maxn];

ll sumDist[maxn], sumDistAll[maxn], sumDistUp[maxn];
ll sumDist2[maxn], sumDistAll2[maxn], sumDistUp2[maxn];
ll cnt[maxn];

int tin[maxn], tout[maxn];
int timer = 1;

int parent[maxn][18];
int depth[maxn];
ll depth2[maxn];

ll n;

void dfs(int v, int p, int d, ll d2 = 0)
{
	tin[v] = timer++;
	parent[v][0] = p;
	depth[v] = d + 1;
	cnt[v] = 1;
	depth2[v] = d2;
	
	for (int i = 1; i < 18; i++)
		parent[v][i] = parent[parent[v][i - 1]][i - 1];
	
	for (pair < int, int > to : g[v])
	{
		if (to.fst == p)
			continue;
			
		dfs(to.fst, v, d + 1, d2 + to.snd);
		
		ll l2 = ((ll)to.snd * to.snd) % mod;
		
		sumDist[v] = (sumDist[v] + (sumDist[to.fst] + cnt[to.fst] * 1LL * to.snd)) % mod;
		sumDist2[v] = (sumDist2[v] + (sumDist2[to.fst] + ((((ll)to.snd) * 2LL * sumDist[to.fst]) % mod) + cnt[to.fst] * l2)) % mod;
		cnt[v] += cnt[to.fst];
	}
	
	tout[v] = timer;
}

void dfs2(int v, int p, ll upDist, ll upDist2)
{
	sumDistAll[v] = (sumDist[v] + upDist) % mod;
	sumDistAll2[v] = (sumDist2[v] + upDist2) % mod;
	
	sumDistUp[v] = upDist;
	sumDistUp2[v] = upDist2;
	
	for (pair < int, int > to : g[v])
	{
		if (to.fst == p)
			continue;
			
		ll l2 = ((ll)to.snd * to.snd) % mod;
			
		ll newUpDist = (upDist + sumDist[v] - ((sumDist[to.fst] + cnt[to.fst] * to.snd) % mod) + mod) % mod;
		ll t = newUpDist;
		newUpDist = (newUpDist + ((ll)to.snd) * (n - cnt[to.fst])) % mod;
		
		ll newUpDist2 =
		 (upDist2 + sumDist2[v] - ((sumDist2[to.fst] + (((ll)to.snd * 2LL * sumDist[to.fst]) % mod) + cnt[to.fst] * l2) % mod) + mod) % mod;
		newUpDist2 = (newUpDist2 + (((ll)to.snd * 2LL * t) % mod) + l2 * (n - cnt[to.fst])) % mod;
		
		dfs2(to.fst, v, newUpDist, newUpDist2);
	}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);
	int diff = depth[a] - depth[b];
	for (int i = 0; i < 18; i++)
		if (diff & (1 << i))
			a = parent[a][i];
			
	if (a == b)
		return a;
		
	int ans;
	for (int i = 17; i >= 0; i--)
	{
		if (parent[a][i] == parent[b][i])
			ans = parent[a][i];
		else
		{
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	
	return ans;
}

ll query(int u, int v)
{
	if (!(tin[v] <= tin[u] && tin[u] < tout[v]))
	{
		int z = lca(u, v);
		ll d = (depth2[u] - depth2[z] + depth2[v] - depth2[z]) % mod;
		ll d2 = (d * d) % mod;
		
		ll ans = sumDistAll2[u];
		
		ans = (ans + 3LL * mod - 2LL * ((sumDist2[v] + ((2LL * d * sumDist[v]) % mod) + d2 * cnt[v]) % mod)) % mod;
		ans = (mod - ans) % mod;
		return ans;
	}
	else
	{
		ll ans = sumDistAll2[u];
		
		ll d = (depth2[u] - depth2[v]) % mod;
		d = (d + mod) % mod;
		
		ll d2 = (d * d) % mod;
		
		ans = (ans + 3LL * mod - 2LL * ((sumDistUp2[v] + 2LL * d * sumDistUp[v] + d2 * (n - cnt[v]) ) % mod)) % mod;
		
		return ans;
	}
}

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int _n;
	scanf("%d", &_n);
	n = _n;
	
	for (int i = 0; i < n - 1; i++)
	{
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		g[u].pb(mp(v, c));
		g[v].pb(mp(u, c));
	}
	
	dfs(1, 1, 0);
	dfs2(1, 1, 0, 0);
	
	int q;
	scanf("%d", &q);
	
	for (int i = 0; i < q; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", (int)query(u, v));
	}
	
	
	return 0;
}