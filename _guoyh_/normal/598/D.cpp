# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 1051;
const int mo[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, k, csz;
char s[MAXN][MAXN];
int ans[MAXN * MAXN];
int c[MAXN][MAXN];
void dfs(int x, int y){
	for (int i = 0; i < 4; i++){
		int nx = x + mo[i][0], ny = y + mo[i][1];
		if (c[nx][ny]) continue;
		if (s[nx][ny] == '*'){
			ans[csz]++;
		} else {
			c[nx][ny] = csz;
			dfs(nx, ny);
		}
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i][j] == '*') continue;
			if (c[i][j]) continue;
			c[i][j] = ++csz;
			dfs(i, j);
		}
	}
	while (k--){
		int ax, ay;
		scanf("%d%d", &ax, &ay);
		printf("%d\n", ans[c[ax][ay]]);
	}
	return 0;
}