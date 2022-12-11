
// Problem : F. DFS
// Contest : Codeforces - Lyft Level 5 Challenge 2018 - Final Round (Open Div. 1)
// URL : https://codeforces.com/contest/1074/problem/F
// Memory Limit : 512 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r, mx, cnt, lzy;
};

int N, Q;
vector<int> graph[200005];
vector<int> lst[200005];
int lft[200005], rht[200005];
int t;
int par[200005];
Node seg[1000000];
set<pair<int, int>> st;

void dfs(int n){
	lft[n] = ++t;
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dfs(e);
			lst[n].emplace_back(lft[e]);
		}
	}
	if(n-1){
		graph[n].erase(find(graph[n].begin(), graph[n].end(), par[n]));
	}
	rht[n] = t;
}

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	seg[idx].cnt = r - l + 1;
	if(l == r){
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void upd(int l, int r, int v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].mx += v;
		seg[idx].lzy += v;
		return;
	}
	if(seg[idx].lzy){
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[2*idx].mx += seg[idx].lzy;
		seg[2*idx+1].mx += seg[idx].lzy;
		seg[idx].lzy = 0;
	}
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
	if(seg[2*idx+1].mx == seg[2*idx].mx){
		seg[idx].mx = seg[2*idx].mx;
		seg[idx].cnt = seg[2*idx+1].cnt + seg[2*idx].cnt;		
	}
	else if(seg[2*idx+1].mx > seg[2*idx].mx){
		seg[idx].mx = seg[2*idx+1].mx;
		seg[idx].cnt = seg[2*idx+1].cnt;
	}
	else{
		seg[idx].mx = seg[2*idx].mx;
		seg[idx].cnt = seg[2*idx].cnt;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i= 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	build(1, N, 1);
	while(Q--){
		int u, v;
		cin >> u >> v;
		if(u > v){
			swap(u, v);
		}
		int val = 1;
		if(st.count(make_pair(u, v))){
			st.erase(make_pair(u, v));
			val = -1;
		}
		else{
			st.insert(make_pair(u, v));
		}
		if(lft[u] < lft[v] && rht[u] >= rht[v]){
			swap(u, v);
		}
		if(lft[v] < lft[u] && rht[v] >= rht[u]){
			int idx = upper_bound(lst[v].begin(), lst[v].end(), lft[u]) - lst[v].begin() - 1;
			int w = graph[v][idx];
			//cout << "node; " << w << "\n";
			upd(lft[u], rht[u], val, 1);
			upd(1, N, val, 1);
			upd(lft[w], rht[w], -val, 1);	
		}
		else{
			upd(lft[u], rht[u], val, 1);
			upd(lft[v], rht[v], val, 1);
		}
		if(seg[1].mx == st.size()){
			cout << seg[1].cnt << "\n";
		}
		else{
			cout << 0 << "\n";
		}
	}
}