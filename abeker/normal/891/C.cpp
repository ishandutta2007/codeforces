#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5e5 + 5;

struct dsu {
	int dad[MAXN], rnk[MAXN];
	void makeset(vector <int> nodes) {
		for (auto it : nodes) {
			dad[it] = it;
			rnk[it] = 0;
		}
	}
	int find(int x) {
		return dad[x] == x ? x : dad[x] = find(dad[x]);
	}
	bool join(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (rnk[x] > rnk[y])
			swap(x, y);
		dad[x] = y;
		rnk[y] += rnk[x] == rnk[y];
		return true;
	}
};

int N, M, Q;
int u[MAXN], v[MAXN], w[MAXN];
vector <pii> queries[MAXN];
vector <pii> toadd[MAXN];
bool ans[MAXN];
dsu global, part;

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d%d", u + i, v + i, w + i);
		toadd[w[i]].push_back({u[i], v[i]});
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int edge;
			scanf("%d", &edge);
			edge--;
			queries[w[edge]].push_back({i, edge});			
		}
	}
}

void work(vector <pii> E) {
	vector <int> nodes;
	for (auto it : E) {
		int x = global.find(u[it.second]);
		int y = global.find(v[it.second]);
		nodes.push_back(x);
		nodes.push_back(y);
		if (!part.join(x, y)) {
			ans[it.first] = false;
			break;
		}
	}
	part.makeset(nodes);
}

void solve() {
	for (int i = 0; i < Q; i++)
		ans[i] = true;
		
	vector <int> all;
	for (int i = 1; i <= N; i++)
		all.push_back(i);
		
	global.makeset(all);
	part.makeset(all);
	
	for (int i = 0; i < MAXN; i++) {
		sort(queries[i].begin(), queries[i].end());
		vector <pii> tmp;
		for (int j = 0; j < queries[i].size(); j++) {
			if (j && queries[i][j].first != queries[i][j - 1].first) {
				work(tmp);
				tmp.clear();
			}
			tmp.push_back(queries[i][j]);
		}
		work(tmp);
		
		for (auto it : toadd[i])
			global.join(it.first, it.second);
	}
	
	for (int i = 0; i < Q; i++)
		puts(ans[i] ? "YES" : "NO");
}

int main() {
	load();
	solve();
	return 0;
}