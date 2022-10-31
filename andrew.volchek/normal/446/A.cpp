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

const int maxn = 100005;

int a[maxn], dp[2][maxn];


int main(int argc, char *argv[])
{	
	//freopen("a.in", "r", stdin);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	dp[0][1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		if (a[i] > a[i - 1])
			dp[0][i] = dp[0][i - 1] + 1;
		else
			dp[0][i] = 1;
	}

	dp[1][n] = 1;
	
	for (int i = n - 1; i >= 1; i--)
	{
		if (a[i] < a[i + 1])
			dp[1][i] = dp[1][i + 1] + 1;
		else
			dp[1][i] = 1;
	}
	
	int ans = 0;
	
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[0][i]);
		
	for (int i = 1; i + 1 <= n; i++)
		ans = max(ans, 1 + dp[1][i + 1]);
		
	for (int i = n; i - 1 >= 1; i--)
		ans = max(ans, 1 + dp[0][i - 1]);
		
	for (int i = 2; i <= n - 1; i++)
	{
		if (a[i - 1] + 1 < a[i + 1])
		{
			ans = max(ans, dp[0][i - 1] + dp[1][i + 1] + 1);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}