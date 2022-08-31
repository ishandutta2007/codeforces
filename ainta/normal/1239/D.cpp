#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define N_ 1000100

int n, m, SCC[N_], ord[N_], vis[N_], cnt;
vector<int>E[N_], F[N_];
void DFS1(int a) {
	vis[a] = 1;
	for (auto &x : E[a]) {
		if (!vis[x])DFS1(x);
	}
	ord[++cnt] = a;
}
void DFS2(int a) {
	SCC[a] = cnt;
	for (auto &x : F[a]) {
		if (!SCC[x])DFS2(x);
	}
}
void Solve() {
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		E[i].clear(), F[i].clear();
		SCC[i] = ord[i] = vis[i] = 0;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		if (a == b)continue;
		E[a].push_back(b);
		F[b].push_back(a);
	}
	cnt = 0;
	for (i = 1; i <= n; i++) {
		if(!vis[i])DFS1(i);
	}
	cnt = 0;
	for (i = n; i >= 1; i--) {
		if (!SCC[ord[i]]) {
			cnt++;
			DFS2(ord[i]);
		}
	}
	if (cnt == 1) {
		puts("No");
		return;
	}
	vector<int>A, B;
	for (i = 1; i <= n; i++) {
		if (SCC[i] == cnt)A.push_back(i);
		else B.push_back(i);
	}
	puts("Yes");
	printf("%d %d\n", A.size(), B.size());
	for (auto &x : A)printf("%d ", x);
	puts("");
	for (auto &x : B)printf("%d ", x);
	puts("");
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}