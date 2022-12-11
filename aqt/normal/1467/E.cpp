
// Problem : E. Distinctive Roots in a Tree
// Contest : Codeforces - Codeforces Round #695 (Div. 2)
// URL : https://codeforces.com/contest/1467/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r, v, lzy;
};

int N;
int arr[200005];
vector<int> graph[200005];
int lft[200005], rht[200005], t;
map<int, int> fre;
int par[200005];
Node seg[2000000];

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(seg[idx].l == seg[idx].r){
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void pd(int idx){
	if(seg[idx].lzy){
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[2*idx].v += seg[idx].lzy;
		seg[2*idx+1].v += seg[idx].lzy;
		seg[idx].lzy = 0;
	}
}

void upd(int l, int r, int v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].lzy += v;
		seg[idx].v += v;
		return;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r)/2;
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
}

int get(int p, int idx){
	if(seg[idx].l == seg[idx].r){
		return seg[idx].v;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(p <= mid){
		return get(p, 2*idx);
	}
	else{
		return get(p, 2*idx+1);
	}
}

void dfs1(int n){
	lft[n] = ++t;
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dfs1(e);
		}
	}
	rht[n] = t;
}

map<int, int> dfs2(int n){
	map<int, int> ret;
	ret[arr[n]] = 1;
	for(int e : graph[n]){
		if(e == par[n]){
			continue;
		}
		par[e] = n;
		auto mp = dfs2(e);
		if(mp.count(arr[n])){
			upd(1, N, 1, 1);
			upd(lft[e], rht[e], -1, 1);
		}
		if(mp.size() > ret.size()){
			swap(mp, ret);
		}
		for(auto p : mp){
			ret[p.first] += p.second;	
		}
	}
	if(ret[arr[n]] != fre[arr[n]]){
		upd(lft[n], rht[n], 1, 1);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		fre[arr[i]]++;
	}
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs1(1);
	build(1, N, 1);
	dfs2(1);
	int ans = 0;
	for(int i = 1; i<=N; i++){
		ans += !get(i, 1);
	}
	cout << ans;
}