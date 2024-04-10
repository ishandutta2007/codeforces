#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1000005
#define P 1000000007
int n, m, cnt, h, t, dis[N];
std :: vector<int> E[N][10], Q[N];
void addedge(int u, int v, int w){
	int ls = v;
	for (; w >= 10; w /= 10)
		E[++cnt][w % 10].push_back(ls), ls = cnt;
	E[u][w].push_back(ls);
}
void bfs(int s){
	for (register int i = 1; i <= cnt; ++i) dis[i] = P;
	h = 0, t = 1, Q[t].push_back(s), dis[s] = 0;
	while (h < t){
		std :: vector<int> &u = Q[++h];
		for (register int i = 0; i < 10; ++i){
			++t;
			for (int p : u)
				for (int v : E[p][i])
					if (dis[v] == P) dis[v] = (10ll * dis[p] + i) % P, Q[t].push_back(v);
			if (!Q[t].size()) --t;
		}
	}
}
int main(){
	n = read(), m = read(), cnt = n;
	for (register int i = 1, u, v; i <= m; ++i)
		u = read(), v = read(), addedge(u, v, i), addedge(v, u, i);
	bfs(1);
	for (register int i = 2; i <= n; ++i) printf("%d\n", dis[i]);
}