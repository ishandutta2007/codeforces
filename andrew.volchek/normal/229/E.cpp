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

ld dp[1005][1005];
ld c[1005][1005];
vector < int > a[1005], b;

int main(int argc, char *argv[])
{
	//freopen("a.in", "r", stdin);
	
	for (int i = 0; i < 1005; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 1; i < 1005; i++)
	{
		for (int j = 1; j < i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		int k;
		cin >> k;
		
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			b.pb(x);
			a[i].pb(x);
		}
		
		sort(a[i].begin(), a[i].end());
	}
	
	sort(b.begin(), b.end());
	n = min(n, (int)b.size());
	
	int x = b[b.size() - n];
	int g = 0;
	for (int i = b.size() - n; i < b.size(); i++)
		if (b[i] == x)
			g++;
		else
			break;
	
	dp[0][0] = 1;
	
	int cnt = 0;
	
	for (int i = 1; i <= m; i++)
	{
		int p = 0;
		while (p < a[i].size() && a[i][p] < x) p++;
		
		if (p == a[i].size())
		{
			for (int j = 0; j < 1005; j++)
				dp[i][j] = dp[i - 1][j];
		}
		else
		{
			for (int iter = 0; iter < 2; iter++)
			{
				for (int j = (p < a[i].size() && a[i][p] == x); j < 1005; j++)
				{
					assert(p <= a[i].size());
					if (p < a[i].size() && a[i][p] == x)
						dp[i][j] += dp[i - 1][j - 1] / c[a[i].size()][a[i].size() - p];
					else
						dp[i][j] += dp[i - 1][j] / c[a[i].size()][a[i].size() - p];
				}
				
				if (!iter && a[i][p] == x)
				{
					p++;
					cnt++;
				}
				else
					break;
			}
		}
	}
	
	cout.precision(10);
	
	cout << fixed << dp[m][g] / c[cnt][g] << endl;
	
	return 0;
}