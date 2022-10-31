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

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100005;

vector < pair < int, int > > g[maxn];
vector < ll > s[maxn];
vector < ll > dp[maxn];
ll dist[maxn];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++)
	{
		int u, v, len;
		scanf("%d %d %d", &u, &v, &len);
		g[u].pb(mp(v, len));
		g[v].pb(mp(u, len));
	}
	
	for (int i = 1; i <= n; i++)
	{
		int k;
		scanf("%d", &k);
		
		if (!k)
			continue;
		
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			s[i].pb(x);
		}
		
		sort(s[i].begin(), s[i].end());
		dp[i].resize(k);
		
		dp[i][k - 1] = s[i][k - 1] + 1;
		
		for (int j = k - 2; j >= 0; j--)
		{
			if (s[i][j] + 1 == s[i][j + 1])
				dp[i][j] = dp[i][j + 1];
			else
				dp[i][j] = s[i][j] + 1;
		}
	}
	
	for (int i = 1; i <= n; i++)
		dist[i] = 1LL << 60;
	
	priority_queue < pair < ll, pair < int, ll > > > q;
	q.push(mp(0, mp(1, 0)));
	dist[1] = 0;
	
	while (!q.empty())
	{
		ll d = -q.top().fst;
		int v = q.top().snd.fst;
		ll t = q.top().snd.snd;
		
		q.pop();
		
		if (dist[v] != d)
			continue;
			
		ll add = 0;
		
		auto res = lower_bound(s[v].begin(), s[v].end(), t);
		
		if (res != s[v].end() && *res == t)
		{
			add = dp[v][res - s[v].begin()] - t;
		}
		
		for (auto pto : g[v])
		{
			int to = pto.fst;
			ll len = pto.snd;
			
			if (dist[to] > dist[v] + add + len)
			{
				dist[to] = dist[v] + add + len;
				q.push(mp(-dist[to], mp(to, t + add + len)));
			}
		}
	}
	
	if (dist[n] == (1LL << 60))
		cout << -1;
	else
		cout << dist[n];
	
	
	return 0;
}