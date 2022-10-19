#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;

int N, M;
bitset <MAXN> mat[MAXN];
int deg[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) 
		mat[i].reset();
	while (M--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--; y--;
		mat[x].set(y);	
		mat[y].set(x);
		mat[x].flip(x);
		mat[y].flip(y);
	}
}

void output() {
	for (int i = 0; i < N; i++, puts(""))
		for (int j = 0; j < N; j++)
			printf("%d ", mat[i].test(j));
	puts("");
	for (int i = 0; i < N; i++)
		printf("%d ", deg[i]);
	puts("");
	puts("");
}

void solve() {
	bool ok = true;
	for (int i = 0; i < N; i++) {
		deg[i] = mat[i].test(i);
		if (deg[i])
			ok = false;
	}
	
	if (ok) {
		puts("1");
		for (int i = 0; i < N; i++)
			printf("1 ");
		puts("");
		return;
	}
	
	for (int j = 0; j < N; j++) {
		for (int i = j; i < N; i++)
			if (mat[i].test(j)) {
				swap(mat[i], mat[j]);
				swap(deg[i], deg[j]);
				break;
			}
		if (mat[j].test(j))
			for (int i = j + 1; i < N; i++) 
				if (mat[i].test(j)) {
					mat[i] ^= mat[j];
					deg[i] ^= deg[j];
				}
	}
	
	for (int i = N - 1; i >= 0; i--) 
		if (mat[i].test(i))
			for (int j = i + 1; j < N; j++)
				deg[i] ^= mat[i].test(j) & deg[j];
	
	puts("2");
	for (int i = 0; i < N; i++)
		printf("%d ", ++deg[i]);
	puts("");
}	

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		load();
		solve();
	}
	return 0;
}