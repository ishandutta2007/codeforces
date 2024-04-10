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

const int maxn = 300005;

int dsu[maxn];
int center[maxn], centerDist[maxn], diam[maxn];

int find(int v)
{
	if (dsu[v] == v)
		return v;
	return dsu[v] = find(dsu[v]);
}

void unite(int a, int b)
{
	int i = find(a);
	int j = find(b);
	
	if (i != j)
	{
		if (rand() & 1)
			swap(i, j);
			
		dsu[i] = j;
		

		diam[j] = max(max(diam[j], diam[i]), centerDist[i] + 1 + centerDist[j]);
		if (max(centerDist[i], 1 + centerDist[j]) < max(centerDist[j], centerDist[i] + 1))
		{
			center[j] = center[i];
			centerDist[j] = max(centerDist[i], 1 + centerDist[j]);
		}
		else
		{
			centerDist[j] = max(centerDist[j], centerDist[i] + 1);
		}
	}
	
}

vector < int > g[maxn];
int used[maxn];
int currUsed = 1;


pair < int, int > ff[maxn];

int dfs(int v, int p)
{
	ff[v] = mp(0, 0);
	int res = 0;
	
	for (int to : g[v])
	{
		if (to == p)
			continue;
			
		int curr = dfs(to, v) + 1;
		res = max(curr, res);
		
		if (curr > ff[v].fst)
		{
			ff[v].snd = ff[v].fst;
			ff[v].fst = curr;
		}
		else if (curr > ff[v].snd)
		{
			ff[v].snd = curr;
		}
	}
	
	return res;
}

pair < int, int > ans;

void dfs2(int v, int p, int up = 0)
{
	ans = min(ans, mp(max(up, ff[v].fst), v));
	for (int to : g[v])
	{
		if (to == p)
			continue;
		int h = up + 1;
		if (ff[to].fst + 1 == ff[v].fst)
			h = max(h, ff[v].snd + 1);
		else
			h = max(h, ff[v].fst + 1);
		dfs2(to, v, h);
	}
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	
	for (int i = 1; i <= n; i++)
	{
		dsu[i] = i;
		center[i] = i;
		centerDist[i] = 0;
		diam[i] = 0;
	}
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		//u = i + 1, v = u + 1;
		g[u].pb(v);
		g[v].pb(u);
		unite(u, v);
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (used[i])
			continue;
			
		currUsed++;
		
		pair < int, int > res = mp(0, i);
		
		for (int h = 0; h < 2; h++)
		{
			currUsed++;
			queue < pair < int, int > > q;
			q.push(mp(0, res.snd));
			used[res.snd] = currUsed;
			
			while (!q.empty())
			{
				int v = q.front().snd;
				int dist = q.front().fst;
				res = max(res, q.front());
				q.pop();
				
				for (int to : g[v])
				{
					if (used[to] == currUsed)
						continue;
					used[to] = currUsed;
					q.push(mp(dist + 1, to));
				}
			}
		}
		
		diam[find(i)] = res.fst;
		
		ans = mp(1e9, -1);
		dfs(i, i);
		dfs2(i, i, 0);
		
		assert((diam[find(i)] + 1) / 2 == ans.fst);
		
		center[find(i)] = ans.snd;
		centerDist[find(i)] = ans.fst;
	}
	
	for (int i = 0; i < q; i++)
	{
		int type;
		scanf("%d", &type);
		
		if (type == 1)
		{
			int x;
			scanf("%d", &x);
			
			printf("%d\n", diam[find(x)]);
		}
		else
		{
			int u, v;
			scanf("%d %d", &u, &v);
			unite(u, v);
		}
	}
	
	return 0;
}