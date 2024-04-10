
// Problem : E. Little Elephant and Tree
// Contest : Codeforces - Codeforces Round #157 (Div. 1)
// URL : https://codeforces.com/contest/258/problem/E
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r, c;
	int sum;
};

int N, M;
vector<int> graph[100005];
int ans[100005];
int lft[100005], rht[100005], t;
vector<int> v[100005];
Node seg[1000000];

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		return;
	}
	int mid = (l+r)/2;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void upd(int l, int r, int v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].c += v;
		if(!seg[idx].c){
			seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
		}
		else{
			seg[idx].sum = r - l + 1;
		}
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		upd(l ,r, v, 2*idx);
	}
	else if(l > mid){
		upd(l, r, v, 2*idx+1);
	}
	else{
		upd(l, mid, v, 2*idx);
		upd(mid+1, r, v, 2*idx+1);
	}
	if(seg[idx].c){
		seg[idx].sum = seg[idx].r - seg[idx].l + 1;
	}
	else{
		seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
	}
}

void dfs1(int n, int p){
	lft[n] = ++t;
	for(int e : graph[n]){
		if(e != p){
			dfs1(e, n);
		}
	}
	rht[n] = t;
}

void dfs2(int n, int p){
	if(v[n].size()){
		upd(lft[n], rht[n], 1, 1);
	}
	for(int k : v[n]){
		upd(lft[k], rht[k], 1, 1);
	}
	ans[n] = seg[1].sum;
	for(int e : graph[n]){
		if(e != p){
			dfs2(e, n);
		}
	}
	if(v[n].size()){
		upd(lft[n], rht[n], -1, 1);
	}
	for(int k : v[n]){
		upd(lft[k], rht[k], -1, 1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i < N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	build(1, N, 1);
	dfs1(1, 0);
	dfs2(1, 0);
	for(int n = 1; n<=N; n++){
		cout << max(ans[n]-1, 0) << " ";
	}
}