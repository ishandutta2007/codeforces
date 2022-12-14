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
struct edge
{
	int to, id;
	edge()
	{
		to = 0;
		id = 0;
	}
	edge(int _to, int _id)
	{
		to = _to;
		id = _id;
	}
};
const int MAXN = 200 * 1000 + 7;
vector<edge>g[MAXN];
vector<int>ans[MAXN];
bool used[MAXN];
int edgeAns[MAXN];
void dfs(int v, int last = -1)
{
	used[v] = true;
	int go = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i].to;
		if (!used[to])
		{
			if (go == last) go++;
			edgeAns[g[v][i].id] = go;
			dfs(to, go);
			go++;
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(edge(v, i));
		g[v].push_back(edge(u, i));
	}
	dfs(1);
	int ansVal = 0;
	for (int i = 1; i < n; i++)
	{
		ans[edgeAns[i]].push_back(i);
		ansVal = max(ansVal, edgeAns[i]);
	}
	printf("%d\n", ansVal);
	for (int i = 1; i <= ansVal; i++)
	{
		printf("%d ", (int)ans[i].size());
		for (int j = 0; j < (int)ans[i].size(); j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}