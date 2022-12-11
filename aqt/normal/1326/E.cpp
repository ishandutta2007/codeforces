#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r, v, lzy;
};

int N;
node seg[1500000];
int arr[300005];
int pos[300005];

void pd(int idx){
	if(seg[idx].lzy){
		//cout << "lzy: " << seg[idx].l << " " << seg[idx].r << "\n";
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
	//cout << l << " " << r << " " << v << " " << idx << endl;
	//cout << seg[idx].l << " " << seg[idx].r << "\n";
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].v += v;
		seg[idx].lzy += v;
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

int query(int p, int idx){
	if(seg[idx].l == seg[idx].r){
		return seg[idx].v;
	}
	pd(idx);
	if(seg[idx].l+seg[idx].r>>1 >= p){
		return query(p, 2*idx);
	}
	else{
		return query(p, 2*idx+1);
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i =1 ; i<=N; i++){
		cin >> arr[i];
		pos[arr[i]] = i;
	}
	build(1, N, 1);
	int k = N;
	upd(1, pos[N], 1, 1);
	for(int q = 1; q<=N; q++){
		//cout << query(pos[k], 1) << "\n";
		while(seg[1].v <= 0){
			k--;
			//cout << " " << k << " " << seg[q].v << endl;
			upd(1, pos[k], 1, 1);
		}
		cout << k << " ";
		int r;
		cin >> r;
		upd(1, r, -1, 1);
	}
}