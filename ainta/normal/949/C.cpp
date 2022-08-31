#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
int n, m, h[N_], K;
vector<int>E[N_], F[N_];
int ord[N_], cnt, SCC[N_], v[N_], chk[N_], SZ[N_];
void DFS1(int a) {
	v[a] = 1;
	for (auto &t : E[a]) {
		if (!v[t])DFS1(t);
	}
	ord[++cnt] = a;
}
void DFS2(int a) {
	SCC[a] = cnt;
	SZ[cnt]++;
	for (auto &t : F[a]) {
		if (!SCC[t])DFS2(t);
	}
}
int main() {
	int i, a, b;
	scanf("%d%d%d", &n, &m, &K);
	for (i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		if ((h[a] + 1) % K == h[b]) {
			E[a].push_back(b);
			F[b].push_back(a);
		}
		if ((h[b] + 1) % K == h[a]) {
			E[b].push_back(a);
			F[a].push_back(b);
		}
	}
	for (i = 1; i <= n; i++) {
		if (!v[i])DFS1(i);
	}
	cnt = 0;
	for (i = n; i >= 1; i--) {
		if (!SCC[ord[i]]) {
			cnt++;
			DFS2(ord[i]);
		}
	}
	for (i = 1; i <= n; i++) {
		for (auto &t : E[i]) {
			if (SCC[i] != SCC[t])chk[SCC[i]] = 1;
		}
	}
	int res = 1e9, pv = 0;
	for (i = 1; i <= cnt; i++) {
		if (!chk[i] && res > SZ[i])res = SZ[i], pv = i;
	}
	printf("%d\n", res);
	for (i = 1; i <= n; i++)if (SCC[i] == pv)printf("%d ", i);
}