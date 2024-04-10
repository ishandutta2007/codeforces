#include <cstdio>
#include <cstdlib>
int n, m, a[1000005];
char t[1000005];
int get(int *a, int i, int j){
	if (i < 1 || j < 1 || i > n || j > m) return 0;
	return a[(i - 1) * m + j];
}
void set(int *a, int i, int j, int v){
	a[(i - 1) * m + j] = v;
}
void GG(int x){
	printf("%d\n", x), exit(0);
}
void dfs2(int i, int j){
	if (i > n || j > m) return;
	if ((i != 1 || (j != 1)) && get(a, i, j)) return;
	if (i == n && j == m) GG(2);
	set(a, i, j, 1);
	dfs2(i + 1, j), dfs2(i, j + 1);
}
void dfs1(int i, int j){
	if (i > n || j > m) return;
	if ((i != 1 || (j != 1)) && get(a, i, j)) return;
	if (i == n && j == m) dfs2(1, 1), GG(1);
	set(a, i, j, 1);
	dfs1(i + 1, j), dfs1(i, j + 1);
}
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; ++i){
		scanf("%s", t + 1);
		for (register int j = 1; j <= m; ++j)
			if (t[j] == '#') set(a, i, j, 1);
	}
	dfs1(1, 1), GG(0);
}