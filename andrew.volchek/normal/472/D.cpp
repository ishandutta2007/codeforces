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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 2005;
int a[maxn][maxn];
pair < int, pair < int, int > > e[maxn * maxn];
int dsu[maxn];
int find(int v)
{
	if (dsu[v] == v)
		return v;
	return dsu[v] = find(dsu[v]);
}
bool unite(int a, int b)
{
	int i = find(a);
	int j = find(b);
	if (i != j)
	{
		if (rand() & 1)
			swap(i, j);
		dsu[i] = j;
		return true;
	}
	return false;
}

vector < pair < int, int > > g[maxn];

ll dist[maxn];

void dfs(int v, int p, ll curr)
{
	dist[v] = curr;
	for (pair < int, int > t : g[v])
	{
		if (t.fst == p)
			continue;
		dfs(t.fst, v, curr + t.snd);
	}
}

int main()
{
	//freopen("a.in", "r", stdin);
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
			
			
	for (int i = 0; i < n; i++)
		dsu[i] = i;
	
	int pos = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			e[pos++] = mp(a[i][j], mp(i, j));
			
	sort(e, e + pos);
	
	int left = n - 1;
	
	for (int i = 0; i < pos && left; i++)
	{
		int u = e[i].snd.fst;
		int v = e[i].snd.snd;
		
		if (e[i].fst == 0)
		{
			puts("NO");
			return 0;
		}
		
		if (unite(u, v))
		{
			//cerr << u << " " << v << endl;
			g[u].pb(mp(v, e[i].fst));
			g[v].pb(mp(u, e[i].fst));
			left--;
		}
	}
	
	bool bad = false;
	
	for (int i = 0; i < n; i++)
	{
		dfs(i, -1, 0);
		
		for (int j = 0; j < n; j++)
			if (dist[j] != a[i][j] || dist[j] != a[j][i])
				bad = true;
	}
		
		
	if (bad)
		puts("NO");
	else
		puts("YES");
	return 0;
}