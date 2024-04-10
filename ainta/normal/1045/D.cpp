#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
vector<int>E[N_], T[N_];
int n, grp[N_], par[N_];
double P[N_], S[N_];
void DFS(int a, int pp) {
	for (auto &x : E[a]) {
		if (x == pp)continue;
		par[x] = a;
		T[a].push_back(x);
		DFS(x, a);
	}
}
int main() {
	int i, a, b, j, Q;
	double res = 0.0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%lf", &P[i]);
	for (i = 1; i < n; i++) {
		scanf("%d%d", &a, &b);
		a++, b++;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	P[0] = 1;
	for (i = 1; i <= n; i++)S[par[i]] += 1.0-P[i];
	for (i = 0; i <= n; i++) {
		res += S[i]*P[i];
	}
	double x;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%lf", &a, &x);
		a++;
		res -= S[a]*P[a];
		res -= S[par[a]]*P[par[a]];
		S[par[a]] -= 1.0-P[a];
		P[a] = x;
		S[par[a]] += 1.0-P[a];
		res += S[a] * P[a];
		res += S[par[a]] * P[par[a]];
		printf("%f\n", res);
	}
}