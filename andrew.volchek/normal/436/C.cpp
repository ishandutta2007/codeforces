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

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 1005;

char a[maxn][101];
vector < pair < int, pair < int, int > > > e;

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
	else
	{
		return false;
	}
}


vector < int > g[maxn];

int used[maxn];
vector < pair < int, int > > ans;

void dfs(int v, int p)
{
	ans.pb(mp(v + 1, p + 1));
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to == p)
			continue;
		dfs(to, v);
	}
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	int n, m, k, w;
	scanf("%d %d %d %d\n", &n, &m, &k, &w);
	
	for (int i = 0; i < k; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			for (int h = 0; h < m; h++)
			{
				scanf("%c", &a[i][cnt]);
				cnt++;
			}
			scanf("\n");
		}
	}
	
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			int diff = 0;
			
			for (int h = 0; h < n * m; h++)
				diff += a[i][h] != a[j][h];
				
			if (diff * w > n * m)
				continue;
				
			e.pb(mp(diff * w, mp(i, j)));
		}
	}
	
	sort(e.begin(), e.end());
	
	for (int i = 0; i < k; i++)
		 dsu[i] = i;
	
	int ans2 = 0;
	int cnt = 0;
	
	for (int i = 0; i < e.size(); i++)
	{
		int u = e[i].snd.fst;
		int v = e[i].snd.snd;
		
		if (unite(u, v))
		{
			
			ans2 += e[i].fst;
			g[u].pb(v);
			g[v].pb(u);
			cnt++;
		}
	}
	
	
	
	
	
	for (int i = 0; i < k; i++)
		if (!used[i])
		{
			ans2 += m * n;
			dfs(i, -1);
		}
		
	cout << ans2 << endl;
	
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].fst << " " << ans[i].snd << endl;
	}
	
	return 0;
}