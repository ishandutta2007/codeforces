#include <bits/stdc++.h>
using namespace std;

typedef unordered_map <int, int> umap;

int U, V, P;
umap distU, dadU, opU, distV, dadV, opV;
queue <int> Q;

void load() {
	scanf("%d%d%d", &U, &V, &P);
}

inline int add(int x, int y) {
	x += y;
	if (x >= P)	
		x -= P;
	else if (x < 0)
		x += P;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % P;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

void bfs(int num, umap &dist, umap &dad, umap &op) {
	queue <int> Q;
	Q.push(num);
	while (!Q.empty() && dist.size() < 1e5) {
		int x = Q.front();
		Q.pop();
		vector <int> v = {add(x, 1), add(x, -1), pot(x, P - 2)};
		for (int i = 0; i < 3; i++) {
			if (v[i] == num || dist[v[i]])
				continue;
			Q.push(v[i]);
			dist[v[i]] = dist[x] + 1;
			dad[v[i]] = x;
			op[v[i]] = i + 1;
		}
	}
}

vector <int> reconstruct(int src, int x, umap &dad, umap &op) {
	vector <int> ans;
	for (; x != src; x = dad[x])
		ans.push_back(op[x]);
	reverse(ans.begin(), ans.end());
	return ans;
}

void solve() {
	bfs(U, distU, dadU, opU);
	bfs(V, distV, dadV, opV);
	
	for (auto it : distU)
		for (int i = -60; i <= 60; i++) {
			int curr = add(it.first, i);
			int rest = distV[curr];
			if ((curr == V || rest) && it.second + abs(i) + rest <= 200) {
				vector <int> u = reconstruct(U, it.first, dadU, opU);
				vector <int> v = reconstruct(V, curr, dadV, opV);
				reverse(v.begin(), v.end());
				for (int j = 0; j < abs(i); j++)
					u.push_back(i > 0 ? 1 : 2);
				for (auto it : v)
					u.push_back(it < 3 ? 3 - it : it);
				printf("%d\n", u.size());
				for (auto it1 : u)
					printf("%d ", it1);
				puts("");
				return;
			}
		}
}

int main() {
	load();
	solve();
	return 0;
}