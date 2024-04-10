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
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 2005;

int n, m;
char a[maxn][maxn];

const int dirs[4][2] = 
{
	1, 0,
	-1, 0,
	0, 1,
	0, -1,
};


bool valid(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

vector < int > g[maxn * maxn];
int deg[maxn * maxn];
int bl[maxn * maxn];

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);
	
	scanf("%d %d\n", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			scanf("%c", &c);
			a[i][j] = c;
		}
		scanf("\n");
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '*')
				continue;
				
			for (int h = 0; h < 4; h++)
			{
				int x = i + dirs[h][0];
				int y = j + dirs[h][1];
				
				if (!valid(x, y))
					continue;
					
				if (a[x][y] == '*')
					continue;
					
				g[i * m + j].pb(x * m + y);
				deg[i * m + j]++;
			}
		}
	}
	
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << deg[i * m + j] << " ";
		cout << endl;
	}*/
	
	queue < int > q;
	for (int i = 0; i < n * m; i++)
	{
		if (deg[i] == 1)
			q.push(i);
	}
			
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		
		if (bl[v])
			continue;
			
		int u = -1;
		for (int x : g[v])
			if (!bl[x])
				u = x;
				
		if (u == -1)
			continue;
				
		int vx = v / m;
		int vy = v % m;
		
		int ux = u / m;
		int uy = u % m;
		
		/*cerr << vx << " " << vy << endl;
		cerr << ux << " " << uy << endl;*/
		
		if (vx == ux)
		{
			a[vx][min(vy, uy)] = '<';
			a[vx][max(vy, uy)] = '>';
		}
		else
		{
			a[min(vx, ux)][vy] = '^';
			a[max(vx, ux)][vy] = 'v';
		}
		
		bl[v] = 1;
		bl[u] = 1;
		for (int x : g[u])
			if (!bl[x])
			{
				deg[x]--;
				if (deg[x] == 1)
					q.push(x);
			}
	}
	
	bool good = true;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			good &= a[i][j] != '.';
			
	if (!good)
	{
		printf("Not unique\n");
		return 0;
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}