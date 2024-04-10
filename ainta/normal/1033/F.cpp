#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, C[600000], P[13], L, O[13], CC[5000];
char p[8] = "AOXaox", q[100];
int w[6][2] = { {2,0},{0,-1},{0,1},{-1,1},{1,2},{1,0} }, po[13];
void Go(int pv, int s) {
	if (pv == L) {
		C[s]++;
		return;
	}
	Go(pv + 1, s * 3 + P[pv]);
	Go(pv + 1, s * 3 + 2);
}
long long res;
void DFS(int pv, int s, int s2) {
	if (pv == -1) {
		res += CC[s] * C[s2];
		return;
	}
	if (w[O[pv]][0] != -1)DFS(pv - 1, s, s2 + w[O[pv]][0] * po[pv]);
	if (w[O[pv]][1] != -1)DFS(pv - 1, s+(1<<pv), s2 + w[O[pv]][1] * po[pv]);
}
int main() {
	int i, j, a, k;
	po[0] = 1;
	for (i = 0; i < 12; i++)po[i + 1] = po[i] * 3;
	scanf("%d%d%d", &L, &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		CC[a]++;
		for (j = 0; j < L; j++) P[L - j - 1] = ((a >> j) & 1);
		Go(0, 0);
	}
	for (i = 0; i < m; i++) {
		scanf("%s", q);
		for (j = 0; j < L; j++) {
			for (k = 0; k < 6; k++) {
				if (p[k] == q[j])O[L - j - 1] = k;
			}
		}
		res = 0;
		DFS(L-1, 0, 0);
		printf("%lld\n", res);
	}
}