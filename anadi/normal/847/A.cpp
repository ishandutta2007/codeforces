#include<bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 1e5 + 7;

int n;
int cur[2];
int edge[N][2];
bool vis[N];
queue <PII> Q;

void dfs(int u, int dir){
	vis[u] = true;
	if(edge[u][dir])
		dfs(edge[u][dir], dir);
	else
		cur[dir] = u;
}

int main()
{
//	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &edge[i][0], &edge[i][1]);
	
	for(int i = 1; i <= n; ++i)
		if(!vis[i]){
			dfs(i, 0);
			dfs(i, 1);
			Q.push({cur[0], cur[1]});
		}
	
	while(Q.size() > 1){
		PII k1 = Q.front();
		Q.pop();
		PII k2 = Q.front();
		Q.pop();
		
		edge[k1.nd][1] = k2.st;
		edge[k2.st][0] = k1.nd;
		Q.push({k1.st, k2.nd});
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%d %d\n", edge[i][0], edge[i][1]);
	return 0;
}