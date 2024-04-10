#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
#define MAXN 300000

vector <int> nums[MAXN], bcc[MAXN];
int vis[MAXN], low[MAXN], bcc_id[MAXN];
bool cut[MAXN];
stack <int> stk;
int t = 1, nbcc = 0;

void dfs1(int v, int pa) {
	vis[v] = low[v] = t++;
	stk.push(v);
	int child = 0;
	for (int u : nums[v]) {
		if (u == pa) continue;
		if (!vis[u]) {
			dfs1(u, v);
			low[v] = min(low[u], low[v]);
			child++;
			if (low[u] >= vis[v]) {
				cut[v] = true;
				bcc[nbcc].push_back(v);
				bcc_id[v] = nbcc;
				while (bcc[nbcc].back() != u) {
					bcc_id[stk.top()] = nbcc;
					bcc[nbcc].push_back(stk.top());
					stk.pop();
				}
				nbcc++;
			}
		} else {
			low[v] = min(low[v], vis[u]);
		}
	}
	if (pa == -1 and child < 2) {
		cut[v] = false;
	}
}

vector <int> BCtree[MAXN * 2];
int bc_id[MAXN * 2], vertex_num = 0, num[MAXN * 2];

void build_BCtree(int n) {
	for (int i = 0; i < n; ++i) {
		if (cut[i]) {
			num[vertex_num]++;
			bc_id[i] = vertex_num++;
		}
	}
	for (int i = 0; i < nbcc; ++i) {
		bc_id[i + n] = vertex_num++;
		for (int v : bcc[i]) {
			if (cut[v]) {
				BCtree[bc_id[i + n]].push_back(bc_id[v]);
				BCtree[bc_id[v]].push_back(bc_id[i + n]);
			} else {
				bc_id[v] = bc_id[i + n];
				num[bc_id[i + n]]++;
			}
		}
	}
}

void calc(int n) {
	fop (i,0,nbcc) {
		bcc[i].clear();
	}
	fop (i,0,vertex_num) {
		BCtree[i].clear();
		num[i] = 0;
	}
	fop (i,0,n) {
		nums[i].clear();
		vis[i] = low[i] = 0;
		cut[i] = false;
		bcc_id[i] = 0;
	}
	t = 1;
	vertex_num = 0;
	nbcc = 0;
}

int dfs2(int v, int pa, int t, int p) {
	if (v == t) return -1;
	int now = 0;
	for (int u : BCtree[v]) {
		if (u == pa) continue;
		int k = dfs2(u, v, t, p);
		if (k == -1) {
			if (pa != -1) return -1;
		} else {
			now += k + num[u];
		}
	}
	return now;
}


void solve () {
	int n,m,u,v,s,t;
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		u--; v--;
		nums[u].push_back(v);
		nums[v].push_back(u);
	}
	dfs1(0, -1);
	fop(i,0,n) num[i] = 0;
	build_BCtree(n);
	if (!cut[s - 1] or !cut[t - 1]) {
		cout << 0 << endl;
		calc(n);
		return;
	}
	s = bc_id[s - 1];
	t = bc_id[t - 1];
	int aa = dfs2(s, -1, t, 0);
	int bb = dfs2(t, -1, s, 1);
	cout << 1ll * aa * bb << endl;
	calc(n);
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}