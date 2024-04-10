
// Problem : E. Split the Tree
// Contest : Codeforces Round #514 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1059/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	long long w, len, v, lzyw, lzyl, lzyv;
};

int N, L;
long long S;
long long val[100005];
vector<int> graph[100005];
int lft[100005], rht[100005], t;
long long dp[100005];
node seg[1000000];

void pu(int idx){
	seg[idx].w = max(seg[2*idx].w, seg[2*idx+1].w);
	seg[idx].len = max(seg[2*idx].len, seg[2*idx+1].len);
	seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v);	
}

void pd(int idx){
	if(seg[idx].lzyw){
		seg[2*idx].lzyw += seg[idx].lzyw;
		seg[2*idx+1].lzyw += seg[idx].lzyw;
		seg[2*idx].w += seg[idx].lzyw;
		seg[2*idx+1].w += seg[idx].lzyw;
		seg[idx].lzyw = 0;
	}
	if(seg[idx].lzyl){
		seg[2*idx].lzyl += seg[idx].lzyl;
		seg[2*idx+1].lzyl += seg[idx].lzyl;
		seg[2*idx].len += seg[idx].lzyl;
		seg[2*idx+1].len += seg[idx].lzyl;
		seg[idx].lzyl = 0;
	}
	if(seg[idx].lzyv){
		seg[2*idx].lzyv += seg[idx].lzyv;
		seg[2*idx+1].lzyv += seg[idx].lzyv;
		seg[2*idx].v += seg[idx].lzyv;
		seg[2*idx+1].v += seg[idx].lzyv;
		seg[idx].lzyv = 0;
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

void updc(int l, int r, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].w += v;
		seg[idx].len++;
		seg[idx].lzyw += v;
		seg[idx].lzyl++;
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	pd(idx);
	if(r <= mid){
		updc(l, r, v, 2*idx);
	}
	else if(l > mid){
		updc(l, r, v, 2*idx+1);
	}
	else{
		updc(l, mid, v, 2*idx);
		updc(mid+1, r, v, 2*idx+1);
	}
	pu(idx);
}

void updv(int l, int r, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].v += v;
		seg[idx].lzyv += v;
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	pd(idx);
	if(r <= mid){
		updv(l, r, v, 2*idx);
	}
	else if(l > mid){
		updv(l, r, v, 2*idx+1);
	}
	else {
		updv(l, mid, v, 2*idx);
		updv(mid+1, r, v, 2*idx+1);
	}
	pu(idx);
}

long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].v;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	pd(idx);
	if(r <= mid){
		return query(l, r, 2*idx);
	}
	else if(l > mid){
		return query(l, r, 2*idx+1);
	}
	else {
		return min(query(l, mid, 2*idx), query(mid+1, r, 2*idx+1));
	}
}

void walk(int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].len = LLONG_MIN>>1;
		seg[idx].w = LLONG_MIN>>1;
		seg[idx].v = LLONG_MAX>>1;
		return;
	}
	pd(idx);
	if(seg[2*idx].w > S || seg[2*idx].len > L){
		walk(2*idx);
	}
	if(seg[2*idx+1].w > S || seg[2*idx+1].len > L){
		walk(2*idx+1);
	}
	pu(idx);
}

void dfs(int n){
	lft[n] = ++t;
	long long tot = 0;
	for(int e : graph[n]){
		dfs(e);
		tot += dp[e];
	}
	rht[n] = ++t;	
	updc(lft[n], rht[n], val[n], 1);
	updv(lft[n], rht[n], tot, 1);
	walk(1);
	for(int e : graph[n]){
		updv(lft[e], rht[e], -dp[e], 1);
	}
	dp[n] = query(lft[n], rht[n], 1)+1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> L >> S;
	for(int i = 1; i<=N; i++){
		cin >> val[i];
		if(val[i] > S){
			cout << -1 << "\n";
			return 0;
		}
	}
	for(int i = 2; i<=N; i++){
		int p;
		cin >> p;
		graph[p].emplace_back(i);
	}
	build(1, 2*N, 1);
	dfs(1);
	cout << dp[1] << "\n";
}