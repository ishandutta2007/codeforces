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


const int maxn = 1005;
int a[maxn];
int cnt[maxn];
vector < int > p;
int n, x;
bool bb;
int dfs(int v)
{
	if (v == x)
		bb = true;
	if (v == 0)
		return 0;
	return 1 + dfs(a[v]);
}
char dp[maxn+1][maxn+1];

int main(int argc, char **argv)
{
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i]] = 1;
	}
	
	int dd = dfs(x);
	
	for (int i = 1; i <= n; i++)
		if (i != x && cnt[i] == 0)
		{
			bb = false;
			int d = dfs(i);
			if (!bb)
				p.pb(d);
		}
	dp[0][0] = 1;
	
	for (int i = 1; i <= p.size(); i++)
	{
		for (int w = 0; w <= maxn; w++)
		{
			dp[w][i] = dp[w][i-1];
			if (w - p[i-1] >= 0)
			{
				dp[w][i] |= dp[w-p[i-1]][i-1];
			}
			
		}
	}
	set < int > s;
	s.insert(0);
	for (int i = 1; i <= maxn; i++)
		if (dp[i][p.size()])
			s.insert(i);
	for (set < int > :: iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it + dd << endl;
	}
	return 0;
}