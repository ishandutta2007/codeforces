#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, c[400005];
vector<int> G[400005];
int dfn[400005], dfo[400005], cnt;

struct segt
{
	LL dat[1048576], tag[1048576];
	void init()
	{
		memset(tag, -1, sizeof(tag));
		rep1(i, n) dat[dfn[i] + 524288] = 1LL << c[i];
		for(int i = 524287; i >= 1; i --) dat[i] = dat[i << 1] | dat[i << 1 | 1];
	}
	void pushdown(int cur)
	{
		if(tag[cur] != -1) {
			dat[cur << 1] = tag[cur << 1] = dat[cur << 1 | 1] = tag[cur << 1 | 1] = tag[cur];
			tag[cur] = -1;
		}
	}
	void modify(int l, int r, LL cd, int cv = 1, int cl = 0, int cr = 524287)
	{
		if(l == cl && r == cr) {
			dat[cv] = tag[cv] = cd;
			return;
		}
		pushdown(cv);
		int mid = cl + cr >> 1;
		if(r <= mid) modify(l, r, cd, cv << 1, cl, mid);
		else if(l > mid) modify(l, r, cd, cv << 1 | 1, mid + 1, cr);
		else {
			modify(l, mid, cd, cv << 1, cl, mid);
			modify(mid + 1, r, cd, cv << 1 | 1, mid + 1, cr);
		}
		dat[cv] = dat[cv << 1] | dat[cv << 1 | 1];
	}
	LL query(int l, int r, int cv = 1, int cl = 0, int cr = 524287)
	{
		if(l == cl && r == cr) return dat[cv];
		pushdown(cv);
		int mid = cl + cr >> 1;
		if(r <= mid) return query(l, r, cv << 1, cl, mid);
		else if(l > mid) return query(l, r, cv << 1 | 1, mid + 1, cr);
		else return query(l, mid, cv << 1, cl, mid) | query(mid + 1, r, cv << 1 | 1, mid + 1, cr);
	}
}tre;

void dfs(int v, int par)
{
	dfn[v] = cnt ++;
	rep(i, G[v].size()) {
		int u = G[v][i];
		if(u == par) continue;
		dfs(u, v);
	}
	dfo[v] = cnt - 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep1(i, n) scanf("%d", &c[i]);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, -1);
	tre.init();
	rep(i, m) {
		int tp, v, x;
		scanf("%d", &tp);
		if(tp == 1) {
			scanf("%d%d", &v, &x);
			tre.modify(dfn[v], dfo[v], 1LL << x);
		} else {
			scanf("%d", &v);
			printf("%d\n", __builtin_popcountll(tre.query(dfn[v], dfo[v])));
		}
	}
	return 0;
}