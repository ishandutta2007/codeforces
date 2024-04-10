#include <stdio.h>
#include <vector>
using namespace std;

vector<int> graph[212345];
int nf = 0;

int dfs(int a, int tp,int tp2)
{
	if(graph[a].size() == 0)
	{
		nf++;
		return 1;
	}
	int retv = tp2 * tp;
	for(int i = 0; i < graph[a].size(); i++)
		if(tp)
		{
			if(tp2 == 0)
				retv = max(retv, dfs(graph[a][i], tp ^1 , tp2));
			else
				retv = min(retv, dfs(graph[a][i], tp ^1 , tp2));
		}
		else	
			retv += dfs(graph[a][i], tp ^ 1, tp2);
	return retv;
}

int
main(void)
{
	int n,a ,b ;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++)
	{
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}
	printf("%d %d\n", 1 + nf - dfs(1, 1, 0x3f3f3f3f), dfs(1, 0, 0x3f3f3f3f));
}