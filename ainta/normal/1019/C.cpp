#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 1001000
using namespace std;
vector<int>E[N_], F[N_];
int n, m, chk[N_], U[N_], res;
void DFS(int a) {
	if (a == n + 1)return;
	if (chk[a]) {
		DFS(a + 1);
		return;
	}
	chk[a] = a;
	for (auto &x : E[a]) {
		chk[x] = a;
	}
	DFS(a + 1);
	int ck = 0;
	for (auto &x : F[a]) {
		if (U[x])ck = 1;
	}
	if (!ck) {
		U[a] = 1;
		res++;
	}
}
int main() {
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		F[b].push_back(a);
	}
	DFS(1);
	printf("%d\n", res);
	for (i = 1; i <= n; i++)if (U[i])printf("%d ", i);
}