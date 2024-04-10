
// Problem : G. Yet Another Maxflow Problem
// Contest : Codeforces - Educational Codeforces Round 34 (Rated for Div. 2)
// URL : https://codeforces.com/contest/903/problem/G
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct SegmentTree{
	struct node{
		int l, r;
		long long mn, lzy;
	};
	node seg[1000000];
	void build(int l, int r, int idx){
		seg[idx].l = l, seg[idx].r = r;
		if(l == r){
			return;
		}
		int mid = l+r>>1;
		build(l, mid, 2*idx);
		build(mid+1, r, 2*idx+1);
	}
	void pd(int idx){
		if(seg[idx].lzy){
			seg[2*idx].mn += seg[idx].lzy;
			seg[2*idx+1].mn += seg[idx].lzy;
			seg[2*idx].lzy += seg[idx].lzy;
			seg[2*idx+1].lzy += seg[idx].lzy;
			seg[idx].lzy = 0;
		}
	}
	void upd(int l, int r, long long v, int idx){
		if(seg[idx].l == l && seg[idx].r == r){
			seg[idx].lzy += v;
			seg[idx].mn += v;
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
		seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
	}
	long long query(int l, int r, int idx){
		if(seg[idx].l == l && seg[idx].r == r){
			return seg[idx].mn;
		}
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
};

int N, M, Q;
long long arr[200005], brr[200005];
vector<pair<int, int>> v[200005];
SegmentTree seg1, seg2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for(int i = 2; i<=N; i++){
		cin >> arr[i-1] >> brr[i];
	}
	for(int i = 1; i<=M; i++){
		int a, b, x;
		cin >> a >> b >> x;
		v[a].emplace_back(b, x);
	}
	seg1.build(1, N, 1);
	for(int i = 1; i<=N; i++){
		seg1.upd(i, i, brr[i], 1);
	}
	seg2.build(1, N, 1);
	for(int i = 1; i<=N; i++){
		for(auto p : v[i]){
			seg1.upd(1, p.first, p.second, 1);
		}
		seg2.upd(i, i, seg1.seg[1].mn + arr[i], 1);
	}
	cout << seg2.seg[1].mn << "\n";
	while(Q--){
		int x, v;
		cin >> x >> v;
		seg2.upd(x, x, v-arr[x], 1);
		arr[x] = v;
		cout << seg2.seg[1].mn << "\n";
	}
}