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

const int maxn = 400;
const int maxk = 200;

ll s[maxn];
ll p[maxn];
ll dp[maxn][maxk][2];



int main()
{
//	srand(time(NULL));
//	gen();
	//freopen("a.in", "r", stdin);
	
	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> p[i];
		
	const ll inf = 1e17;
		
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxk; j++)
			dp[i][j][0] = dp[i][j][1] = -inf;
			
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
		
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + p[i];
		
	ll ans = 0;
		
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			
			dp[i][j][0] = dp[i - 1][j][0];
			dp[i][j][1] = dp[i - 1][j][1];
			
			
			if (j > 0)
			{
				for (int h = i - 1; h >= 0; h--)
				{
					if (j == k)
					{
						ans = max(ans, dp[h][j - 1][0]  +  (s[i] - s[h]));
						ans = max(ans, dp[h][j - 1][1]  -  (s[i] - s[h]));
					}
					
					ll add = (s[i] - s[h]);
					if (j == 1)
						add = 0;
					
					dp[i][j][0] = max(dp[i][j][0], dp[h][j - 1][0]  + add - ((s[i] - s[h])));
					dp[i][j][1] = max(dp[i][j][1], dp[h][j - 1][0]  + add + ((s[i] - s[h])));
					
			
					
					dp[i][j][0] = max(dp[i][j][0], dp[h][j - 1][1]  - add - ((s[i] - s[h])));
					dp[i][j][1] = max(dp[i][j][1], dp[h][j - 1][1]  - add + ((s[i] - s[h])));
				}
			}
			
			
			
		}
	}
	
	cout << ans << endl;

	return 0;
}