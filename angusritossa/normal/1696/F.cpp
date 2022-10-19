#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 110

int d[MAXN][MAXN][MAXN]; // x, y, z

vector<int> adj[MAXN];
int isIn[MAXN], n;

int dis[MAXN][MAXN];
void findDis(int a, int b, int par = -1, int D = 0) {
	dis[a][b] = D;
	for (auto c : adj[b]) {
		if (c != par) {
			findDis(a, c, b, D+1);
		}
	}
}

bool makeTree(int a, int b) {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		isIn[i] = false;
	}
	isIn[a] = isIn[b] = true;
	adj[a].push_back(b);
	adj[b].push_back(a);
	vector<int> t = { a, b };
	for (int i = 0; i < (int)t.size(); i++) {
		bool found = 0;
		int node = t[i];
		for (int j = 1; j <= n; j++) {
			if (isIn[j]) continue;
			bool good = true;
			// consider attaching j to node
			for (auto x : adj[node]) {
				if (!d[x][j][node]) {
					good = false;
				}
				break;
			}
			if (good) {
				found = true;
				isIn[j] = true;
				t.push_back(j);
				adj[node].push_back(j);
				adj[j].push_back(node);
				break;
			}
		}
		if (found) i--;
	}

	if ((int)t.size() < n) return false;

	for (int i = 1; i <= n; i++) {
		findDis(i, i);
	}

	for (int x = 1; x <= n; x++) {
		for (int y = x+1; y <= n; y++) {
			for (int z = 1; z <= n; z++) {
				int res1 = dis[x][z] == dis[y][z];
				if (!!res1 != !!d[x][y][z]) return false;
			}
		}
	}

	printf("Yes\n");
	for (int i = 1; i <= n; i++) {
		for (auto j : adj[i]) {
			if (j > i) {
				printf("%d %d\n", i, j);
			}
		}
	}

	return true;
}

void solve() {
	scanf("%d", &n);
	for (int x = 1; x <= n; x++) {
		for (int y = x+1; y <= n; y++) {
			for (int z = 1; z <= n; z++) {
				char c;
				scanf(" %c", &c);
				d[x][y][z] = c == '1';
				d[y][x][z] = c == '1';
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (makeTree(1, i)) return;
	}
	printf("No\n");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}