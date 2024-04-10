#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define fst first
#define snd second
#define ld long double

int n, k, m;
ll dp[303][303];
vector < pair < int , int > > b[303];
int can[303][303];
int was[303][303];

ll rec(int t, int h)
{
	if (t == 0)	
		return 0;
	if (h == 0)
		return 0;
	
	if (dp[t][h] != -1 || was[t][h])
		return dp[t][h];
	int curr = 1000000001;
	ll& ans = dp[t][h];
	int next, j;
	for (int i = 0; i < b[t].size(); i++)
	{
		curr = min(curr, b[t][i].snd);
		j = b[t][i].fst;
		if (i != b[t].size()-1)
		{
			next = b[t][i+1].fst;
		}
		else
		{
			next = t+1;
		}
		while (j < next)
		{
			rec(j-1, max(0, h - (t-j+1)));
			if (can[j-1][max(0, h - (t-j+1))])
			{
				if (!can[t][h])
					ans = dp[j-1][max(0, h - (t-j+1))] + curr;
				else
					ans = min(ans, dp[j-1][max(0, h - (t-j+1))] + curr);
				can[t][h] = 1;
			}
			j++;
		}
	}
	
	rec(t-1, h);
	if (can[t-1][h])
	{
		if (!can[t][h])
			ans = dp[t-1][h];
		ans = min(ans, dp[t-1][h]);
		can[t][h] = 1;
	}
	was[t][h] = 1;
	return ans;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		int l, r, c;
		scanf("%d %d %d", &l, &r, &c);
		b[r].pb(mp(l, c));
	}
	
	for (int i = 1; i <= n; i++)
		sort(b[i].begin(), b[i].end());
		
	
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <=n; j++)
			dp[i][j] = -1;
	for (int i = 0; i <= n; i++)
	{
		can[i][0] = 1;
		dp[i][0] = 0;
	}
		
		
	cout << rec(n, k);
	
	
	
}