#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#define N_ 101000
using namespace std;
typedef pair<int, int>pii;
int n, m, Deg[N_], PV[N_];
vector<int>E[N_], F[N_], G[N_], T[N_];
int SCC[N_], ord[N_], cnt, vis[N_];
set<int>Set;
void DFS1(int a) {
	vis[a] = 1;
	for (auto &x : E[a]) {
		if (!vis[x])DFS1(x);
	}
	ord[++cnt] = a;
}

void DFS2(int a) {
	SCC[a] = cnt;
	G[cnt].push_back(a);
	for (auto &x : F[a]) {
		if (!SCC[x])DFS2(x);
	}
}

int Query(int a, int b) {
	int x;
	printf("? %d %d\n", a, b);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}

int main() {
	int i, a, b, ck;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		F[b].push_back(a);
	}

	for (i = 1; i <= n; i++) {
		if (!vis[i])DFS1(i);
	}
	cnt = 0;
	for (i = n; i >= 1; i--) {
		if (!SCC[ord[i]]) {
			cnt++;
			DFS2(ord[i]);
		}
	}
	for (i = 1; i <= n; i++) {
		for (auto &x : E[i]) {
			if (SCC[i] != SCC[x]) {
				T[SCC[i]].push_back(SCC[x]);
				Deg[SCC[x]]++;
			}
		}
	}
	for (i = 1; i <= cnt; i++) {
		if (!Deg[i])Set.insert(i);
	}
	a = G[*Set.begin()][0];
	while (Set.size() > 1) {
		auto it = Set.begin();
		if (SCC[a] == *it) {
			it++;
		}
		int x = *it;
		b = G[x][PV[x]];
		if (Query(a, b) == 0) {
			x = SCC[a];
			a = b;
		}
		PV[x]++;
		if (PV[x] == G[x].size()) {
			Set.erase(x);
			for (auto &t : T[x]) {
				Deg[t]--;
				if (!Deg[t])Set.insert(t);
			}
		}
	}
	printf("! %d\n", a);
}