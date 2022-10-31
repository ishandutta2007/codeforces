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

const int maxn = 1000005;
const int inf = 1e9;

vector < int > g[maxn];

int dist[maxn];
set < int > was[maxn];
int c[maxn];

int deg[maxn];

int main(int argc, char *argv[])
{
    //freopen("a.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++)
    {
		int u, v;
		scanf("%d %d", &u, &v);
		g[v].pb(u);
		
		deg[u]++;
	}
   
	int s, t;
	scanf("%d %d", &s, &t);
	
	for (int i = 1; i <= n; i++)
		dist[i] = inf;
		
	dist[t] = 0;
	priority_queue < pair < int, int > > q;
	q.push(mp(0, t));
	
	while (!q.empty())
	{
		int v = q.top().snd;
		int currD = -q.top().fst;
		q.pop();
		
		if (currD != dist[v])
			continue;
			
		for (int to : g[v])
		{
			was[to].insert(v);
			c[to] = max(c[to], currD);
			
			int d = currD + 1;
			
			if (was[to].size() == deg[to])
				d = min(d, c[to]);
				
			if (d < dist[to])
			{
				dist[to] = d;
				q.push(mp(-d, to));
			}
		}
	}
	
	if (dist[s] == inf)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dist[s] << endl;
	}
	
	return 0;
}