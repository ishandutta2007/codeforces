#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 201000
using namespace std;
vector<int>E[N_];
int n, C[N_], par[N_], Dep[N_];
int CK[2];
long long S[N_], res;
void DFS(int a, int pp) {
	par[a] = pp;
	C[a] = 1;
	CK[Dep[a] % 2]++;
	for (auto &x : E[a]) {
		if (x == pp)continue;
		Dep[x] = Dep[a] + 1;
		DFS(x, a);
		C[a] += C[x];
	}
}
void Go(int a, int pp) {
	for (auto &x : E[a]) {
		if (x == pp)continue;
		S[x] = S[a] + n - C[x] * 2;
		Go(x, a);
	}
}
int main() {
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	for (i = 1; i <= n; i++)S[1] += Dep[i];
	Go(1, 0);
	for (i = 1; i <= n; i++) {
		res += S[i];
	}
	res += 1ll * CK[0] * CK[1] * 2;
	printf("%lld\n", res / 4);
}