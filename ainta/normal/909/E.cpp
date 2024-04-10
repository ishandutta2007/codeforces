#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, D[101000], Q[101000], head, tail, Deg[101000], w[101000], res;
vector<int>E[101000];
int main() {
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		D[i] = w[i];
	}
	for (i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		a++, b++;
		E[b].push_back(a);
		Deg[a]++;
	}
	for (i = 1; i <= n; i++)if (!Deg[i])Q[++tail] = i;
	while (head < tail) {
		int x = Q[++head];
		for (i = 0; i < E[x].size(); i++) {
			int y = E[x][i];
			Deg[y]--;
			D[y] = max(D[y], D[x]);
			if (w[x] == 0 && w[y] == 1)D[y] = max(D[y], D[x] + 1);
			if (!Deg[y]) {
				Q[++tail] = y;
			}
		}
	}
	for (i = 1; i <= n; i++)res = max(res, D[i]);
	printf("%d\n", res);
}