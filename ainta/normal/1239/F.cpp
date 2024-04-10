#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<bitset>
#include<map>
using namespace std;
#define N_ 501000
int n, m, Deg[N_], vis[N_], par[N_], MM[N_], TP[N_], Com[N_], ct, CC[N_];
vector<int>E[N_], F[N_];
void Print(int a, int pp) {
	int i;
	for (i = 1; i <= n; i++)MM[i] = 0;
	int cc = 0;
	MM[a] = ++cc;
	TP[cc] = a;
	while (1) {
		int t = par[a];
		MM[t] = ++cc;
		TP[cc] = t;
		int Mx = -1;
		for (auto &x : F[t]) {
			if (MM[x] && x != a) {
				Mx = max(Mx, MM[x]);
			}
		}
		if (Mx != -1) {
			for (i = 1; i <= n; i++)MM[i] = 0;
			for (i = Mx; i <= cc; i++) {
				MM[TP[i]] = 1;
			}
			vector<int>RR;
			for (i = 1; i <= n; i++)if (!MM[i])RR.push_back(i);
			if (RR.size() == n || RR.size() == 0) {
				puts("No");
				return;
			}
			puts("Yes");
			printf("%d\n", RR.size());
			for (auto &t : RR)printf("%d ", t);
			puts("");
			return;
		}
		a = par[a];
	}
}
bool DFS(int a, int pp, int col) {
	vis[a] = 1;
	par[a] = pp;
	Com[a] = col;
	for (auto &x : F[a]) {
		if (x == pp)continue;
		if (vis[x]) {
			Print(a, x);
			return true;
		}
		if (DFS(x, a, col))return true;
	}
	return false;
}
int D[N_], Q[N_], Path[N_];
void BFS(int a, int b) {
	int head = 0, tail = 0;
	int i;
	for (i = 0; i <= n; i++)D[i] = 0, vis[i] = 0;
	Q[++tail] = a;
	vis[a] = 1;
	while (head < tail) {
		int x = Q[++head];
		for (auto &y : E[x]) {
			if (!vis[y]) {
				Q[++tail] = y;
				Path[y] = x;
				vis[y] = 1;
				D[y] = D[x] + 1;
			}
		}
	}
	int t = b;
	vector<int>Z;
	for (i = 1; i <= n; i++)vis[i] = 0;
	while (t!=a) {
		vis[t] = 1;
		t = Path[t];
		if (t != a && Deg[t] % 3 == 1) {
			BFS(t, b);
			return;
		}
	}
	vis[a] = 1;
	vector<int>RR;
	for (i = 1; i <= n; i++) {
		if (!vis[i])RR.push_back(i);
	}
	if (RR.size() == n || RR.size() == 0) {
		puts("No");
		return;
	}
	puts("Yes");
	printf("%d\n", RR.size());
	for (auto &t : RR)printf("%d ", t);
	puts("");
}
#define pii pair<int,int>
map<pii, int>Map;
int chk[N_];
void Build(int a) {
	int head = 0, tail = 0;
	int i, b = -1;
	for (i = 0; i <= n; i++)D[i] = 0, vis[i] = 0;
	Q[++tail] = a;
	vis[a] = 1;
	while (head < tail) {
		int x = Q[++head];
		for (auto &y : F[x]) {
			if (!vis[y]) {
				if (chk[y] && b == -1)b = y;
				Q[++tail] = y;
				Path[y] = x;
				vis[y] = 1;
				D[y] = D[x] + 1;
			}
		}
	}

	int t = b;
	while (t != a) {
		Map[{min(Path[t], t), max(Path[t], t)}]++;
		t = Path[t];
	}
}
void Solve() {
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)E[i].clear(), F[i].clear();
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= n; i++)Deg[i] = E[i].size();
	if (n == 1) {
		puts("No");
		return;
	}
	for (i = 1; i <= n; i++) {
		if (E[i].size() % 3 == 0) {
			puts("Yes");
			printf("%d\n", n - 1);
			for (int j = 1; j <= n; j++) {
				if (j != i)printf("%d ", j);
			}
			puts("");
			return;
		}
	}
	if (n == 2) {
		puts("No");
		return;
	}
	for (i = 1; i <= n; i++) {
		for (auto &t : E[i]) {
			if (Deg[i] % 3 == 2 && Deg[t] % 3 == 2) {
				F[i].push_back(t);
			}
			if (Deg[i] % 3 == 1 && Deg[t] % 3 == 1) {
				puts("Yes");
				printf("%d\n", n - 2);
				for (int j = 1; j <= n; j++) {
					if (j != i && j != t)printf("%d ", j);
				}
				puts("");
				return;
			}
		}
	}
	ct = 0;
	for (i = 1; i <= n; i++)vis[i] = 0, par[i] = 0;
	for (i = 1; i <= n; i++) {
		if (!vis[i] && Deg[i]%3==2) {
			ct++;
			if (DFS(i, 0, ct)) {
				return;
			}
		}
	}
	vector<int>V;
	for (i = 1; i <= n; i++) {
		if (Deg[i] % 3 == 1) {
			V.push_back(i);
		}
	}
	if (V.empty()) {
		puts("No");
		return;
	}
	if (V.size() >= 2) {
		BFS(V[0], V[1]);
		return;
	}
	else {
		int a = V[0];
		for (i = 1; i <= ct; i++)CC[i] = 0;
		for (auto &t : E[a]) {
			CC[Com[t]]++;
		}
		vector<int>V1, V2;
		for (i = 1; i <= ct; i++) {
			if (CC[i] >= 4) {
				V1.push_back(i);
			}
			if (CC[i] >= 2) {
				V2.push_back(i);
			}
		}
		if (V1.size() == 0 && V2.size() < 2) {
			puts("No");
			return;
		}
		Map.clear();
		if(V2.size()>=2) {
			vector<int>Z[2];
			for (i = 1; i <= n; i++)chk[i] = 0;
			for (auto &t : E[a]) {
				chk[t] = 1;
				if (V2[0] == Com[t])Z[0].push_back(t);
				if (V2[1] == Com[t])Z[1].push_back(t);
			}
			Build(Z[0][0]);
			Build(Z[1][0]);
		}
		else {
			puts("No");
			return;
		}
		for (i = 1; i <= n; i++)vis[i] = 0;
		for (auto &t : Map) {
			if (t.second % 2 == 1) {
				vis[t.first.first] = 1;
				vis[t.first.second] = 1;
			}
		}
		vis[a] = 1;
		vector<int>RR;
		for (i = 1; i <= n; i++)if (!vis[i])RR.push_back(i);
		if (RR.size() == 0 || RR.size() == n) {
			puts("No");
			return;
		}
		puts("Yes");
		printf("%d\n", RR.size());
		for (auto &x : RR)printf("%d ", x);
		puts("");
	}
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}