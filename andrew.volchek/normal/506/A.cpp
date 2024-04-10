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


const int maxn = 30005;
const int zero = 303;

int a[maxn];

int dp[maxn][605];
int can[maxn][605];


int main()
{
	//gen();
	//freopen("a.in", "r", stdin);
	//srand(time(NULL));
	
	int n, d;
	scanf("%d %d", &n, &d);
	
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	
	can[d][zero] = 1;
	dp[d][zero] = a[d];
	
	int ans = 0;
	
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < 605; j++)
		{
			if (!can[i][j])
				continue;
				
			ans = max(ans, dp[i][j]);
				
			int v = d + j - zero;
			
			if (i + v < maxn)
			{
				dp[i + v][j] = max(dp[i + v][j], dp[i][j] + a[i + v]);
				can[i + v][j] = 1;
			}
			
			if (i + v + 1 < maxn)
			{
				dp[i + v + 1][j + 1] = max(dp[i + v + 1][j + 1], dp[i][j] + a[i + v + 1]);
				can[i + v + 1][j + 1] = 1;
			}
			
			if (v - 1 > 0 && i + v - 1 < maxn)
			{
				dp[i + v - 1][j - 1] = max(dp[i + v - 1][j - 1], dp[i][j] + a[i + v - 1]);
				can[i + v - 1][j - 1] = 1;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}