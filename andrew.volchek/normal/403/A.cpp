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

int deg[30];
int g[30][30];
int p[30];

bool comp(int i1, int i2)
{
	return deg[i1] < deg[i2];
}

int main()
{
	//freopen("a.in", "r", stdin);
	int t;
	cin >> t;
	while (t--)
	{
		int n, p;
		cin >> n >> p;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				g[i][j] = 0;
			deg[i] = 0;
		}
			
		int currP = 0;
		for (int i = 0; i < 2 * n + p; i++)
		{
			int u = -1, v = -1;
			
			bool all = true;
			
			for (int i = 1; i <= n; i++)
			{
				all &= deg[i] >= currP + 1;
			}
			
			if (all)
				currP++;
				
			
			for (int j = 1; j <= n && u == -1; j++)
			{
				for (int h = j + 1; h <= n; h++)
				{
					if (!g[j][h] && deg[j] == currP && deg[h] == currP)
					{
						u = j;
						v = h;
						break;
					}
				}
			}
				
			if (u != -1)
			{
				//cerr << u << " " << v << endl;
				g[u][v] = g[v][u] = 1;
				deg[u]++;
				deg[v]++;
				continue;
			}
			
			for (int j = 1; j <= n && u == -1; j++)
				for (int h = j + 1; h <= n; h++)
				{
					if (!g[j][h] && min(deg[j], deg[h]) == currP && max(deg[j], deg[h]) == currP  + 1)
					{
						u = j; 
						v = h;
						break;
					}
				}
			
			//cerr << u << " " << v << endl;
			g[u][v] = g[v][u] = 1;
			deg[u]++;
			deg[v]++;
			
		}
		//cerr << endl;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (g[i][j])
				{
					printf("%d %d\n", i, j);
					cnt++;
				}
				
		//assert(cnt == 2 * n + p);
	}
	
	return 0;
}