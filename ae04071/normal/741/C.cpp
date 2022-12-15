#include <stdio.h>
#include <vector>

int n;
std::vector<int> adj[200001];
bool vis[200001];
int color[200001];

int boy[100000], girl[100000];

bool DFS(int node, int c)
{
	vis[node] = true; color[node] = c;
	for (auto &it : adj[node]){
		if (!vis[it]) {
			if (!DFS(it, (c + 1) % 2)) return false;
		}
		else if (color[it] == c) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i<n; i++) {
		scanf("%d %d", &a, &b);
		boy[i] = a, girl[i] = b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= 2*n; i+=2) {
		adj[i].push_back(i+1);
		adj[i+1].push_back(i);
	}

	for(int i=1;i<=2*n;i++){
		if(!vis[i]) if(!DFS(i,0)) {
			printf("-1\n");
			return 0;
		}
	}
	{
		for (int i = 0; i<n; i++) printf("%d %d\n", color[boy[i]] + 1, color[girl[i]] + 1);
	}

	return 0;
}