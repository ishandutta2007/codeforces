#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

const int N = 1000015;

int n, head[N], siz[N], Max[N], tot, buc[N], dep[N];
struct edge { int to, nxt; } e[N << 1];
bitset<N> f;

void add(int u, int v) {
	e[++tot] = (edge) {v, head[u]};
	head[u] = tot;
}

void dfs(int u, int pa) {
	siz[u] = 1; dep[u] = dep[pa] + 1; Max[u] = 0;

	for (int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;

		if (v == pa) continue;

		dfs(v, u);
		siz[u] += siz[v];
		Max[u] = max(Max[u], siz[v]);
	}

	Max[u] = max(Max[u], n - siz[u]);
}

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d", &n);

	rep(i, 2, n) {
		int x;
		scanf("%d", &x);
		add(x, i); add(i, x);
	}

	f[0] = 1;
	dfs(1, 0);
	int rt = min_element(Max + 1, Max + n + 1) - Max;

	dfs(rt, 0);
	ll ans = accumulate(dep + 1, dep + n + 1, 0ll);

	for (int i = head[rt]; i; i = e[i].nxt) buc[siz[e[i].to]]++;

	f[0] = 1;

	rep(i, 1, n) {
		for (int j = 1; j <= buc[i]; buc[i] -= j, j <<= 1) {
			f |= f << (j * i);
		}

		if (buc[i]) f |= f << (buc[i] * i);
	}

	per(i, 0, n / 2) {
		if (f[i]) {
			ans += (ll)(n - 1 - i) * i;
			break;
		}
	}

	printf("%lld\n", ans);
	return 0;
}