
// Problem : D. Odd Mineral Resource
// Contest : Codeforces - Codeforces Round #700 (Div. 1)
// URL : https://codeforces.com/contest/1479/problem/D
// Memory Limit : 1024 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long x;
	Node * lft;
	Node * rht;
	
	Node * copy(){
		Node * n = new Node();
		n->l = l;
		n->r = r;
		n->x = x;
		n->lft = lft;
		n->rht = rht;
		return n;
	}
};

int N, Q;
const int D = 20;
int arr[300005];
long long hsh[300005];
vector<int> graph[300005];
Node * pseg[300005];
int dep[300005];
int par[300005];
int tbl[20][300005];
mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

Node * build(int l, int r){
	Node * n = new Node();
	n->l = l;
	n->r = r;
	n->x = 0;
	n->lft = n->rht = NULL;
	if(l == r){
		return n;
	}
	int mid = l + r >> 1;
	n->lft = build(l, mid);
	n->rht = build(mid+1, r);
	return n;
}

Node * upd(int p, long long v, Node * n){
	Node * ret = n->copy();
	if(n->l == n->r){
		ret->x ^= v;
		return ret;
	}
	int mid = n->l + n->r >> 1;
	if(p <= mid){
		ret->lft = upd(p, v, n->lft);
	}
	else{
		ret->rht = upd(p, v, n->rht);
	}
	ret->x = ret->lft->x ^ ret->rht->x;
	return ret;
}

long long query(int l, int r, Node * n){
	if(r < n->l || l > n->r){
		return 0;
	}
	if(n->l == l && n->r == r){
		return n->x;
	}
	int mid = n->l + n->r >> 1;
	if(r <= mid){
		return query(l, r, n->lft);
	}
	else if(l > mid){
		return query(l, r, n->rht);
	}
	else{
		return query(l, mid, n->lft) ^ query(mid+1, r, n->rht);
	}
}

void dfs(int n){
	pseg[n] = upd(arr[n], hsh[arr[n]], pseg[par[n]]);
	for(int e : graph[n]){
		if(e != par[n]){
			tbl[0][e] = par[e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
	}
}

int lca(int u, int v){
	if(dep[u] < dep[v]){
		swap(u, v);
	}
	for(int d = D - 1; d >= 0; d--){
		if(dep[tbl[d][u]] >= dep[v]){
			u = tbl[d][u];
		}
	}
	if(u == v){
		return u;
	}
	for(int d = D - 1; d >= 0; d--){
		if(tbl[d][u] != tbl[d][v]){
			u = tbl[d][u];
			v = tbl[d][v];
		}
	}
	return par[v];
}

long long pathquery(int u, int v, int p, int l, int r, Node * a, Node * b){
	long long ret = query(l, r, a) ^ query(l, r, b);
	if(l <= arr[p] && arr[p] <= r){
		ret ^= hsh[arr[p]];
	}
	return ret;
}

int godown(int l, int r, int u, int v, int p, Node * a, Node * b){
	if(a->l == a->r){
		return a->l;
	}
	int val = a->lft->x ^ b->lft->x;
	if(a->lft->l <= arr[p] && a->lft->r >= arr[p]){
		val ^= hsh[arr[p]];
	}
	if(val){
		return godown(l, r, u, v, p, a->lft, b->lft);
	}
	else{
		return godown(l, r, u, v, p, a->rht, b->rht);
	}
}

int solve(int l, int r, int u, int v, int p, Node * a, Node * b){
	if(a->l == l && a->r == r){
		int val = a->x ^ b->x;
		if(a->l <= arr[p] && a->r >= arr[p]){
			val ^= hsh[arr[p]];
		}
		if(val){
			return godown(l, r, u, v, p, a, b);
		}
		return 0;
	}
	int mid = a->l + a->r >> 1;
	if(r <= mid){
		return solve(l, r, u, v, p, a->lft, b->lft);
	}
	else if(l > mid){
		return solve(l, r, u, v, p, a->rht, b->rht);
	}
	else{
		int tmp = solve(l, mid, u, v, p, a->lft, b->lft);
		if(tmp){
			return tmp;
		}
		else{
			return solve(mid+1, r, u, v, p, a->rht, b->rht);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		hsh[i] = uniform_int_distribution<long long>(1, LLONG_MAX) (rando);
	}	
	for(int i = 1; i < N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	pseg[0] = build(1, N);
	dep[1] = 1;
	dfs(1);
	for(int d = 1; d < D; d++){
		for(int n = 1; n <= N; n++){
			tbl[d][n] = tbl[d-1][tbl[d-1][n]];
		}
	}
	while(Q--){
		int u, v, ql, qr;
		cin >> u >> v >> ql >> qr;
		const int p = lca(u, v);
		if(pathquery(u, v, p, ql, qr, pseg[u], pseg[v]) == 0){
			cout << -1 << "\n";
		}
		else{
			cout << solve(ql, qr, u, v, p, pseg[u], pseg[v]) << "\n";
		}
	}
}