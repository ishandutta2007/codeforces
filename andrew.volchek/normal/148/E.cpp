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
#include <bitset>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define fst first
#define snd second
#define ld long double

int shelfCnt[105];
int shelfCntSum[105];
vector < int > shelfs[105];
int shelfPartialSums[105][105];
int shelfSum[105][105];
int dp[10005][105];

int main(int argc, char **argv)
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", shelfCnt + i);
		for (int j = 0; j < shelfCnt[i]; j++)
		{
			int x; 
			scanf("%d", &x);
			shelfs[i].pb(x);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		shelfPartialSums[i][0] = 0;
		for (int j = 0; j < shelfs[i].size(); j++)
		{
			shelfPartialSums[i][j+1] = shelfPartialSums[i][j] + shelfs[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= shelfCnt[i]; j++)
		{
			int curr = 0;
			for (int l = 0; l <= j; l++)
			{
				curr = max(curr, shelfPartialSums[i][l] + shelfPartialSums[i][shelfCnt[i]]
				 - shelfPartialSums[i][shelfCnt[i] - j + l]);
			}
			shelfSum[i][j] = curr;
		}
	}
	
	shelfCntSum[0] = shelfCnt[0];
	for (int i = 1; i < n; i++)
		shelfCntSum[i] = shelfCntSum[i-1] + shelfCnt[i];
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i > shelfCntSum[j-1])
				continue;
				
			dp[i][j] = 0;
			for (int h = 0; h <= shelfCnt[j-1]; h++)
			{
				if (h > i)
					break;
				dp[i][j] = max(dp[i][j], dp[i - h][j-1] + shelfSum[j-1][h]);
			}
		}
	}
	
	cout << dp[m][n];
	
	return 0;
}