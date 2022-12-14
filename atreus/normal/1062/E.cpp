#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
const int maxl = 18;

vector<int> t[maxn];
int par[maxl][maxn], h[maxn];
int n, Time = 1, st[maxn];

struct node{
	int mxm;
	int mnm;
	int sndmxm;
	int sndmnm;
	node (int mxm_ = 0, int mnm_ = 0){
		mxm = mxm_;
		sndmxm = mxm_;
		mnm = mnm_;
		sndmnm = mnm_;
	}
	void updatemxm(node a, node b){
		vector<pair<int, int> > t;
		t.push_back({st[a.mxm], a.mxm});
		t.push_back({st[a.sndmxm], a.sndmxm});
		t.push_back({st[b.mxm], b.mxm});
		t.push_back({st[b.sndmxm], b.sndmxm});
		sort(t.begin(), t.end());
		mxm = t[3].second;
		sndmxm = t[2].second;
	}
	void updatemnm(node a, node b){
		vector<pair<int, int> > t;
		t.push_back({st[a.mnm], a.mnm});
		t.push_back({st[a.sndmnm], a.sndmnm});
		t.push_back({st[b.mnm], b.mnm});
		t.push_back({st[b.sndmnm], b.sndmnm});
		sort(t.begin(), t.end());
		mnm = t[0].second;
		sndmnm = t[1].second;
	}
} seg[4 * maxn];

node merge(node fi, node se){
	node T;
	T.updatemxm(fi, se);
	T.updatemnm(fi, se);
	return T;
}

node get(int id, int L, int R, int l, int r){
	if (r <= L or R <= l)
		return node(0, n + 1);
	if (l <= L and R <= r)
		return seg[id];
	int mid = (L + R) >> 1;
	return merge(get(2 * id + 0, L, mid, l, r), get(2 * id + 1, mid, R, l, r));
}

void build(int id, int L, int R){
	if (L + 1 == R){
		seg[id].mxm = seg[id].mnm = L;
		seg[id].sndmxm = 0;
		seg[id].sndmnm = n + 1;
		return;
	}
	int mid = (L + R) >> 1;
	build(2 * id + 0, L, mid);
	build(2 * id + 1, mid, R);
	seg[id] = merge(seg[2 * id + 0], seg[2 * id + 1]);
}

void dfs(int v, int p = -1){
	st[v] = Time ++;
	par[0][v] = p;
	for (int i = 1; par[i - 1][v] != -1 and i < maxl; i++)
		par[i][v] = par[i - 1][par[i - 1][v]];
	for (auto u : t[v]){
		h[u] = h[v] + 1;
		dfs(u, v);
	}
}

int lca(int v, int u){
	if (h[v] < h[u])
		return lca(u, v);
	for (int i = maxl - 1; i >= 0; i--)
		if (h[v] - (1 << i) >= h[u])
			v = par[i][v];
	if (v == u)
		return v;
	for (int i = maxl - 1; i >= 0; i--){
		if (par[i][v] != par[i][u]){
			v = par[i][v];
			u = par[i][u];
		}
	}
	return par[0][v];
}

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> n >> q;
	for (int v = 2; v <= n; v++){
		int u;
		cin >> u;
		t[u].push_back(v);
	}
	int root = 1;
	memset(par, -1, sizeof par);
	st[0] = 0, st[n + 1] = n + 1;
	dfs(root);
	build(1, 1, n + 1);
	for (int query = 1; query <= q; query++){
		int l, r;
		cin >> l >> r;
		node T = get(1, 1, n + 1, l, r + 1);
		int fi = lca(T.sndmxm, T.mnm);
		int se = lca(T.sndmnm, T.mxm);
		if (h[fi] >= h[se])
			cout << T.mxm << " ";
		else
			cout << T.mnm << " ";
		cout << max(h[fi], h[se]) << '\n';

	}
}