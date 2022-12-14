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
vector<int>g[27];
char buf[129];
bool used[27];
bool was[29];
int inDeg[29];
vector<int>topsort;
void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
		{
			dfs(to);
		}
	}
	topsort.push_back(v);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", buf);
		int m = strlen(buf);
		for (int j = 0; j < m; j++)
		{
			was[buf[j] - 'a'] = true;
		}
		for (int j = 0; j < m - 1; j++)
		{
			g[buf[j] - 'a'].push_back(buf[j + 1] - 'a');
			inDeg[buf[j + 1] - 'a']++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (!used[i] && was[i] && inDeg[i] == 0)
		{
			dfs(i);
		}
	}
	reverse(topsort.begin(), topsort.end());
	for (int i = 0; i < (int)topsort.size(); i++)
	{
		printf("%c", 'a' + topsort[i]);
	}
	printf("\n");
}