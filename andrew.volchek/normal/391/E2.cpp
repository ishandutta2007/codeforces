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
#define y1 _y1

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 100005;

vector < int > g[3][maxn];
ll sz[3][maxn], ds[3][maxn], sum[3][maxn];
ll n[3];

void dfs(int i, int v, int p)
{
	sz[i][v] = 1;
	for (int to : g[i][v])
		if (to != p)
		{
			dfs(i, to, v);
			sz[i][v] += sz[i][to];
			ds[i][v] += ds[i][to] + sz[i][to];
		}
}

void dfs2(int i, int v, int p, ll up = 0)
{
	sum[i][v] = up + ds[i][v];
	for (int to : g[i][v])
		if (to != p)
		{
			dfs2(i, to, v, up + ds[i][v] - (ds[i][to] + sz[i][to]) + (n[i] - sz[i][to]));
		}
}

int i2, i3;
ll best[2][maxn];
ll ans = 0;

void dfs3(int i, int v, int p)
{
	multiset < ll > s;
	for (int to : g[i][v])
	{
		if (to == p)
			continue;
		dfs3(i, to, v);
		s.insert(best[0][to]);
	}
	
	ans = max(ans, sum[i][v] * (n[i2] + n[i3]));
	
	best[0][v] = sum[i][v] * n[i2];
	best[1][v] = sum[i][v] * n[i3];
	
	for (int to : g[i][v])
	{
		if (to == p)
			continue;
		s.erase(s.find(best[0][to]));
		if (!s.empty())
			ans = max(ans, *s.rbegin() + best[1][to] + 2LL * n[i2] * n[i3]);
		s.insert(best[0][to]);
		ans = max(ans, sum[i][v] * n[i2] + n[i2] * n[i3] + best[1][to]);
		ans = max(ans, sum[i][v] * n[i3] + n[i2] * n[i3] + best[0][to]);
		
		best[0][v] = max(best[0][v], best[0][to] + n[i2] * n[i3]);
		best[1][v] = max(best[1][v], best[1][to] + n[i2] * n[i3]);
	}
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	cin >> n[0] >> n[1] >> n[2];
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n[i] - 1; j++)
		{
			int u, v;
			cin >> u >> v;
			g[i][u].pb(v);
			g[i][v].pb(u);
		}
		
		dfs(i, 1, -1);
		dfs2(i, 1, -1);
	}
	
	ll gans = 0;
	
	ll best[3] = { 0, 0, 0 };
	ll s = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n[i]; j++)
		{
			s += sum[i][j];
			best[i] = max(best[i], sum[i][j]);
		}
	
	for (int i = 0; i < 3; i++)
	{
		i2 = (i + 1) % 3;
		i3 = (i + 2) % 3;
		
		ans = 0;
		dfs3(i, 1, -1);
		
		ans += s / 2;
		ans += n[i2] * (n[i] + n[i3]);
		ans += n[i3] * (n[i] + n[i2]);
		ans += best[i2] * (n[i] + n[i3]);
		ans += best[i3] * (n[i] + n[i2]);
		
		gans = max(gans, ans);
	}
	
	cout << gans << endl;
	
	return 0;
}