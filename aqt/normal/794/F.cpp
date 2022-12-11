#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	vector<long long> d;
	vector<long long> lzy;
};

int N, Q;
node seg[400005];
int arr[400005];

void pd(int idx){
	for(int nxt = 2*idx; nxt < 2*idx+2; nxt++){
		vector<long long> t(20, 0);
		for(int d = 0; d<10; d++){
			t[seg[idx].lzy[d]] += seg[nxt].d[d];	
		}
		seg[nxt].d = t;
		for(int d = 0; d<10; d++){
			t[d] = seg[idx].lzy[seg[nxt].lzy[d]];
		}
		seg[nxt].lzy = t;
	}
	for(int d = 0; d<10; d++){
		seg[idx].lzy[d] = d;
	}
}

void pu(int idx){
	for(int d = 0; d<10; d++){
		seg[idx].d[d] = seg[2*idx].d[d] + seg[2*idx+1].d[d];
	}
}

void build(int l, int r, int idx){
	seg[idx].l =l, seg[idx].r = r;
	seg[idx].d.resize(20);
	seg[idx].lzy.resize(20);
	for(int d = 0; d<10; d++){
		seg[idx].lzy[d] = d;
	}
	if(l == r){
		int n = arr[l], cnt = 0;
		while(n){
			seg[idx].d[n%10] += pow(10, cnt);
			cnt++;
			n /= 10;
		}
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	pu(idx);
}

void upd(int l, int r, int x, int y, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		for(int d = 0; d<10; d++){
			if(seg[idx].lzy[d] == x){
				seg[idx].lzy[d] = y;
			}
		}
		seg[idx].d[y] += seg[idx].d[x];
		seg[idx].d[x] = 0;
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		upd(l, r, x, y, 2*idx);
	}
	else if(l > mid){
		upd(l, r, x, y, 2*idx+1);
	}
	else{
		upd(l, mid, x, y, 2*idx);
		upd(mid+1, r, x, y, 2*idx+1);
	}
	pu(idx);
}

long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		long long ret = 0;
		for(int d = 0; d<10; d++){
			ret += seg[idx].d[d] * d;
		}
		return ret;
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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	build(1, N, 1);
	while(Q--){
		int c, l, r, x, y;
		cin >> c >> l >> r;
		if(c == 1){
			cin >> x >> y;
			if(x == y){
				continue;
			}
			upd(l, r, x, y, 1);
		}
		else{
			cout << query(l, r, 1) << "\n";
		}
	}
}