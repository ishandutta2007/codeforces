#include<cstdio>
#include<algorithm>
int w[3][6], n, P[4], v[3];
bool DFS(int pv) {
	if (pv == -1)return true;
	int i, j;
	for (i = 0; i < n; i++) {
		if (v[i])continue;
		for (j = 0; j < 6; j++) {
			if (P[pv] == w[i][j])break;
		}
		if (j == 6)continue;
		v[i] = 1;
		if (DFS(pv - 1)) {
			v[i] = 0;
			return true;
		}
		v[i] = 0;
	}
	return false;
}
bool Pos(int a) {
	int c = 0;
	while (a) {
		int t = a % 10;
		P[c++] = t;
		a /= 10;
	}
	return DFS(c - 1);
}
int main() {
	int i, j, k;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < 6; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	for (i = 1;; i++) {
		if (!Pos(i)) {
			printf("%d\n", i - 1);
			break;
		}
	}
}