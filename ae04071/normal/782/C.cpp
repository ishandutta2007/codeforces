#include <stdio.h>
#include <vector>

int n;
std::vector<int> adj[200001];
int color[200001], max=0;
void DFS(int node, int p) {
	int sum=adj[node].size()+1;
	if(max<sum)max=sum;
	for(auto &it:adj[node]) {
		if(it==p) continue;
		DFS(it, node);
	}
}
void Color(int node, int p, int c) {
	color[node]=c;
	for(auto &it:adj[node]) {
		if(it==p) continue;
		while(color[node]==c||color[p]==c) {
			c++;
			c%=max;
		}
		Color(it, node, c%max);
		c++;
		c%=max;
	}
}

int main() {
	scanf("%d",&n);
	int u,v;
	for(int i=0;i<n-1;i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	color[0]=-1;
	DFS(1,0);
	Color(1,0,0);
	printf("%d\n",max);
	for(int i=1;i<=n;i++) {
		printf("%d ",color[i]+1);
	}
	return 0;
}