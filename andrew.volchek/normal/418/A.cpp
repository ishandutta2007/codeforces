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

const int maxn = 1005;

int g[maxn][maxn];

int main()
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		int nxt = i;
		for (int j = 0; j < k; j++)
		{
			nxt++;
			while (nxt >= n)
				nxt -= n;
			g[i][nxt]++;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (g[i][j] && g[j][i])
			{
				cout << -1;
				return 0;
			}
			
			if (g[i][j] > 1)
			{
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << n * k << endl;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (g[i][j])
			{
				printf("%d %d\n", i + 1, j + 1);
			}
		}
	}
	
	return 0;
}