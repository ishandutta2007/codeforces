#include <stdio.h>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

vector<int> graph[112345];
vector<int> h[112345];
vector<int> diam[112345];
int maxdiam[112345][2];
int maxh[112345][3];

void change_maxh(int a, int x)
{
	if(x > maxh[a][2])
		maxh[a][2] = x;
	if(maxh[a][2] > maxh[a][1])
		swap(maxh[a][2], maxh[a][1]);
	if(maxh[a][1] > maxh[a][0])
		swap(maxh[a][1], maxh[a][0]);
}

void change_maxdiam(int a, int x)
{
	if(x > maxdiam[a][1])
		maxdiam[a][1] = x;
	if(maxdiam[a][1] > maxdiam[a][0])
		swap(maxdiam[a][1], maxdiam[a][0]);	
}

pair<int, int> dfs(int a, int p)
{
	for(int i = 0; i < graph[a].size(); i++)
		if(graph[a][i] != p)
		{
			pii x = dfs(graph[a][i], a);
			h[a][i] = x.first + 1;
			diam[a][i] = x.second;
			change_maxdiam(a, diam[a][i]);			
			change_maxh(a, h[a][i]);
		}
	return pii(maxh[a][0], max(maxdiam[a][0], maxh[a][0] + maxh[a][1]));
}

int solve(int a, int p)
{
	int retv = 0;
	for(int i = 0; i < graph[a].size(); i++)
		if(graph[a][i] != p)
		{
			int x = diam[a][i];
			int y = (maxdiam[a][0] == diam[a][i]) ? maxdiam[a][1] : maxdiam[a][0];
			int z = (h[a][i] == maxh[a][0]) ? (maxh[a][1] + maxh[a][2]) : (maxh[a][0] + ((maxh[a][1] == h[a][i]) ? maxh[a][2] : maxh[a][1]));
			retv = max(retv, x * max(y, z));

			change_maxh(graph[a][i], (h[a][i] == maxh[a][0]) ? (maxh[a][1] + 1) : (maxh[a][0] + 1));
			change_maxdiam(graph[a][i], max(y, z));

			retv = max(retv, solve(graph[a][i], a));
		}
	return retv;
}

int main(void)
{
	int n, a, b;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		h[a].push_back(0);
		diam[a].push_back(0);
		graph[b].push_back(a);
		h[b].push_back(0);
		diam[b].push_back(0);		
	}
	dfs(1, 0);
	printf("%d\n", solve(1, 0));
}