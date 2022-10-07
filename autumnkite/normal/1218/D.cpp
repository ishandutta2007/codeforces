#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
typedef std :: vector<int> poly;
#define P 1000000007
#define Inv2 500000004
namespace Fast_Walsh_Transform{
	int plus(int a, int b){ return (a += b) >= P ? a - P : a; }
	int minus(int a, int b){ return (a -= b) < 0 ? a + P : a; }
	void FWT_xor(poly &a, int op = 1){
		int n = a.size();
		for (register int m = 1; m < n; m <<= 1)
			for (register int l = m << 1, p = 0; p < n; p += l)
				for (register int i = p; i < p + m; ++i){
					int t0 = plus(a[i], a[i + m]), t1 = minus(a[i], a[i + m]);
					if (~op) a[i] = t0, a[i + m] = t1;
					else a[i] = 1ll * t0 * Inv2 % P, a[i + m] = 1ll * t1 * Inv2 % P;
				}
	}
	poly mul_xor(poly a, poly b){
		int n = a.size();
		FWT_xor(a), FWT_xor(b);
		for (register int i = 0; i < n; ++i) a[i] = 1ll * a[i] * b[i] % P;
		FWT_xor(a, -1);
		return a;
	}
}
using Fast_Walsh_Transform :: mul_xor;
#define N 100055
int n, m, cnt, mw, sw;
std :: vector<int> cyc[50];
poly ans_ex, ans;
int edge, to[N << 1], tw[N << 1], pr[N << 1], hd[N];
void addedge(int u, int v, int w){
	to[++edge] = v, tw[edge] = w, pr[edge] = hd[u], hd[u] = edge;
}
int top, sta[N], stw[N], vis[N];
void dfs(int u, int fa = 0, int fw = 0){
	sta[++top] = u, stw[top] = fw, vis[u] = 2;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa){
			int w = tw[i];
			if (!vis[v]) dfs(v, u, w);
			else if (vis[v] == 2){
				int k = top;
				while (sta[k] != v) --k;
				++cnt;
				for (register int i = k + 1; i <= top; ++i)
					cyc[cnt].push_back(stw[i]);
				cyc[cnt].push_back(w);
			}
		}
	vis[u] = 1, --top;
}
int get(int n){
	int res = 1;
	while (res < n) res <<= 1;
	return res;
}
int main(){
	n = read(), m = read();
	for (register int i = 1, u, v, w; i <= m; ++i){
		u = read(), v = read(), w = read(), sw ^= w, mw = std :: max(mw, w);
		addedge(u, v, w), addedge(v, u, w);
	}
	mw = get(mw + 1);
	dfs(1);
	ans.resize(mw), ans[sw] = 1;
	ans_ex.resize(mw), ans_ex[sw] = 1;
	for (register int i = 1; i <= cnt; ++i){
		poly tmp(mw);
		for (int v : cyc[i]) ++tmp[v];
		ans = mul_xor(ans, tmp);
		ans_ex = mul_xor(ans_ex, tmp);
		for (register int j = 0; j < mw; ++j)
			if (ans_ex[j]) ans_ex[j] = 1;
	}
	for (register int i = 0; i < mw; ++i)
		if (ans_ex[i]) return printf("%d %d\n", i, ans[i]), 0;
}