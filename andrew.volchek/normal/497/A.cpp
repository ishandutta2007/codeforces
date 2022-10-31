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

const int maxn = 1005;

char a[maxn][maxn];
int good[maxn];
int ngood[maxn];

int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%c", &a[i][j]);
		scanf("\n");
		//puts(a[i]);
	}
			
	int ans = 0;
	
	for (int i = 0; i < m; i++)
	{
		bool bad = false;
		for (int j = 0; j < n; j++)
			ngood[j] = good[j];
		for (int j = 0; j + 1 < n; j++)
		{
			if (ngood[j])
				continue;
			if (a[j][i] < a[j + 1][i])
			{
				ngood[j] = 1;
			}
			else if (a[j][i] == a[j + 1][i])
			{
			}
			else
			{
				bad = true;
			}
		}
		
		if (bad)
		{
			ans++;
		}
		else
		{
			for (int j = 0; j < n; j++)
				good[j] = ngood[j];
		}
	}
	
	cout << ans << endl;
	
	
	return 0;
}