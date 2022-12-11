
// Problem : E. Complicated Computations
// Contest : Codeforces - Codeforces Round #678 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1436/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r, mn;
};

int N;
vector<int> pos[100005];
Node seg[400005];

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		seg[idx].mn = l;
		return;
	}
	int mid = l + r >> 1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
}

void upd(int p, int v, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].mn = min(seg[idx].mn, v);
		return;
	}
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(p <= mid){
		upd(p, v, 2*idx);
	}
	else{
		upd(p, v, 2*idx+1);
	}
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
}

int query(int l, int r, int idx){
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	bool all1 = 1;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		pos[n].push_back(i);
		all1 &= (n == 1);
	}
	if(all1){
		cout << 1 << "\n";
		return 0;
	}
	build(1, N+1, 1);
	for(int ans = 1; ans<=N+2; ans++){
		bool good = 0;
		int prev = 0;
		for(int n : pos[ans]){
			if(query(n+1, N+1, 1) > prev){
				good = 1;
			}
			prev = n;
		}
		if(query(N+1, N+1, 1) > prev){
			good = 1;
		}
		if(!good){
			cout << ans << "\n";
			return 0;
		}
		prev = 0;
		for(int n : pos[ans]){
			upd(n, prev, 1);
			prev = n;
		}
		upd(N+1, prev, 1);
	}
}