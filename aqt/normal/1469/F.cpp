
// Problem : F. Power Sockets
// Contest : Codeforces - Educational Codeforces Round 101 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1469/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long tot;
	long long lzy;
};

int N, K;
priority_queue<int> pq;
Node seg[400005 * 4];

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		seg[idx].tot = (l == 0);
		return;
	}
	int mid = (l + r)/2;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	seg[idx].tot = seg[2*idx].tot + seg[2*idx+1].tot;
}

void pd(int idx){
	if(seg[idx].lzy){
		seg[2*idx].tot += seg[idx].lzy * (seg[2*idx].r - seg[2*idx].l + 1);
		seg[2*idx+1].tot += seg[idx].lzy * (seg[2*idx+1].r - seg[2*idx+1].l + 1);
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[idx].lzy = 0;
	}
}

void upd(int l, int r, int v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].lzy += v;
		seg[idx].tot += 1LL * v * (seg[idx].r - seg[idx].l + 1);
		return;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r) / 2;
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
	seg[idx].tot = seg[2*idx].tot + seg[2*idx+1].tot;
}

int walk(int k, int idx){
	if(seg[idx].l == seg[idx].r){
		return seg[idx].l;
	}
	pd(idx);
	if(seg[2*idx].tot < k){
		return walk(k - seg[2*idx].tot, 2*idx+1);
	}
	else{
		return walk(k, 2*idx);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i =1; i <= N; i++){
		int n;
		cin >> n;
		pq.push(n);
	}
	build(0, 400000, 1);
	int ans = 1e9;
	long long tot = 1;
	while(pq.size()){
		int n = pq.top();
		pq.pop();
		tot += n - 2;
		int d = walk(1, 1);
		upd(d, d, -1, 1);
		d++;
		int h1 = n/2;
		int h2 = n - n/2 - 1;
		upd(d+1, h1+d, 1, 1);
		upd(d+1, h2+d, 1, 1);
		if(tot >= K){
			ans = min(ans, walk(K, 1));
		}
	}
	if(ans == 1e9){
		ans = -1;
	}
	cout << ans;
}