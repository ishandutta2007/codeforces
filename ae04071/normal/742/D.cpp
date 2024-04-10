#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>

const long long INF = 1e15;

struct Node{
	int w;
	long long b;
	Node() {}
	Node(int w, long long b) : w(w), b(b) {}
};

int n, m, w;
int ww[1000];
long long b[1000];

std::vector<int> adj[1000];
std::vector<Node> pp[1000];
int size;
bool vis[1000];

long long cache[1010][1010];

void DFS(int node, int idx)
{
	vis[node] = true;
	pp[idx].push_back(Node(ww[node], b[node]));

	for (auto &it : adj[node]) {
		if (!vis[it]) DFS(it, idx);
	}
}

long long DP(int idx, int we)
{
	if (we > w) return -INF;
	if (idx >= size) return 0;

	long long &ret = cache[idx][we];
	if (ret != -1) return ret;

	ret = 0;
	ret = std::max(ret, DP(idx + 1, we));

	long long bsum = 0;
	int wsum = 0;
	for (auto &it : pp[idx]) {
		wsum += it.w; bsum += it.b;
		ret = std::max(ret, DP(idx + 1, we + it.w) + it.b);
	}
	ret = std::max(ret, DP(idx + 1, we + wsum) + bsum);

	return ret;
}

int main()
{
	scanf("%d %d %d", &n, &m, &w);
	for (int i = 0; i<n; i++) scanf("%d", ww + i);
	for (int i = 0; i<n; i++) scanf("%I64d", b + i);

	int a, c;
	for (int i = 0; i<m; i++) {
		scanf("%d %d", &a, &c);
		a--; c--;
		adj[a].push_back(c);
		adj[c].push_back(a);
	}

	for (int i = 0; i<n; i++) {
		if (!vis[i]) {
			DFS(i, size);
			size++;
		}
	}
	memset(cache, -1, sizeof(cache));

	printf("%I64d\n", DP(0, 0));

	return 0;
}