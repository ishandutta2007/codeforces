#include <bits/stdc++.h>

using namespace std;

const int MX = 1000;

namespace bipartite_matching {
	const int LEFT = MX * MX, RIGHT = MX * MX;
	
	vector<int> G[LEFT];
	int paired[LEFT], parent[RIGHT];
	bool used[LEFT], coverL[LEFT], coverR[RIGHT];
	
	bool dfs(int v) {
		if (used[v]) return false;
		used[v] = true;
		coverL[v] = false;
		for (int u : G[v]) {
			if (parent[u] == -1 || dfs(parent[u])) {
				paired[v] = u;
				parent[u] = v;
				return true;
			}
			
			coverR[u] = true;
		}
		return false;
	}
	
	int find(int left, int right) {
		memset(paired, -1, sizeof(int) * left);
		memset(parent, -1, sizeof(int) * right);
		bool run = true;
		int size = 0;
		while (run) {
			memset(used, 0, sizeof(bool) * left);
			run = false;
			for (int i = 0; i < left; i++)
				if (paired[i] == -1 && dfs(i)) {
					size++;
					run = true;
				}
		}
		return size;
	}
	
	void cover(int left, int right) {
		find(left, right);
		
		fill(coverL, coverL + left, true);
		memset(coverR, 0, sizeof coverR);
		memset(used, 0, sizeof(bool) * left);
		for (int i = 0; i < left; i++)
			if (paired[i] == -1)
				dfs(i);
	}
}

int x[MX], y[MX];

int main() {
	int n;
	ignore = scanf("%d", &n);
	
	map<int, vector<int>> row, col;
	set<int> xs, ys;
	for (int i = 0; i < n; i++) {
		ignore = scanf("%d %d", x + i, y + i);
		row[x[i]].push_back(y[i]);
		col[y[i]].push_back(x[i]);
		xs.insert(x[i]);
		ys.insert(y[i]);
	}
	
	map<pair<int, int>, int> id[2];
	auto getId = [&id](int f, int x, int y) {
		auto p = make_pair(x, y);
		if (id[f].count(p) == 0) {
			int v = id[f].size();
			id[f][p] = v;
		}
		
		return id[f][p];
	};
	
	for (auto& p : col) sort(p.second.begin(), p.second.end());
	
	for (int x : xs) {
		auto& vec = row[x];
		sort(vec.begin(), vec.end());
		size_t i = 0;
		for (int y : ys) {
			if (y <= vec[i]) continue;
			if (i + 1 == vec.size()) break;
			if (y == vec[i + 1]) {
				i++;
				continue;
			}
			
			if (x < col[y][0] || x > col[y].back()) continue;
			
			int xx = *prev(lower_bound(col[y].begin(), col[y].end(), x));
			
			int h = getId(0, x, vec[i]);
			int v = getId(1, y, xx);
			
			bipartite_matching::G[h].push_back(v);
		}
	}
	
	bipartite_matching::cover(id[0].size(), id[1].size());
	
	vector<tuple<int, int, int, int>> h, v;
	
	for (int x : xs) {
		auto& vec = row[x];
		
		int prev = -1;
		for (int y : vec) {
			if (bipartite_matching::coverL[getId(0, x, y)]) {
				if (prev == -1) prev = y;
				v.emplace_back(x, prev, x, y);
				prev = -1;
				continue;
			}
			
			if (prev == -1) prev = y;
		}
		
		if (prev != -1) v.emplace_back(x, prev, x, vec.back());
	}
	
	for (int y : ys) {
		auto& vec = col[y];
		
		int prev = -1;
		for (int x : vec) {
			if (bipartite_matching::coverR[getId(1, y, x)]) {
				if (prev == -1) prev = x;
				h.emplace_back(prev, y, x, y);
				prev = -1;
				continue;
			}
			
			if (prev == -1) prev = x;
		}
		
		if (prev != -1) h.emplace_back(prev, y, vec.back(), y);
	}
	
	printf("%d\n", (int)h.size());
	for (auto& p : h) {
		int a, b, c, d;
		tie(a, b, c, d) = p;
		printf("%d %d %d %d\n", a, b, c, d);
	}
	
	printf("%d\n", (int)v.size());
	for (auto& p : v) {
		int a, b, c, d;
		tie(a, b, c, d) = p;
		printf("%d %d %d %d\n", a, b, c, d);
	}
	
	return 0;
}