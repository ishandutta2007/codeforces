
// Problem : E. Nastya and King-Shamans
// Contest : Codeforces - Codeforces Round #489 (Div. 2)
// URL : https://codeforces.com/problemset/problem/992/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	long long mn, lzy;
};

int N, Q;
node seg[1000000];
long long pre[1000000], arr[1000000];

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	if(l == r){
		seg[idx].mn = pre[l-1] - arr[l];
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
	//cout << idx << " " << seg[idx].mn << "\n";
}

void pd(int idx){
	if(seg[idx].lzy){
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[2*idx].mn += seg[idx].lzy;
		seg[2*idx+1].mn += seg[idx].lzy;
		seg[idx].lzy = 0;
	}
}

void upd(int l, int r, int v, int idx){
	//cout << idx << "\n";
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].mn += v;
		seg[idx].lzy += v;
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	pd(idx);
	if(r<=mid){
		upd(l, r, v, 2*idx);
	}
	else if(l > mid){
		upd(l, r, v, 2*idx+1);
	}
	else{
		upd(l, mid, v, 2*idx);
		upd(mid+1, r, v, 2*idx+1);
	}
	//cout << idx << " " << seg[2*idx].mn << " " << seg[2*idx+1].mn << "\n";
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
	//cout << seg[idx].mn << "\n";
}
/*
long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].mx;
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
		return query(l, mid, 2*idx) + query(mid+1, r, 2*idx+1);
	}
}
*/

int walk(int idx){
	//cout << " " << idx << " " << seg[idx].mn << "\n";
	if(seg[idx].mn > 0){
		return 0;
	}
	if(seg[idx].l == seg[idx].r){
		if(seg[idx].mn == 0){
			return seg[idx].l;
		}
		else{
			return 0;
		}
	}
	pd(idx);
	int k = walk(2*idx);
	if(k){
		return k;
	}
	k = walk(2*idx+1);
	return k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		pre[i] = pre[i-1] + arr[i];
	}
	build(1, N+1, 1);
	while(Q--){
		int n ,v;
		cin >> n >> v;
		int d = v - arr[n];
		upd(n, n, -d, 1);
		upd(n+1, N+1, d, 1);
		int k = walk(1);
		if(k && k != N+1){
			cout << k << "\n";
		}
		else{
			cout << -1 << "\n";
		}
		arr[n] = v;
	}
}