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

int dp[5005][5005];
int n;
ll s[5005];
ll c[5005];

int rec(int a, int b)
{
	if (b == n - 1)
		return b - a;
		
	if (dp[a][b] != -1)
		return dp[a][b];
		
	int res = 1e9;
	
	if (b < n - 1)
		res = rec(a, b + 1);
		
	int lo = b, hi = n;
	while (hi - lo > 1)
	{
		int mid = (lo + hi) >> 1;
		
		if (s[mid] - s[b] >= s[b] - (a ? s[a - 1] : 0))
			hi = mid;
		else
			lo = mid;
	}
	
	if (hi != n)
		res = min(res, rec(b + 1, hi) + b - a);
	
	return dp[a][b] = res;
}

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	
	s[0] = c[0];
	
	for (int i = 1; i < n; i++)
		s[i] = c[i] + s[i - 1];
		
	for (int i = 0; i < 5005; i++)
		for (int j = 0; j < 5005; j++)
			dp[i][j] = -1;
			
	cout << rec(0, 0);
	
	
	return 0;
}