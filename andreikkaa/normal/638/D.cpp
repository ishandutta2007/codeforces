#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<cmath>
#include<bitset>
#include<cassert>
#include<queue>
#include<stack>
#include<deque>
#include<cassert>
using namespace std;
const int MAXN = 102;
int a[MAXN][MAXN][MAXN];
int number[MAXN][MAXN][MAXN];
char buf[MAXN];
vector<int>g[MAXN*MAXN*MAXN];
vector<int>revg[MAXN*MAXN*MAXN];
vector<int>gg[MAXN*MAXN*MAXN];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, p;
	scanf("%d %d %d", &n, &m, &p);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%s", buf);
			for (int k = 1; k <= p; k++)
			{
				if (buf[k - 1] == '1')
				{
					a[i][j][k] = 1;
				}
				cnt++;
				number[i][j][k] = cnt;				
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= p; k++)
			{
				if (a[i][j][k] == 0) continue;
				if (a[i + 1][j][k] == 1)
				{
					g[number[i][j][k]].push_back(number[i + 1][j][k]);
					revg[number[i + 1][j][k]].push_back(number[i][j][k]);
				}
				if (a[i][j + 1][k] == 1)
				{
					g[number[i][j][k]].push_back(number[i][j + 1][k]);
					revg[number[i][j + 1][k]].push_back(number[i][j][k]);
				}
				if (a[i][j][k + 1] == 1)
				{
					g[number[i][j][k]].push_back(number[i][j][k + 1]);
					revg[number[i][j][k + 1]].push_back(number[i][j][k]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= p; k++)
			{
				int v = number[i][j][k];
				for (int w = 0; w < (int)g[v].size(); w++)
				{
					int q = g[v][w];
					for (int z = 0; z < (int)g[q].size(); z++)
					{
						int to = g[q][z];
						gg[v].push_back(to);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int v = 1; v <= cnt; v++)
	{
		bool ok = true;
		for (int i = 0; i < (int)revg[v].size(); i++)
		{
			int parent = revg[v][i];
			for (int j = 0; j < (int)g[v].size(); j++)
			{
				int to = g[v][j];
				int cnt = 0;
				for (int k = 0; k < (int)gg[parent].size(); k++)
				{
					int w = gg[parent][k];
					if (w == to) cnt++;
				}
				if (cnt <= 1)
				{
					ok = false;
					break;
				}
			}
			if (!ok)
			{
				break;
			}
		}
		if (!ok)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
}