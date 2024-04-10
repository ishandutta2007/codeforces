#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

class Blossom {
public:
	const static int N = 1000 + 10;
	int mate[N], n, ret;
	int run(int n, const vector<int> G[]) {
		this->n = n;
		memset(mate, -1, sizeof(mate[0]) * n);
		for (int i = 0; i < n; i++) if (mate[i] == -1) aug(i, G);
		for (int i = ret = 0; i < n; i++) ret += (mate[i] > i);
		return ret;
	}
private:
	int next[N], dsu[N], mark[N], vis[N];
	queue<int> Q;
	int get(int x) {
		return (x == dsu[x]) ? x : (dsu[x] = get(dsu[x]));
	}
	void merge(int a, int b) {
		dsu[get(a)] = get(b);
	}
	int lca(int x, int y) {
		static int t = 0;
		++t;
		for (; ; swap(x, y)) if (x != -1) {
			if (vis[x = get(x)] == t) return x;
			vis[x] = t;
			x = (mate[x] != -1) ? next[mate[x]] : -1;
		}
	}
	void group(int a, int p) {
		for (int b, c; a != p; merge(a, b), merge(b, c), a = c) {
			b = mate[a], c = next[b];
			if (get(c) != p) next[c] = b;
			if (mark[b] == 2) mark[b] = 1, Q.push(b);
			if (mark[c] == 2) mark[c] = 1, Q.push(c);
		}
	}
	void aug(int s, const vector<int> G[]) {
		for (int i = 0; i < n; i++) next[i] = vis[i] = -1, dsu[i] = i, mark[i] = 0;
		while (!Q.empty()) Q.pop();
		Q.push(s);
		mark[s] = 1;
		while (mate[s] == -1 && !Q.empty()) {
			int x = Q.front();
			Q.pop();
			for (int y : G[x]) {
				if (y != mate[x] && get(x) != get(y) && mark[y] != 2) {
					if (mark[y] == 1) {
						int p = lca(x, y);
						if (get(x) != p) next[x] = y;
						if (get(y) != p) next[y] = x;
						group(x, p);
						group(y, p);
					}
					else if (mate[y] == -1) {
						next[y] = x;
						for (int j = y, k, l; j != -1; j = l) {
							k = next[j];
							l = mate[k];
							mate[j] = k;
							mate[k] = j;
						}
						break;
					}
					else {
						next[y] = x;
						Q.push(mate[y]);
						mark[mate[y]] = 1;
						mark[y] = 2;
					}
				}
			}
		}
	}
} T;

char p[210][210];
vector<int>G[310];
void Add_Edge(int a, int b) {
	G[a].push_back(b);
	G[b].push_back(a);
}
void Solve() {
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", p[i]);
	}
	for (i = 0; i <= 300; i++)G[i].clear();
	for (i = 0; i < n; i++) {
		Add_Edge(i, i + n);
		for (j = 0; j < m; j++) {
			if (p[i][j] == '1') {
				Add_Edge(i, j + n * 2);
				Add_Edge(i + n, j + n * 2);
			}
		}
	}
	printf("%d\n", T.run(n * 2 + m, G) - n);
}

int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}