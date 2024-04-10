#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
char s[2000005];
int n, x, y, dis[15][15];
int h, t, Q[25];
void bfs(int s){
	memset(dis[s], 0x3f, sizeof dis[s]);
	h = 0, t = 1, Q[t] = s, dis[s][s] = 0;
	while (h < t){
		int u = Q[++h], v;
		v = (u + x) % 10;
		if (dis[s][v] == INF) Q[++t] = v, dis[s][v] = dis[s][u] + 1;
		v = (u + y) % 10;
		if (dis[s][v] == INF) Q[++t] = v, dis[s][v] = dis[s][u] + 1;
	}
}
int calc(int s, int t){
	return std :: min(dis[(s + x) % 10][t], dis[(s + y) % 10][t]);
}
int solve(int _x, int _y){
	x = _x, y = _y;
	for (register int i = 0; i < 10; ++i) bfs(i);
	int res;
	if (s[1] == 0) res = 0;
	else if (dis[0][s[1]] == INF) return -1;
	else res = dis[0][s[1]];
	for (register int i = 2, tmp; i <= n; ++i)
		if ((tmp = calc(s[i - 1], s[i])) == INF) return -1;
		else res += tmp;
	return res;
}
int main(){
	scanf("%s", s + 1), n = strlen(s + 1);
	for (register int i = 1; i <= n; ++i) s[i] -= '0';
	for (register int i = 0; i < 10; ++i)
		for (register int j = 0; j < 10 || (putchar('\n'), 0); ++j)
			printf("%d ", solve(i, j));
}