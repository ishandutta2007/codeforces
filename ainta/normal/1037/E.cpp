#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define N_ 201000
int Q[N_], Deg[N_], n, m, K, head, tail, vis[N_], Res[N_];
set<int>Set[N_];
struct Edge {
	int a, b;
}w[N_];
void Put(int a) {
	if (vis[a] || Deg[a] >= K)return;
	vis[a] = 1;
	Q[++tail] = a;
}
int main() {
	int i;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &w[i].a, &w[i].b);
		Set[w[i].a].insert(w[i].b);
		Set[w[i].b].insert(w[i].a);
		Deg[w[i].a]++;
		Deg[w[i].b]++;
	}
	for (i = 1; i <= n; i++) {
		Put(i);
	}
	for (i = m; i >= 1; i--) {
		while (head < tail) {
			int x = Q[++head];
			for (auto &y : Set[x]) {
				Deg[y]--;
				Set[y].erase(x);
				Put(y);
			}
		}
		Res[i] = n - tail;
		if (!vis[w[i].a] && !vis[w[i].b]) {
			Deg[w[i].a]--;
			Deg[w[i].b]--;
			Put(w[i].a);
			Put(w[i].b);
			Set[w[i].a].erase(w[i].b);
			Set[w[i].b].erase(w[i].a);
		}
	}
	for (i = 1; i <= m; i++)printf("%d\n", Res[i]);
}