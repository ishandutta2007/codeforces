#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, E[200][200], Q[200], head, tail, D[200];
long long w[101000];
vector<int>G[61], T;
void Dijk(int a) {
	int i;
	for (i = 0; i < n; i++)D[i] = 1e9;
	D[a] = 0;
	head = tail = 0;
	Q[++tail] = a;
	while (head < tail) {
		int x = Q[++head];
		for (i = 0; i < n; i++) {
			if (D[i] > D[x] + 1 && E[x][i]) {
				D[i] = D[x] + 1;
				Q[++tail] = i;
			}
		}
	}
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		for (j = 0; j < 60; j++) {
			if ((w[i] >> j) & 1) {
				G[j].push_back(i);
				if (G[j].size() >= 3) {
					puts("3");
					return 0;
				}
			}
		}
	}
	for (i = 0; i < 60; i++) {
		if (G[i].size() == 2) {
			T.push_back(G[i][0]);
			T.push_back(G[i][1]);
		}
	}
	sort(T.begin(), T.end());
	T.resize(unique(T.begin(), T.end()) - T.begin());
	n = T.size();
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i != j && (w[T[j]] & w[T[i]]))E[i][j] = 1;
		}
	}
	int res = 1e9;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (E[i][j]) {
				E[i][j] = E[j][i] = 0;
				Dijk(i);
				res = min(res, D[j] + 1);
				E[i][j] = E[j][i] = 1;
			}
		}
	}
	if (res > 5e5)puts("-1");
	else printf("%d\n", res);
}