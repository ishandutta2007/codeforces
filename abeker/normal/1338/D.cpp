#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

class TwoMax {
	int mx1, mx2;
	public:
		TwoMax() {
			mx1 = mx2 = 0;
		}
		void update(int val) {
			if (val >= mx1) {
				mx2 = mx1;
				mx1 = val;
			}
			else if (val > mx2)
				mx2 = val;
		}
		int sum() const {
			return mx1 + mx2;
		}
};

int N;
vector <int> adj[MAXN];
int down[MAXN][2];

void load() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int dfs(int x, int p) {
	int res = 0;
	TwoMax all, zero;
	for (auto it : adj[x])
		if (it != p) {
			res = max(res, dfs(it, x));
			int both = max(down[it][0], down[it][1]);
			all.update(both);
			zero.update(down[it][0]);
			down[x][0] = max(down[x][0], both);
			down[x][1] = max(down[x][1], down[it][0]);
		}
	int cost = (int)adj[x].size() - 2;
	down[x][0] += cost;
	down[x][1]++;
	return max(max(zero.sum() + 1, all.sum() + cost), res);
}

int main() {
	load();
	printf("%d\n", max(dfs(1, 0), 1));	
	return 0;
}