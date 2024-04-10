#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, Col[10100];
vector<int>E[10100], L[10100];
int Num(int x, int y) {
	return (x - 1)*n + y;
}
void Add_Edge(int a, int b, int c) {
	E[a].push_back(b);
	E[b].push_back(a);
	L[a].push_back(c);
	L[b].push_back(c);
}
void Ask(int bx, int by, int ex, int ey) {
	printf("? %d %d %d %d\n", bx, by, ex, ey);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	Add_Edge(Num(bx, by), Num(ex, ey), 1 - r);
}
void DFS(int a, int col) {
	Col[a] = col;
	for (int i = 0; i < E[a].size(); i++) {
		int x = E[a][i];
		if (Col[x] == -1)DFS(x, col^L[a][i]);
	}
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i - 2 >= 1) {
				Ask(i - 2, j, i, j);
			}
			else if (j - 2 >= 1) {
				Ask(i, j - 2, i, j);
			}
			else if (i > 1 && j - 1) {
				Ask(i - 1, j - 1, i, j);
			}
		}
	}
	Ask(2, 1, 3, 2);
	for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)Col[Num(i, j)] = -1;
	DFS(Num(1, 1), 1);
	DFS(Num(1, 2), 1);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i + 2 <= n && j + 1 <= n) {
				int t1 = Col[Num(i, j)] ^ Col[Num(i + 1, j + 1)];
				int t2 = Col[Num(i, j)] ^ Col[Num(i + 2, j)];
				int t3 = Col[Num(i + 2, j + 1)] ^ Col[Num(i, j + 1)];
				int t4 = Col[Num(i + 2, j + 1)] ^ Col[Num(i + 1, j)];
				if (t1 == t2 && t3 == t4 && t1 != t3)continue;
				printf("? %d %d %d %d\n", i, j, i + 2, j + 1);
				fflush(stdout);
				int r;
				scanf("%d", &r);
				if ((r == 1) != (Col[Num(i, j)] == Col[Num(i + 2, j + 1)])) {
					for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)Col[Num(i, j)] = -1;
					DFS(Num(1, 1), 1);
					DFS(Num(1, 2), 0);
				}

				puts("!");
				for (i = 1; i <= n; i++) {
					for (j = 1; j <= n; j++) {
						printf("%d", Col[Num(i, j)]);
					}
					puts("");
				}
				return 0;
			}
		}
	}
}