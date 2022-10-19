#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second

typedef long long ll;
typedef pair <ll, ll> pii;

const int MAXN = 3e5 + 5;
const int offset = 1 << 19;
const int LOG = 19;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct node {
	int st, en;
	ll dp[2][2];
	node() {
		st = en = -1;
		memset(dp, INF, sizeof dp);
	}
	void output() const {
		printf("%d %d\n", st, en);
		for (int i = 0; i < 2; i++, puts(""))
			for (int j = 0; j < 2; j++)
				printf("%lld ", dp[i][j]);
		puts("-------");
	}
};

int N, Q;
ll cost[MAXN];
vector <pair <int, pii>> adj[MAXN], ch[MAXN];
vector <ll> opt[MAXN];
ll mn1[MAXN], mn2[MAXN], up[MAXN];
int dep[MAXN], sub[MAXN];
int pos[MAXN], idx[MAXN], head[MAXN];
int anc[MAXN][LOG];
node t[2 * offset];
int chain, ptr;

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", cost + i);
	for (int i = 1; i < N; i++) {
		int x, y;
		ll w1, w2;
		scanf("%d%d%lld%lld", &x, &y, &w1, &w2);
		adj[x].push_back({y, {w1, w2}});
		adj[y].push_back({x, {w1, w2}});
	}
}

void dfs_prep(int x, int p) {
	sub[x] = 1;
	mn1[x] = cost[x];
	mn2[x] = INF;
	up[x] = INF;
	anc[x][0] = p;
	for (auto it : adj[x]) 
		if (it.fs != p) {
			ch[x].push_back(it);
			dep[it.fs] = dep[x] + 1;
			dfs_prep(it.fs, x); 
			sub[x] += sub[it.fs];
			ll tmp = mn1[it.fs] + it.sc.fs + it.sc.sc;
			opt[x].push_back(tmp);
			if (tmp <= mn1[x]) {
				mn2[x] = mn1[x];
				mn1[x] = tmp;
			}
			else if (tmp < mn2[x]) 
				mn2[x] = tmp;
		}	
}

void dfs_dp(int x) {
	for (int i = 0; i < ch[x].size(); i++) {
		up[ch[x][i].fs] = min(up[ch[x][i].fs], ch[x][i].sc.fs + ch[x][i].sc.sc + min(up[x], opt[x][i] == mn1[x] ? mn2[x] : mn1[x])); 
		dfs_dp(ch[x][i].fs);
	}
}

void dfs_hld(int x) {
	if (!head[chain])
		head[chain] = x;
	idx[x] = chain;
	pos[x] = ptr++;
	
	int spec = 0;
	for (auto it : ch[x])
		if (sub[it.fs] > sub[spec])
			spec = it.fs;
	
	if (spec)
		dfs_hld(spec);
	
	for (auto it : ch[x]) 
		if (it.fs != spec) {
			chain++;
			dfs_hld(it.fs);
		}
	
	for (auto it : ch[x]) {
		node &ref = t[pos[it.fs] + offset];
		ref.st = x;
		ref.en = it.fs;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 2; k++) 
					ref.dp[i][j] = min(ref.dp[i][j], (k ? it.sc.sc : it.sc.fs) + (i == k ? 0 : cost[x]) + (j == k ? 0 : cost[it.fs]));
	}
}

int lca(int a, int b) {
	if (dep[a] < dep[b])
		swap(a, b);
	int diff = dep[a] - dep[b];
	for (int i = 0; i < LOG; i++)
		if (diff >> i & 1)
			a = anc[a][i];
	if (a == b)
		return a;
	for (int i = LOG - 1; i >= 0; i--)
		if (anc[a][i] != anc[b][i]) {
			a = anc[a][i];
			b = anc[b][i];
		}
	return anc[a][0];
}

node merge(node lft, node rig) {
	if (lft.st == -1)
		return rig;
	if (rig.st == -1)
		return lft;
	node res;
	res.st = lft.st;
	res.en = rig.en;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					res.dp[i][j] = min(res.dp[i][j], lft.dp[i][k] + rig.dp[l][j] + (k == l ? 0 : cost[lft.en]));
	return res;
}

node rev(node n) {
	swap(n.st, n.en);
	swap(n.dp[0][1], n.dp[1][0]);
	return n;
}

node query(int x, int lo, int hi, int from, int to) {
	if (lo >= to || hi <= from)
		return node();
	if (lo >= from && hi <= to)
		return t[x];
	int mid = (lo + hi) / 2;
	return merge(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

node query(int from, int to) {
	return query(1, 0, offset, from, to);
}

node query_up(int x, int y) {
	node res;
	if (x == y) {
		res.st = res.en = x;
		res.dp[0][0] = res.dp[1][1] = 0;
		res.dp[0][1] = res.dp[1][0] = cost[x];
		return res;
	}
	while (1) {
		int curr = idx[x];
		if (curr == idx[y]) {
			res = merge(query(pos[y] + 1, pos[x] + 1), res);
			break;
		}
		res = merge(query(pos[head[curr]], pos[x] + 1), res);
		x = anc[head[curr]][0];
	}
	return res;
}

ll path(int u, int w1, int v, int w2) {
	int l = lca(u, v);
	return merge(rev(query_up(u, l)), query_up(v, l)).dp[w1][w2];
}

void solve() {
	dfs_prep(1, 0);
	dfs_dp(1);
	
	for (int i = 1; i <= N; i++)
		cost[i] = min(cost[i], min(mn1[i], up[i]));
		
	dfs_hld(1);
	
	for (int j = 1; j < LOG; j++)
		for (int i = 1; i <= N; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
	
	for (int i = offset - 1; i >= 0; i--)
		t[i] = merge(t[2 * i], t[2 * i + 1]);
		
	scanf("%d", &Q);	
	while (Q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		u++; v++;
		printf("%lld\n", path(u / 2, u % 2, v / 2, v % 2));
	}
}

int main() {
	load();
	solve();
	return 0;
}