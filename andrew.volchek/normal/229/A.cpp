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

int a[105][30005];
int dp[2][105][30005];

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	int n, m;
	scanf("%d %d\n", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char x;
			scanf("%c", &x);
			a[i][j] = a[i][j + m] = a[i][j + 2 * m] = x - '0';
		}
		scanf("\n");
	}
	
	for (int i = 0; i < n; i++)
	{
		dp[0][i][0] = a[i][0] ? 0 : -1;
		for (int j = 1; j < 3 * m; j++)
			if (a[i][j])
				dp[0][i][j] = j;
			else
				dp[0][i][j] = dp[0][i][j - 1];
				
		dp[1][i][3 * m] = 3 * m;
		
		for (int j = 3 * m - 1; j >= 0; j--)
			if (a[i][j])
				dp[1][i][j] = j;
			else
				dp[1][i][j] = dp[1][i][j + 1];
	}
	
	int ans = 1 << 30;
	
	for (int i = 0; i < m; i++)
	{
		int curr = 0;
		bool bad = false;
		
		for (int j = 0; j < n; j++)
		{
			if (dp[0][j][m + i] == -1 && dp[1][j][m + i] == 3 * m)
				bad = true;
			curr += min(abs(dp[0][j][m + i] - (m + i)), abs(dp[1][j][m + i] - (m + i)));
		}
		
		if (!bad)
			ans = min(ans, curr);
	}
	
	if (ans == (1 << 30))
		cout << -1;
	else
		cout << ans;
	
	
	return 0;
}