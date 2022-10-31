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
const int mod = 1000000007;

int dp[maxn][maxn];
int s[maxn][maxn];
ll f[maxn];


int main()
{
	//freopen("a.in", "r", stdin);
	
	for (int i = 0; i < maxn; i++)
		dp[0][i] = 1;
		
	for (int k = 1; k < maxn; k++)
	{
		for (int i = 0; i < k; i++)
			s[0][i] = dp[k - 1][i];
		for (int i = k; i < maxn; i++)
		{
			int ca = i / k;
			int cb = i % k;
			s[ca][cb] = s[ca - 1][cb] + dp[k - 1][i];
			
			if (s[ca][cb] >= mod)
				s[ca][cb] -= mod;
		}
		
		for (int n = k; n < maxn; n++)
		{
			dp[k][n] = dp[k][n - 1] + s[n / k - 1][n % k];
			
			if (dp[k][n] >= mod)
				dp[k][n] -= mod;
		}
	}
	
	f[0] = 1;
	for (int i = 1; i < maxn; i++)
		f[i] = (f[i - 1] * i) % mod;
	
	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		int n, k;
		scanf("%d %d", &n, &k);
		
		cout << (f[k] * dp[k][n]) % mod << endl;
	}
	
	
	
	return 0;
}