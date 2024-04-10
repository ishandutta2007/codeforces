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

const int maxn = 2005;
int g[maxn][maxn];
int color[maxn];
int used[maxn];
int n;

vector < int > order;

void dfs1(int v)
{
	used[v] = 1;
	for (int i = 0; i < n; i++)
		if (g[v][i] && !used[i])
			dfs1(i);
			
	order.pb(v);
}

void dfs2(int v)
{
	used[v] = 1;
	for (int i = 0; i < n; i++)
		if (g[i][v] && !used[i])
			dfs2(i);
}

int main()
{
	//freopen("a.in", "r", stdin);
	
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &g[i][j]);
			
	for (int i = 0; i < n; i++)
	{
		if (!used[i])
			dfs1(i);
	}
	
	for (int i = 0; i < n; i++)
		used[i] = 0;
		
	cerr << order.back();
	dfs2(order.back());
	
	bool good = true;
	for (int i = 0; i < n; i++)
		good &= used[i];
		
	if (good)
		puts("YES");
	else
		puts("NO");
	
	
	
	return 0;
}