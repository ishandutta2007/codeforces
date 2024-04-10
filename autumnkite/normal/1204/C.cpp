#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 105
#define INF 0x3f3f3f3f
int n, h, t, Q[N], dis[N][N];
char s[N];
int m, p[1000005];
std :: vector<int> E[N], ans;
void bfs(int s, int *dis){
	for (register int i = 1; i <= n; ++i) dis[i] = INF;
	h = 0, t = 1, Q[t] = s, dis[s] = 0;
	while (h < t){
		int u = Q[++h];
		for (int v : E[u]) if (dis[v] == INF) dis[v] = dis[u] + 1, Q[++t] = v;
	}
}
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i){
		scanf("%s", s + 1);
		for (register int j = 1; j <= n; ++j)
			if (s[j] == '1') E[i].push_back(j);
	}
	for (register int i = 1; i <= n; ++i) bfs(i, dis[i]);
	m = read();
	for (register int i = 1; i <= m; ++i) p[i] = read();
	ans.push_back(p[1]);
	for (register int i = 3, lst = 1; i <= m; ++i)
		if (dis[ans.back()][p[i]] < i - lst) ans.push_back(p[i - 1]), lst = i - 1;
	ans.push_back(p[m]);
	printf("%d\n", ans.size());
	for (int v : ans) printf("%d ", v);
}