#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define mod 1000000007LL

int l, r;
int seq[2123];
pair<int,int> a[2123];
vector<int> graph[2123];

long long dfs(int a, int p)
{
	long long retv = 1;
	for(int i = 0; i < graph[a].size(); i++)
		if(graph[a][i] != p && l <= seq[graph[a][i]] && seq[graph[a][i]] <= r)
			retv = (retv * (1 + dfs(graph[a][i], a))) % mod;
	return retv;
}

int main(void)
{
	int d, n, u, v;
	int ans = 0;
	scanf("%d %d", &d, &n);
	for(int i = 0; i < n; a[i].second = i + 1, i++)
		scanf("%d", &a[i].first);

	for(int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	sort(a, a+n);
	for(int i = 0; i < n; i++)
		seq[a[i].second] = i;

	for(int i = 0, j = 0; i < n; i++)
	{
		while(j + 1 < n && a[j+1].first - a[i].first <= d)
			j++;
		l = i, r = j;
		ans = (ans + dfs(a[i].second, a[i].second)) % mod;
	}
	printf("%d\n", ans);
}