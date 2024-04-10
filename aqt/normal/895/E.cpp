
// Problem : E. Eyes Closed
// Contest : Codeforces - Codeforces Round #448 (Div. 2)
// URL : https://codeforces.com/problemset/problem/895/E
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	long double val;
	long double lzyp, lzys;
};

int N, Q;
int arr[100005];
node seg[400005];

void pd(int idx){
	for(int nxt = 2*idx; nxt<=2*idx+1; nxt++){
		seg[nxt].val *= seg[idx].lzyp;
		seg[nxt].val += seg[idx].lzys * (seg[nxt].r - seg[nxt].l + 1);
		seg[nxt].lzyp *= seg[idx].lzyp;
		seg[nxt].lzys *= seg[idx].lzyp;
		seg[nxt].lzys += seg[idx].lzys;
	}
	seg[idx].lzyp = 1, seg[idx].lzys = 0;
}

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	seg[idx].lzyp = 1;
	if(l == r){
		seg[idx].val = arr[l];
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	seg[idx].val = seg[2*idx].val + seg[2*idx+1].val;
}

void upd(int l, int r, long double a, long double m, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].val *= m;
		seg[idx].val += a * (seg[idx].r - seg[idx].l + 1);
		seg[idx].lzys *= m;
		seg[idx].lzyp *= m;
		seg[idx].lzys += a;
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		upd(l, r, a, m, 2*idx);
	}
	else if(l > mid){
		upd(l, r, a, m, 2*idx+1);
	}
	else{
		upd(l, mid, a, m, 2*idx);
		upd(mid+1, r, a, m, 2*idx+1);
	}
	seg[idx].val = seg[2*idx].val + seg[2*idx+1].val;
}

long double query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].val;
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(9);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	build(1, N, 1);
	while(Q--){
		int c;
		cin >> c;
		if(c == 1){
			int l1, r1, l2, r2;
			cin >> l1 >> r1 >> l2 >> r2;
			long double v1 = query(l1, r1, 1), v2 = query(l2, r2, 1);
			long double k1 = 1.0*(r1-l1)/(r1-l1+1), k2 = 1.0*(r2-l2)/(r2-l2+1);
			//cout << v2 << " " << v1 << "\n";
			upd(l1, r1, (1-k1)*v2/(r2-l2+1), k1, 1);
			upd(l2, r2, (1-k2)*v1/(r1-l1+1), k2, 1);
			//cout << "qu: " << query(1, 1, 1) << "\n";
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << query(l, r, 1) << "\n";
		}
	}
}