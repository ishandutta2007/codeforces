
// Problem : F. Nearest Leaf
// Contest : Codeforces - Codeforces Global Round 1
// URL : https://codeforces.com/problemset/problem/1110/F
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long v, lzy;
};

int N, Q;
vector<pair<int, int>> graph[500005];
long long dist[500005];
int lft[500005], rht[500005], nd[500005];
vector<int> qu[500005];
int st[500005], ed[500005], t;
int et[500005];
int par[500005];
long long ans[500005];
Node seg[2000005];

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		if(graph[et[l]].empty()){
			seg[idx].v = dist[et[l]];
		}
		else{
			seg[idx].v = LLONG_MAX/2;
		}
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v);
}

void pd(int idx){
	if(seg[idx].lzy){
		seg[2*idx].v += seg[idx].lzy;
		seg[2*idx+1].v += seg[idx].lzy;
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[idx].lzy = 0;
	}
}

void upd(int l, int r, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].v += v;
		seg[idx].lzy += v;
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
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
	seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v);
}

long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].v;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else{
		return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
	}
}

void dfs1(int n){
	st[n] = ++t;
	et[t] = n;
	for(auto e : graph[n]){
		dist[e.first] = dist[n] + e.second;
		dfs1(e.first);
	}
	ed[n] = t;
}

void dfs2(int n){
	for(int q : qu[n]){
		ans[q] = query(lft[q], rht[q], 1);
	}
	for(auto e : graph[n]){
		upd(1, N, e.second, 1);
		upd(st[e.first], ed[e.first], -2*e.second, 1);
		dfs2(e.first);
		upd(1, N, -e.second, 1);
		upd(st[e.first], ed[e.first], 2*e.second, 1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 2; i<=N; i++){
		long long w;
		cin >> par[i] >> w;
		graph[par[i]].emplace_back(i, w);
	}
	for(int q = 1; q<=Q; q++){
		cin >> nd[q] >> lft[q] >> rht[q];
		qu[nd[q]].push_back(q);
	}
	dfs1(1);
	build(1, N, 1);
	dfs2(1);
	for(int q = 1; q<=Q; q++){
		cout << ans[q] << "\n";
	}
}