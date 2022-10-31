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

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

vector < int > g[1405];
int used[1405];
int currUsed;
int vis = 0;

void dfs(int v)
{
	used[v] = currUsed;
	vis++;
	for (int to : g[v])
	{
		if (used[to] == currUsed)
			continue;
		dfs(to);
	}
}

int main()
{
	//freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		char ch;
		scanf("%c", &ch);
		if (ch == '>')
		{
			for (int j = 0; j + 1 < m; j++)
			{
				g[i * m + j].pb(i * m + j + 1);
			}
		}
		else
		{
			for (int j = 0; j + 1 < m; j++)
				g[i * m + j + 1].pb(i * m + j);
		}
	}
	
	scanf("\n");
	
	for (int j = 0; j < m; j++)
	{
		char ch;
		scanf("%c", &ch);
		if (ch == 'v')
		{
			for (int i = 0; i + 1 < n; i++)
				g[i * m + j].pb((i + 1) * m + j);
		}
		else
		{
			for (int i = 0; i + 1 < n; i++)
				g[(i + 1) * m + j].pb(i * m + j);
		}
	}
	
	for (int i = 0; i < n * m; i++)
	{
		currUsed++;
		vis = 0;
		dfs(i);
		
		if (vis != n * m)
		{
			puts("NO");
			return 0;
		}
	}
	
	
	puts("YES");
	
	return 0;
}