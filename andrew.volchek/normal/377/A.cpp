#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstring>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define y0 _y0
#define y1 _y1

int n, m;
char a[505][505];
int used[505][505];

const int dirs[4][2] = 
{
	1, 0,
	0, 1, 
	-1, 0,
	0, -1,
};

bool valid(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

int k;

bool dfs(int x, int y)
{
	used[x][y] = 1;
	bool all = true;
	
	for (int i = 0; i < 4; i++)
	{
		int cx = x + dirs[i][0];
		int cy = y + dirs[i][1];
		
		if (valid(cx, cy) && a[cx][cy] == '.' && !used[cx][cy])
		{
			all &= dfs(cx, cy);
		}
	}
	
	if (all && k)
	{
		a[x][y] = 'X';
		k--;
	}
	
	return all;
}

void printAns()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	//freopen("a.in", "r", stdin);
	
	scanf("%d %d %d\n", &n, &m, &k);
	
	for (int i = 0; i < n; i++)
		gets(a[i]);
		
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '.')
			{
				dfs(i, j);
				
				printAns();
				return 0;
			}
		}
	}
	
	
	return 0;
}