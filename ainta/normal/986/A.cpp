#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int D[110][101000], Q[101000];
vector<int>G[110], E[101000];
int n, m, w[101000], K, S, v[101000];
void BFS(int a) {
	int i;
	for (i = 1; i <= n; i++) {
		v[i] = 0;
		D[a][i] = 1e9;
	}
	int head = 0, tail = 0;
	for (auto &x : G[a]) {
		Q[++tail] = x;
		v[x] = 1;
		D[a][x] = 0;
	}
	while (head < tail) {
		int x = Q[++head];
		for (auto &y : E[x]) {
			if (!v[y]) {
				v[y] = 1;
				Q[++tail] = y;
				D[a][y] = D[a][x] + 1;
			}
		}
	}
}
int main() {
	int i, j;
	scanf("%d%d%d%d", &n, &m,&K,&S);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		G[w[i]].push_back(i);
	}
	for (i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (i = 1; i <= K; i++) {
		BFS(i);
	}
	for (i = 1; i <= n; i++) {
		vector<int>T;
		for (j = 1; j <= K; j++) {
			T.push_back(D[j][i]);
		}
		sort(T.begin(), T.end());
		long long res = 0;
		for (j = 0; j < S; j++) {
			res += T[j];
		}
		printf("%lld ", res);
	}
}