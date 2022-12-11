
// Problem : C. Nikita and stack
// Contest : Codeforces - 8VC Venture Cup 2017 - Final Round
// URL : https://codeforces.com/contest/756/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	int mx, lzy;
};

int N;
node seg[400005];
int arr[100005];

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
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[2*idx].mx += seg[idx].lzy;
		seg[2*idx+1].mx += seg[idx].lzy;
		seg[idx].lzy = 0;
	}
}

void upd(int l, int r, int v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].mx += v;
		seg[idx].lzy += v;
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		upd(l, r, v, 2*idx);
	}
	else if(l > mid){
		upd(l ,r, v, 2*idx+1);
	}
	else{
		upd(l, mid,v, 2*idx);
		upd(mid+1, r, v, 2*idx+1);
	}
	seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
}

int walk(int idx){
	if(seg[idx].mx <= 0){
		return 0;
	}
	if(seg[idx].l == seg[idx].r){
		return seg[idx].l;
	}
	pd(idx);
	if(seg[2*idx+1].mx > 0){
		return walk(2*idx+1);
	}
	else{
		return walk(2*idx);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	build(1, N, 1);
	arr[0] = -1;
	for(int i = 1; i<=N; i++){
		int k, t, n;
		cin >> k >> t;
		if(t == 1){
			cin >> n;
			arr[k] = n;
			upd(1, k, 1, 1);		
		}
		else{
			upd(1, k, -1, 1);
		}
		cout << arr[walk(1)] << "\n";
	}
}