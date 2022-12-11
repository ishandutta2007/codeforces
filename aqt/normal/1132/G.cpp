
// Problem : G. Greedy Subsequences
// Contest : Educational Codeforces Round 61 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1132/G
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	long long v, lzy;
};

int N, K;
vector<int> graph[1000005];
int arr[1000005];
int lft[1000005], rht[1000005], t;
node seg[8000005];

void dfs(int n){
	lft[n] = ++t;
	for(int e : graph[n]){
		dfs(e);
	}
	rht[n] = ++t;
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

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	if(l == r){
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void upd(int l, int r, int v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].lzy += v;
		seg[idx].v += v;
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
	seg[idx].v = max(seg[2*idx].v, seg[2*idx+1].v);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	stack<int> stk;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		while(stk.size() && arr[stk.top()] < arr[i]){
			int n = stk.top();
			stk.pop();
			graph[i].push_back(n);
		}
		stk.push(i);
	}
	while(stk.size()){
		int n = stk.top();
		stk.pop();
		graph[N+1].push_back(n);
	}
	dfs(N+1);
	build(1, 2*N+2, 1);
	for(int i = 1; i<K; i++){
		upd(lft[i], rht[i], 1, 1);
	}
	for(int i = K; i<=N; i++){
		upd(lft[i], rht[i], 1, 1);
		cout << seg[1].v << " ";
		upd(lft[i-K+1], rht[i-K+1], -2*N, 1);
	}
}