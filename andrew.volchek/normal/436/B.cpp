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

const int maxn = 2005;

int a[maxn][maxn];
int ans[maxn];


int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m, k;
	scanf("%d %d %d\n", &n, &m, &k);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;
			scanf("%c", &ch);
			
			if (ch == 'L')
				a[i][j] = 1;
			else if (ch == 'R')
				a[i][j] = 2;
			else if (ch == 'U')
				a[i][j] = 3;
			else if (ch == 'D')
				a[i][j] = 4;
		}
		scanf("\n");
	}
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 2; j < n; j += 2)
			if (a[j][i] == 3)
				ans[i]++;
				
		for (int k = 0; k < n && i - k >= 0; k++)
			if (a[k][i - k] == 2)
				ans[i]++;
		
		for (int k = 0; k < n && i + k < m; k++)
			if (a[k][i + k] == 1)
				ans[i]++;
	}
	
	for (int i = 0; i < m; i++)
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	
	
	return 0;
}