#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int maxl = 30;

int n, newint = 2, f[maxn];

struct node{
	int lc;
	int rc;
	int answer;
	int pre;
	int suf;
	int fil;
	node(){
		lc = -1, rc = -1, answer = 0, pre = 0, suf = 0, fil = 0;
	}
};

void debug(node x){
	cout << "answer is : " << x.answer << endl;
	cout << "pre is : " << x.pre << endl;
	cout << "suf is : " << x.suf << endl;
	cout << "fil is : " << x.fil << endl;
}

node merge(node fi, node se, int lc_ = -1, int rc_ = -1){
	node ret;
	ret.lc = lc_, ret.rc = rc_;
	ret.answer = fi.answer + se.answer - f[fi.suf] - f[se.pre] + f[fi.suf + se.pre];
	ret.pre = fi.pre + fi.fil * se.pre;
	ret.suf = se.suf + se.fil * fi.suf;
	ret.fil = fi.fil & se.fil;
	return ret;
}

node seg[maxn * maxl];

node get(int id, int L, int R, int l, int r){
	if (L == l and R == r)
		return seg[id];
	int mid = (L + R) >> 1;
	if (mid >= r)
		return get(seg[id].lc, L, mid, l, r);
	if (mid <= l)
		return get(seg[id].rc, mid, R, l, r);
	return merge(get(seg[id].lc, L, mid, l, mid), get(seg[id].rc, mid, R, mid, r));
}

int add(int id, int L, int R, int idx){
	int myid = newint ++;
	seg[myid].lc = seg[id].lc, seg[myid].rc = seg[id].rc;
	if (L + 1 == R){
		seg[myid].pre = seg[myid].suf = seg[myid].fil = 1;
		seg[myid].answer = f[1];
		return myid;
	}
	int mid = (L + R) >> 1;
	if (idx < mid)
		seg[myid].lc = add(seg[id].lc, L, mid, idx);
	else
		seg[myid].rc = add(seg[id].rc, mid, R, idx);
	seg[myid] = merge(seg[seg[myid].lc], seg[seg[myid].rc], seg[myid].lc, seg[myid].rc);
	return myid;
}

void build(int id, int L, int R){
	if (L + 1 == R)
		return;
	int mid = (L + R) >> 1;
	seg[id].lc = newint ++;
	build(seg[id].lc, L, mid);
	seg[id].rc = newint ++;
	build(seg[id].rc, mid, R);
}

int h[maxn], up[maxn], st[maxn], par[maxn], sz[maxn];

int getHLD(int v, int u, int root){
	node forv, foru;
	forv.fil = foru.fil = 1;
	while (up[v] != up[u]){
		if (h[up[v]] < h[up[u]]){
			swap(v, u);
			swap(forv, foru);
		}
		node tmp = get(root, 0, n, st[up[v]], st[v] + 1);
		forv = merge(tmp, forv);
		v = par[up[v]];
	}
	if (h[v] < h[u]){
		swap(v, u);
		swap(forv, foru);
	}
	// reverse u
	swap(foru.pre, foru.suf);
	// end of reverse :)
	if (v == u)
		return merge(foru, forv).answer;
	node tmp = get(root, 0, n, st[u] + 1, st[v] + 1);
	forv = merge(tmp, forv);
	return merge(foru, forv).answer;
}

bool cmp(int v, int u){
	return sz[v] > sz[u];
}

vector<int> t[maxn];

int Time = 0;
void dfs(int v, int parent = -1){
	par[v] = parent;
	st[v] = Time ++;
	bool heavy = 1;
	sort(t[v].begin(), t[v].end(), cmp);
	for (auto u : t[v]){
		if (u == parent)
			continue;
		if (heavy)
			up[u] = up[v];
		else
			up[u] = u;
		heavy = 0;
		h[u] = h[v] + 1;
		dfs(u, v);
	}
}

int dfs_sz(int v, int par = -1){
	sz[v] = 1;
	for (auto u : t[v])
		if (u != par)
			sz[v] += dfs_sz(u, v);
	return sz[v];
}

void buildHLD(){
	dfs_sz(0);
	dfs(0);
	build(1, 0, n);
}

struct Edge{
	int fi;
	int se;
	int weight;
	bool operator < (const Edge &other) const{
		return weight > other.weight;
	}
};
Edge edge[maxn];

int root[maxn];
int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++)
		cin >> f[i + 1];
	for (int i = 0; i < n - 1; i++){
		cin >> edge[i].fi >> edge[i].se >> edge[i].weight;
		edge[i].fi --, edge[i].se --;
		t[edge[i].fi].push_back(edge[i].se);
		t[edge[i].se].push_back(edge[i].fi);
	}
	buildHLD();
//	for (int i = 0; i < n; i++)
//		cerr << "Up of " << i << " is : " << up[i] << endl;
	sort(edge, edge + n - 1);
	int lastroot = 1;
	for (int i = 0; i < n - 1; i++){
		int v = edge[i].fi, u = edge[i].se;
		if (h[v] < h[u])
			swap(v, u);
//		cout << "# " << i << " ----> " << v << " with starting time : " << st[v] << endl;
		root[i] = add(lastroot, 0, n, st[v]);
		lastroot = root[i];
	}
	for (int i = 0; i < q; i++){
		int v, u, l;
		cin >> v >> u >> l;
		v --, u --;
		int lo = -1, hi = n - 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (edge[mid].weight >= l)
				lo = mid;
			else
				hi = mid;
		}
//		cout << "times is when : " << lo << endl;
		if (lo == -1){
			cout << 0 << '\n';
			continue;
		}
		cout << getHLD(v, u, root[lo]) << '\n';
	}
}