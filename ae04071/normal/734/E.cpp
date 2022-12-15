#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

typedef std::pair<int, int> iPair;

int n;
int color[200001];
std::vector<int> adj[200001];

bool vis[200001];
int pa[200001];

iPair depth[200001];

int minDist = 987654321;

int con[200001];
int size;

void Merge(int node, int root) {
	vis[node] = true;
	pa[node] = root;
	for (auto &it : adj[node]){
		if (color[it] == color[node] && !vis[it]) Merge(it, root);
		if (root != node && color[it] != color[node]) {
			con[size++] = it;
		}
	}
}

int GetDepth(int node) {
	vis[node] = true;
	for (auto &it : adj[node]) {
		if (pa[it] == it && !vis[it]) {
			int num = GetDepth(it);
			if (num > depth[node].first) {
				depth[node].second = depth[node].first;
				depth[node].first = num;
			}
			else if (num > depth[node].second) {
				depth[node].second = num;
			}
		}
	}

	return depth[node].first + 1;
}

void FindMax(int node, int dist, bool isRoot) {
	vis[node] = true;
	if (isRoot) {
		if (minDist > depth[node].first) minDist = depth[node].first;
		dist = depth[node].first;
	}
	else {
		if (dist >= minDist) return;
		int max = std::max(depth[node].first, dist);
		if (minDist > max) minDist = max;
		if (dist < depth[node].second) dist = depth[node].second;
	}
	for (auto &it : adj[node]) {
		if (pa[it] == it && !vis[it]) {
			if (depth[it].first + 1 == depth[node].first){
				if (isRoot)
					FindMax(it, depth[node].second + 1, false);
				else
					FindMax(it, dist + 1, false);
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", color + i);
	
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int root = -1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			size = 0;
			Merge(i, i);
			if (root == -1) root = i;
			for (int j = 0; j < size; j++) {
				adj[i].push_back(con[j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (pa[i] != i) continue;
		for (auto &it : adj[i])
			it = pa[it];
	}

	std::fill(vis, vis + n + 1, false);
	GetDepth(root);

	std::fill(vis, vis + n + 1, false);
	FindMax(root, -1, true);

	printf("%d\n", minDist);

	return 0;
}