#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define N_ 201000
using namespace std;
int TC, n, m, chk[N_], vis[N_], SCC[N_], ord[N_], cnt, cc, Mn[N_], CK[N_], vis2[N_];
vector<int>E[N_], F[N_];
vector<int>U, G1[N_], G2[N_];
char p[N_];
void DFS(int a) {
	vis[a] = 1;
	for (auto &x : E[a]) {
		if (!vis[x])DFS(x);
	}
	ord[++cnt] = a;
}
void DFS2(int a) {
	SCC[a] = cnt;
	Mn[cnt] = min(Mn[cnt], a / 2);
	for (auto &x : F[a]) {
		if (!SCC[x])DFS2(x);
	}
}
void Add_Edge(int a, int b) {
	E[a].push_back(b);
	F[b].push_back(a);
}
void Go1(int a) {
	vis[a] = 1;
	for (auto &x : G1[a]) {
		if (!vis[x])Go1(x);
	}
}
void Go2(int a) {
	vis2[a] = 1;
	for (auto &x : G2[a]) {
		if (!vis2[x])Go2(x);
	}
}
void Solve() {
	int i, a, b, j;
	scanf("%d%d", &n, &m);
	scanf("%s", p);
	for (i = 0; i < n; i++) {
		if (p[i] == 'A')chk[i] = 1;
		else chk[i] = 0;
	}
	for (i = 0; i < 2 * n; i++) {
		Mn[i + 1] = 1e9;
		CK[i + 1] = 0;
		E[i].clear();
		F[i].clear();
		G1[i+1].clear();
		G2[i+1].clear();
		vis[i] = 0;
		SCC[i] = 0;
	}
	int ck = 0;
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		if (a < 0)a = (-a) * 2 - 1;
		else a = a * 2 - 2;
		if (b < 0)b = (-b) * 2 - 1;
		else b = b * 2 - 2;
		if (a > b)swap(a, b);
		Add_Edge(a ^ 1, b);
		Add_Edge(b ^ 1, a);
		if (chk[a/2] && chk[b/2] && (a^1)!=b)ck = 1;
		if (a/2 != b/2 && chk[b/2]) {
			Add_Edge(a ^ 1, a);
		}
	}
	if (ck) {
		puts("FALSE");
		return;
	}
	cnt = 0;
	for (i = 0; i < 2 * n; i++) {
		if (!vis[i])DFS(i);
	}
	cnt = 0;
	for (i = 2 * n; i >= 1; i--) {
		if (!SCC[ord[i]]) {
			cnt++;
			DFS2(ord[i]);
		}
	}
	for (i = 0; i < n; i++) {
		if (SCC[i * 2] == SCC[i * 2 + 1]) {
			puts("FALSE");
			return;
		}
		if (chk[i] && (Mn[SCC[i * 2]] != i || Mn[SCC[i * 2 + 1]] != i)) {
			puts("FALSE");
			return;
		}
		if (chk[i])CK[SCC[i * 2]] = CK[SCC[i * 2 + 1]] = 1;
	}
	for (i = 0; i < 2 * n; i++) {
		for (auto &t : E[i]) {
			if (SCC[i] != SCC[t]) {
				G1[SCC[i]].push_back(SCC[t]);
				G2[SCC[t]].push_back(SCC[i]);
				if (CK[SCC[i]] && CK[SCC[t]]) {
					puts("FALSE");
					return;
				}
			}
		}
	}
	for (i = 1; i <= cnt; i++)vis[i] = vis2[i] = 0;
	for (i = 1; i <= cnt; i++) {
		if (CK[i] && !vis[i]) {
			Go1(i);
		}
		if (CK[i] && !vis2[i]) {
			Go2(i);
		}
	}
	for (i = 1; i <= cnt; i++) {
		if (!CK[i] && vis[i] && vis2[i]) {
			puts("FALSE");
			return;
		}
	}
	puts("TRUE");
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}