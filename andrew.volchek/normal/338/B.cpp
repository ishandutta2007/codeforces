#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

const int maxn = 100005;
pair < int, int > m1down[maxn], m2down[maxn];
int n, m, d;
vector < int > g[maxn];
int ans = 0;
bool evil[maxn];

int dfs1(int v, int p)
{
	pair < int, int > m1 = mp(evil[v] ? 0 : -1, -1);
	pair < int, int > m2 = mp(-1, -1);
	
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to == p)
			continue;
		
		int res = dfs1(to, v) + 1;
		if (!res)
			continue;
		
		pair < int, int > curr = mp(res, to);
		
		if (curr > m1)
		{
			m2 = max(m2, m1);
			m1 = curr;
		}
		else if (curr > m2)
		{
			m2 = curr;
		}
	}
	
	m1down[v] = m1;
	m2down[v] = m2;
	
	return m1down[v].fst;
}

void dfs2(int v, int p, int maxUp)
{
	if (max(maxUp, m1down[v].fst) <= d)
		ans++;
		
	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if (to == p)
			continue;
			
		int newUp;			
		if (m1down[v].snd != to)
			newUp = max(maxUp, m1down[v].fst);
		else
			newUp = max(maxUp, m2down[v].fst);
		
		if (newUp == -1)
			dfs2(to, v, -1);
		else
			dfs2(to, v, newUp + 1);
	}
}


int main()
{
	scanf("%d %d %d", &n, &m, &d);
	
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		evil[x] = true;
	}
	
	for (int i = 0; i < n-1; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs1(1, -1);
	dfs2(1, -1, -1);
	
	cout << ans;
}