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

ll dp[5005][5005];
ll a[5005];
ll s[5005];
int n, m, k;

ll rec(int i, int j)
{
	if (i == 0)
		return 0;
		
	if (j < m)
		return 0;
		
	if (dp[i][j] != -1)
		return dp[i][j];
	
	ll res = 0;
	if (j > m)
		res = rec(i, j - 1);
	res = max(res, rec(i - 1, j - m) + s[j] - s[j - m]);
	return dp[i][j] = res;
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[i] = a[i] + s[i - 1];
	}
	
	
	for (int i = 0; i < 5005; i++)	
		for (int j = 0; j < 5005; j++)
			dp[i][j] = -1;
			
	cout << rec(k, n);
	
	
	return 0;
}