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

const int dirs[4][2] = 
{
	1, 0,
	-1, 0, 
	0, 1, 
	0, -1,
};

const int maxn = 105;
int f[maxn][maxn];

int n, m;

bool valid(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool check(int x, int y, int color)
{
	for (int j = 0; j < color; j++)
	{
		bool all = true;
		for (int i = 0; i < 4; i++)
		{
			int cx = x + dirs[i][0];
			int cy = y + dirs[i][1];
			
			if (!valid(cx, cy))
				continue;
				
			if (f[cx][cy] == -1)
				continue;
				
			all &= f[cx][cy] != j;
		}
		
		if (all)
			return true;
	}
	
	return false;
}

bool check2(int x, int y, int color)
{
	for (int i = 0; i < 4; i++)
	{
		int cx = x + dirs[i][0];
		int cy = y + dirs[i][1];
		
		if (!valid(cx, cy))
			continue;
			
		if (f[cx][cy] == -1)
			continue;
			
		if (f[cx][cy] == color)
			return true;
	}
	
	return false;
}

int main(int argc, char *argv[])
{
	cin >> n >> m;
	
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			f[i][j] = -1;
			
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (f[i][j] != -1)
				continue;

			int color = 0;
			int len = 0;
			
			while (check2(i, j, color)) color++;
			
			while (i + len < n && j + len < m && f[i][j + len] == -1 && 
				   f[i + len][j] == -1 && !check(i, j + len, color) && !check2(i, j + len, color)
				   && !check2(i + len, j, color)) len++;
			
			
			for (int x = i; x < i + len; x++)
			{
				for (int y = j; y < j + len; y++)
				{
					f[x][y] = color;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%c", f[i][j] + 'A');
		}
		printf("\n");
	}
	
	return 0;
}