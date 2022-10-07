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
#define N 100005
int n, m, col[N], vis[N];
std :: vector<int> E[N];
namespace Double_Hash{
	static const int B1 = 100003, P1 = 382538579, B2 = 138239, P2 = 952959323;
	struct node{
		int H1, H2;
		node(int _H1 = 0, int _H2 = 0){ H1 = _H1, H2 = _H2; }
		bool operator != (const node &rhs) const {
			return H1 != rhs.H1 || H2 != rhs.H2;
		}
		node add(int ch){
			return node((1ll * H1 * B1 + ch) % P1, (1ll * H2 * B2 + ch) % P2);
		}
	};
}
using namespace Double_Hash;
node h[N];
bool work(int u, int c){
	memset(vis, 0, sizeof vis);
	for (int v : E[u]) vis[v] = 1;
	for (register int i = 1; i <= n; ++i)
		if (!vis[i]) if (h[i] != h[u] || col[i]) return 0; else col[i] = c;
	return 1;
}
int main(){
	n = read(), m = read();
	for (register int i = 1, u, v; i <= m; ++i)
		u = read(), v = read(), E[u].push_back(v), E[v].push_back(u);
	for (register int i = 1; i <= n; ++i) std :: sort(E[i].begin(), E[i].end());
	for (register int i = 1; i <= n; ++i)
		for (int v : E[i]) h[i] = h[i].add(v);
	int c = 0;
	for (register int i = 1; i <= n; ++i)
		if (!col[i]){
			++c;
			if (c > 3 || !work(i, c)) return puts("-1"), 0;
		}
	if (c < 3) return puts("-1"), 0;
	for (register int i = 1; i <= n; ++i) printf("%d ", col[i]);
}