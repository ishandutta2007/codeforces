#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define pii pair<int, int>
 
inline int read() {
    int w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}
 
const int maxn = 100000 + 5;
 
int N, M;
 
struct Edge {
	int u, v, w, pre;
} e[maxn << 1];
int m, G[maxn];
void clear() {
	m = 0;
	memset(G, -1, sizeof(G));
}
void add(int u, int v, int w) {
	e[m++] = (Edge){u, v, w, G[u]};
	G[u] = m-1;
}
 
int tag[maxn], id[maxn];
int border;
 
void dfs(int u, int tg) {
	tag[u] = tg;
	for (register int i = G[u]; ~i; i = e[i].pre) {
		int v = e[i].v;
		if (e[i].w <= border) continue;
		if (!tag[v]) dfs(v, tg);
	}
}
 
int cnt, ans[maxn], res;
int st[maxn], rk[maxn], d[maxn], l, r;
bool topsort() {
	memset(d, 0, sizeof(d));
	rep(i, 0, M-1) if (e[i].w > border) d[e[i].v]++;
	l = r = 0;
	rep(i, 1, N) if (!d[i]) st[r++] = i;
	while (l < r) {
		int u = st[l++];
		for (register int i = G[u]; ~i; i = e[i].pre) {
			int v = e[i].v;
			if (e[i].w <= border) continue;
			if (!--d[v]) st[r++] = v;
		}
	}
	return r == N;
}
 
int main() {
	N = read(), M = read();
	clear();
	rep(i, 1, M) {
		int u = read(), v = read(), w = read();
		add(u, v, w);
	}
	int L = 0, R = 1000000000;
	while (L <= R) {
		border = L+R>>1;
		if (topsort()) res = border, R = border-1; else L = border+1;
	}
 
	border = res;
	rep(i, 1, N) if (!tag[i]) dfs(i, i);
	topsort();
	rep(i, 0, N-1) rk[st[i]] = i;
	rep(i, 0, M-1) {
		if (e[i].w <= border && (tag[e[i].u] < tag[e[i].v] || tag[e[i].u] == tag[e[i].v] && rk[e[i].u] > rk[e[i].v])) ans[++cnt] = i;
	}
	printf("%d %d\n", border, cnt);
	rep(i, 1, cnt) printf("%d ", ans[i]+1);
 
	return 0;
}