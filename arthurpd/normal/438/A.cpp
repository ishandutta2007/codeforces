#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

#define inf 0x3f3f3f3f

vector<int> graph[1123];
int v[1123];
int w[1123];
bool removed[1123];

int weight(int a)
{
	int retv = 0;
	return w[a] = v[a];
	for(int i = 0; i < graph[a].size(); i++)
		if(!removed[graph[a][i]])
			retv += (v[a] - v[graph[a][i]]);
	return w[a] = retv;
}

int cost(int a)
{
	int retv = 0;
	for(int i = 0; i < graph[a].size(); i++)
		if(!removed[graph[a][i]])
			retv += v[graph[a][i]];
	return retv;
}

int
main(void)
{
	int n, m, a, b;
	long long ans = 0;
	set<pair<int,int> > rdm;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 1; i <= n; i++)
	{
		rdm.insert(pair<int,int> (-weight(i), i));
//		printf("%d\n", w[i]);	
	}
	for(int i = 0; i < n; i++)
	{
		a = (rdm.begin()->second);
		rdm.erase(rdm.begin());
		ans += cost(a);
//		printf("%d\n", a);
//		printf("%d\n", w[a]);
		removed[a] = true;
		for(int i = 0; i < graph[a].size(); i++)
			if(!removed[graph[a][i]])
			{
				rdm.erase(rdm.find(pair<int,int> (-w[graph[a][i]], graph[a][i])));
				rdm.insert(pair<int,int> (-weight(graph[a][i]), graph[a][i]));
			}
	}
	cout << ans;
	return 0;
}