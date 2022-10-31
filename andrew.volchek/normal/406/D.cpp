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

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

const int maxn = 100005;

pair < ll, ll > a[maxn];
int p[maxn][20];


vector < int > g[maxn];
int height[maxn];

void dfs(int v)
{
	for (int to : g[v])
	{
		height[to] = height[v] + 1;
		dfs(to);
	}
}


int main(int argc, char *argv[])
{
    //freopen("a.in", "r", stdin);
	int n;
	cin >> n;
	
	vector < int > st;
	
	for (int i = 0; i < n; i++)
	{
		p[i][0] = i;
		cin >> a[i].fst >> a[i].snd;
	}
	
	st.pb(n - 1);
		
	for (int i = n - 2; i >= 0; i--)
	{
		if (st.size() == 1)
		{
			p[i][0] = st[0];
			st.pb(i);
		}
		else
		{
			while (st.size() > 1)
			{
				int u = st[st.size() - 2], v = st[st.size() - 1];
				
				if ((a[u].snd - a[i].snd) * (a[v].fst - a[i].fst) > (a[v].snd - a[i].snd) * (a[u].fst - a[i].fst))
				{
					st.pop_back();
				}
				else
					break;
			}
			
			p[i][0] = st.back();
			st.pb(i);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (p[i][0] != i)
			g[p[i][0]].pb(i);
	}
	
	for (int i = n - 1; i >= 0; i--)
		for (int j = 1; j < 20; j++)
			p[i][j] = p[p[i][j - 1]][j - 1];
			
	dfs(n - 1);
			
	int m;
	cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		
		if (height[u] < height[v])
			swap(u, v);
		
		int diff = height[u] - height[v];
		
		for (int j = 0; j < 20; j++)
			if (diff & (1 << j))
				u = p[u][j];
				
		if (i)
			cout << " ";
				
		if (u == v)
		{
			cout << u + 1;
			continue;
		}
		
		int ans;
		
		for (int j = 19; j >= 0; j--)
		{
			if (p[u][j] == p[v][j])
				ans = p[u][j];
			else
			{
				u = p[u][j];
				v = p[v][j];
			}
		}
		
		cout << ans + 1;
	}
	
	
	return 0;
}