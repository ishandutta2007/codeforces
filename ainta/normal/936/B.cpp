#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
using namespace std;
vector<int>E[N_];
int n, m, v[N_][2], Q[N_*2], Path[N_][2];
int head, tail;
void Put(int a, int ck, int pp) {
	if (v[a][ck])return;
	v[a][ck] = 1;
	Path[a][ck] = pp;
	Q[++tail] = a * 2 + ck;
}
int vv[N_], chk = 0;
void DFS(int a) {
	int i;
	vv[a] = 1;
	for (i = 0; i < E[a].size(); i++) {
		if (!vv[E[a][i]]) {
			DFS(E[a][i]);
		}
		if (vv[E[a][i]] == 1)chk = 1;
	}
	vv[a] = 2;
}
int main() {
	int i, a, b, ck, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		int c;
		scanf("%d", &c);
		E[i].resize(c);
		for (j = 0; j < c; j++)scanf("%d", &E[i][j]);
	}
	int st;
	scanf("%d", &st);
	Put(st, 0, 0);
	while (head < tail) {
		int x = Q[++head];
		ck = x % 2;
		x /= 2;
		for (i = 0; i < E[x].size(); i++) {
			Put(E[x][i], !ck, x);
		}
	}
	for (i = 1; i <= n; i++) {
		if (E[i].empty() && v[i][1]) {
			a = i, ck = 1;
			vector<int>T;
			while (a) {
				T.push_back(a);
				a = Path[a][ck];
				ck = !ck;
			}
			printf("Win\n");
			for (j = T.size() - 1; j >= 0; j--) {
				printf("%d ", T[j]);
			}
			return 0;
		}
	}
	DFS(st);
	if (chk)printf("Draw\n");
	else printf("Lose\n");
}