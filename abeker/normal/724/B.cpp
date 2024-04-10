#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 25;

int N, M;
int mat[MAXN][MAXN];
int perm[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", mat[i] + j);
}

bool id() {
	for (int i = 0; i < M; i++)
		if (perm[i] != i + 1) 
			return false;
	return true;
}

bool check(int c1, int c2, int r) {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++)
				perm[k] = mat[r][k];
			swap(perm[i], perm[j]);
			swap(perm[c1], perm[c2]);
			if (id()) return true;
			for (int k = 0; k < M; k++)
				perm[k] = mat[r][k];
			swap(perm[c1], perm[c2]);
			swap(perm[i], perm[j]);
			if (id()) return true;
		}
	return false;
}

bool solve() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++) {
			bool ok = true;
			for (int k = 0; k < N; k++)
				ok &= check(i, j, k);
			if (ok) return true;
		}
	return false;
}

int main() {
	load();
	puts(solve() ? "YES" : "NO");
	return 0;
}