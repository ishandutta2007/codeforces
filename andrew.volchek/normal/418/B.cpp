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
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left

template < typename T > T abs(T x)
{
	return x > 0 ? x : -x;
}

const int maxn = 105;
const ull inf = -1;

ull dp[2][1 << 20];

int xi[maxn], bi[maxn], mi[maxn], p[maxn];

bool comp(int i, int j)
{
	return bi[i] < bi[j];
}

int main()
{
	int n, m, b;
	scanf("%d %d %d", &n, &m, &b);
	
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d %d %d", xi + i, bi + i, &k);
		
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			
			x--;
			
			mi[i] |= 1 << x;
		}
		
		p[i] = i;
	}
	
	sort(p, p + n, comp);
	
	for (int i = 1; i < (1 << m); i++)
		dp[0][i] = inf;
		
	ull ans = inf;
	
	for (int i = 0; i < n; i++)
	{
		int i1 = i & 1;
		int i2 = 1 - i1;
		
		for (int j = 0; j < (1 << m); j++)
		{
			dp[i2][j] = dp[i1][j];
		}
		
		int x = xi[p[i]];
		int mask = mi[p[i]];
		int bn = bi[p[i]];
		
		for (int j = 0; j < (1 << m); j++)
		{
			if (dp[i1][j] != inf)
				dp[i2][j | mask] = min(dp[i2][j | mask], dp[i1][j] + x);
		}
		
		if (dp[i2][(1 << m) - 1] != inf)
			ans = min(ans, dp[i2][(1 << m) - 1] + (ull)bn * b);
	}
	
	if (ans == inf)
		cout << -1 << endl;
	else
		cout << ans << endl;
			
	return 0;
}