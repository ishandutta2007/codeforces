
// Problem : C2. Pokmon Army (hard version)
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/C2
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long mx[2], mn[2];
};

int T;
int N, Q;
Node seg[4 * 300005];
int arr[300005];

void pu(int idx){
	seg[idx].mx[0] = max(seg[2*idx].mx[0] + seg[2*idx+1].mx[0], seg[2*idx].mx[1] - seg[2*idx+1].mn[1]);
	seg[idx].mx[1] = max(seg[2*idx].mx[0] + seg[2*idx+1].mx[1], seg[2*idx].mx[1] - seg[2*idx+1].mn[0]);
	seg[idx].mn[0] = min(seg[2*idx].mn[0] + seg[2*idx+1].mn[0], seg[2*idx].mn[1] - seg[2*idx+1].mx[1]);
	seg[idx].mn[1] = min(seg[2*idx].mn[0] + seg[2*idx+1].mn[1], seg[2*idx].mn[1] - seg[2*idx+1].mx[0]);
}

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		seg[idx].mn[1] = seg[idx].mx[1] = arr[l];
		seg[idx].mn[0] = seg[idx].mx[0] = 0;
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	pu(idx);
}

void upd(int p, int v, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].mn[1] = seg[idx].mx[1] = v;
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(p <= mid){
		upd(p, v, 2*idx);
	}
	else{
		upd(p, v, 2*idx+1);
	}
	pu(idx);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> Q;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		build(1, N, 1);
		cout << seg[1].mx[1] << "\n";
		while(Q--){
			int l, r;
			cin >> l >> r;
			swap(arr[l], arr[r]);
			upd(l, arr[l], 1);
			upd(r, arr[r], 1);
			cout << seg[1].mx[1] << "\n";
		}
	}
}