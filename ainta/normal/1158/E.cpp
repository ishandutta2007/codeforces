#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, L[1010], BE[1010], T1[1010], T2[1010], chk[1010], Dep[1010], T3[1010], par[1010], DEBUG = 0;

vector<int>TR[1010];

int Dist[1010][1010];

vector<int>G[1010];
char p[1010];
void Query(int *T) {
	int i, j;
	if (!DEBUG) {
		printf("?");
		for (i = 1; i <= n; i++)printf(" %d", min(L[i], n - 1));
		puts("");
	}
	fflush(stdout);
	if (!DEBUG) {
		scanf("%s", p);
		for (i = 1; i <= n; i++) {
			T[i] = p[i - 1] - '0';
		}
	}
	else {
		for (i = 1; i <= n; i++) {
			T[i] = 0;
			for (j = 1; j <= n; j++) {
				if (L[j] && Dist[i][j] <= L[j])T[i] = 1;
			}
		}
	}
}
void Add(int a, int dep) {
	Dep[a] = dep;
	G[dep].push_back(a);
	chk[a] = 1;
}
void DFS(int a, int pp, int d, int rt) {
	Dist[rt][a] = d;
	for (auto &x : TR[a]) {
		if (x == pp)continue;
		DFS(x, a, d + 1, rt);
	}
}
int main() {
	//freopen("output.txt", "w", stdout);
	int i, j, k, l;
	scanf("%d", &n);
	if (DEBUG) {
		srand(193);
		for (i = 2; i <= n; i++) {
			int a = rand() % (i - 1) + 1;
			TR[a].push_back(i);
			TR[i].push_back(a);
			printf("%d %d\n", a, i);
		}
		for (i = 1; i <= n; i++) {
			DFS(i, 0, 0, i);
		}
	}
	for (i = 1; i <= n; i++) {
		BE[i] = 0;
	}
	Add(1, 0);
	for (i = 512; i >= 2; i >>= 1) {

		for (j = 1; j <= n; j++)L[j] = 0;
		for (j = 0; j <= 1000; j += i * 4) {
			for (auto &t : G[j]) {
				L[t] = i;
			}
		}
		Query(T1);

		for (j = 1; j <= n; j++)L[j] = 0;
		for (j = 0; j <= 1000; j += i * 4) {
			for (auto &t : G[j]) {
				L[t] = i-1;
			}
		}
		Query(T2);

		for (j = 1; j <= n; j++) {
			if (!chk[j] && BE[j] % (4 * i) == 0) {
				if (T1[j] != T2[j]) {
					Add(j, BE[j] + i);
				}
			}
		}

		for (j = 1; j <= n; j++) {
			if (!chk[j] && BE[j] % (4 * i) == 0) {
				if (!T1[j]) {
					BE[j] += i;
				}
			}
		}

		for (j = 1; j <= n; j++)L[j] = 0;
		for (j = 2*i; j <= 1000; j += i * 4) {
			for (auto &t : G[j]) {
				L[t] = i;
			}
		}
		Query(T1);

		for (j = 1; j <= n; j++)L[j] = 0;
		for (j = 2*i; j <= 1000; j += i * 4) {
			for (auto &t : G[j]) {
				L[t] = i - 1;
			}
		}
		Query(T2);

		for (j = 1; j <= n; j++) {
			if (!chk[j] && BE[j] % (4 * i) == 2*i) {
				if (T1[j] != T2[j]) {
					Add(j, BE[j] + i);
				}
			}
		}

		for (j = 1; j <= n; j++) {
			if (!chk[j] && BE[j] % (4 * i) == 2*i) {
				if (!T1[j]) {
					BE[j] += i;
				}
			}
		}
	}

	for (i = 1; i <= n; i++) {
		if (!chk[i]) {
			Add(i, BE[i] + 1);
		}
	}


	for (i = 0; i < 3; i++) {
		for (j = 0; j < 10; j++) {
			for (k = 1; k <= n; k++)L[k] = 0;
			for (k = i; k <= n; k += 3) {
				for (l = 0; l < G[k].size(); l++) {
					if ((l >> j) & 1)L[G[k][l]] = 1;
				}
			}
			Query(T1);

			for (k = i + 1; k <= n; k += 3) {
				for (auto &x : G[k]) {
					if (T1[x]) {
						par[x] += (1 << j);
					}
				}
			}

		}
	}
	printf("!\n");
	for (i = 2; i <= n; i++) {
		printf("%d %d\n", G[Dep[i] - 1][par[i]], i);
	}
	fflush(stdout);
	return 0;
}