#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
int w[N_], n, m, A, B, chk[N_], vis[N_], T1[N_], T2[N_];
vector<int>E[N_];
void DFS(int a) {
	vis[a] = 1;
	for (auto &x : E[a]) {
		if (!vis[x] && !chk[x])DFS(x);
	}
}
void Solve() {
	int i, a, b;
	scanf("%d%d%d%d", &n,&m,&A,&B);
	for (i = 1; i <= n; i++) {
		E[i].clear();
		T1[i] = T2[i] = vis[i] = 0;
		chk[i] = 0;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	chk[B] = 1;
	DFS(A);
	long long c1 = 0, c2 = 0;
	for (i = 1; i <= n; i++) {
		if (!vis[i] && i != B)T1[i] = 1,c1++;
		vis[i] = 0;
	}
	chk[B] = 0;
	chk[A] = 1;
	DFS(B);
	for (i = 1; i <= n; i++) {
		if (!vis[i] && i != A)T2[i] = 1,c2++;
	}
	printf("%lld\n", c1*c2);
}
int main() {
	//freopen("input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}