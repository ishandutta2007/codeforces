
// Problem : E. Jamie and Tree
// Contest : Codeforces - Codeforces Round #457 (Div. 2)
// URL : https://codeforces.com/contest/916/problem/E
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long lzy, sum;
} seg[1000005];

int N, Q;
vector<int> graph[100005];
int arr[100005];
int lft[100005], rht[100005], t;
int dep[100005];
int tbl[20][100005];
int lst[3];

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	if(l == r){
		return;
	}
	int mid = (l+r)>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void pd(int idx){
	if(seg[idx].lzy){
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[2*idx].sum += seg[idx].lzy * (seg[2*idx].r - seg[2*idx].l + 1);
		seg[2*idx+1].sum += seg[idx].lzy * (seg[2*idx+1].r - seg[2*idx+1].l + 1);
		seg[idx].lzy = 0;
	}
}

void upd(int l, int r, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].lzy += v;
		seg[idx].sum += (seg[idx].r - seg[idx].l + 1) * v;
		return;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r) >> 1;
	if(r <= mid){
		upd(l, r, v, 2*idx);
	}
	else if(l > mid){
		upd(l, r, v, 2*idx+1);
	}
	else{
		upd(l, mid, v, 2*idx);
		upd(mid+1, r, v, 2*idx+1);
	}
	seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
}

long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].sum;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r) >> 1;
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else{
		return query(l, mid, 2*idx) + query(mid+1, r, 2*idx+1);
	}
}

int lca(int u, int v){
	if(dep[u] < dep[v]){
		swap(u, v);
	}
	for(int d = 19; d>=0; d--){
		if(dep[tbl[d][u]] >= dep[v]){
			u = tbl[d][u];
		}
	}
	if(u == v){
		return u;
	}
	for(int d = 19; d>=0; d--){
		if(tbl[d][u] != tbl[d][v]){
			u = tbl[d][u];
			v = tbl[d][v];
		}
	}
	return tbl[0][u];
}

int clmb(int u, int k){
	assert(dep[u] >= k);
	for(int d = 19; d>=0; d--){
		if(dep[tbl[d][u]] >= k){
			u = tbl[d][u];
		}
	}
	return u;
}

void dfs(int n){
	lft[n] = ++t;
	for(int e : graph[n]){
		if(e != tbl[0][n]){
			tbl[0][e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
	}
	rht[n] = t;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dep[1] = 1;
	dfs(1);
	for(int d = 1; d<20; d++){
		for(int n = 1; n<=N; n++){
			tbl[d][n] = tbl[d-1][tbl[d-1][n]];
		}
	}
	int rt = 1;
	build(1, N, 1);
	for(int i = 1; i<=N; i++){
		upd(lft[i], lft[i], arr[i], 1);
	}
	while(Q--){
		int c;
		cin >> c;
		if(c == 1){
			cin >> rt;
		}
		else if(c == 2){
			int u, v, x;
			cin >> u >> v >> x;
			lst[0] = lca(u, v);
			lst[1] = lca(u, rt);
			lst[2] = lca(rt, v);
			if(dep[lst[0]] > max(dep[lst[1]], dep[lst[2]])){
				upd(lft[lst[0]], rht[lst[0]], x, 1);
			}
			else{
				if(dep[lst[1]] < dep[lst[2]]){
					swap(lst[1], lst[2]);
				}
				upd(1, N, x, 1);
				if(lst[1] != rt){
					int w = clmb(rt, dep[lst[1]]+1);
					upd(lft[w], rht[w], -x, 1);
				}
			}
		}
		else{
			int u;
			cin >> u;
			if(u == rt){
				cout << query(1, N, 1) << "\n";
			}
			else if(lft[u] < lft[rt] && rht[u] >= rht[rt]){
				int w = clmb(rt, dep[u]+1);
				cout << query(1, N, 1) - query(lft[w], rht[w], 1) << "\n";
			}
			else{
				cout << query(lft[u], rht[u], 1) << "\n";
			}
		}
	}
}