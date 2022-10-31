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

using namespace std;


#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

int g[10][10];
int deg[10];
map < pair < int, int >, vector < int > > d;

int main()
{
	//freopen("a.in", "r", stdin);
	
	int n;
	cin >> n;
	
	int startV = 10;
	
	for (int i = 0; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		
		d[mp(u, v)].pb(i + 1);
		
		g[u][v]++;
		g[v][u]++;
		
		deg[u]++;
		deg[v]++;
		
		startV = v;
	}
	
	int oddCnt = 0;
	
	for (int i = 0; i <= 6; i++)
		if (deg[i] & 1)
		{
			oddCnt++;
			startV = i;
		}
			
	if (!(oddCnt == 0 || oddCnt == 2))
	{
		puts("No solution");
		return 0;
	}
	
	stack < int > s;
	s.push(startV);
	
	vector < int > cycle;
	
	while (!s.empty())
	{
		int v = s.top();
		
		if (!deg[v])
		{
			cycle.pb(v);
			s.pop();
		}
		else
		{
			for (int i = 0; i <= 6; i++)
			{
				if (g[v][i])
				{
					g[v][i]--;
					g[i][v]--;
					deg[v]--;
					deg[i]--;	
					s.push(i);
					break;
				}
			}
		}
	}
	
	vector < pair < int, bool > > ans;
	
	for (int i = 0; i < (int)cycle.size() - 1; i++)
	{
		int curr = cycle[i];
		int nxt = cycle[(i + 1) % cycle.size()];
		
		if (!d[mp(curr, nxt)].empty())
		{
			ans.pb(mp(d[mp(curr, nxt)].back(), true));
			d[mp(curr, nxt)].pop_back();
		}
		else if (!d[mp(nxt, curr)].empty())
		{
			ans.pb(mp(d[mp(nxt, curr)].back(), false));
			d[mp(nxt, curr)].pop_back();
		}
	}
	
	
	
	if (ans.size() != n)
	{
		puts("No solution");
		return 0;
	}
	
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].fst << " " << (ans[i].snd ? "+" : "-") << endl;
			
	return 0;
}