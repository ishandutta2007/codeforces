#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
const int MAXN = 100010;

struct node{
	long long mx, mxid, sum;
} seg[4*MAXN];

node combine(node x, node y){
	if (x.mx<y.mx) return {y.mx, y.mxid, x.sum+y.sum};
	return {x.mx, x.mxid, x.sum+y.sum};
}

int n, m, k, u, v, x, y, t, a, b, type, l, r;
int A[MAXN];

void build(int id, int tl, int tr){
	if (tl==tr){
		seg[id]={A[tl], tl, A[tl]};
		return ;
	}
	int mid=(tl+tr)>>1;
	build(id<<1, tl, mid);
	build(id<<1 | 1, mid+1, tr);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

void update(int id, int tl, int tr, int ind, int val){
	if (tl==tr){
		seg[id]={val, tl, val};
		return ;
	}
	int mid=(tl+tr)>>1;
	if (ind<=mid) update(id<<1, tl, mid, ind, val);
	else update(id<<1 | 1, mid+1, tr, ind, val);
	seg[id]=combine(seg[id<<1], seg[id<<1 | 1]);
}

node get(int id, int tl, int tr, int l, int r){
	if (tr<l || r<tl) return {0, 0, 0};
	if (l<=tl && tr<=r) return seg[id];
	int mid=(tl+tr)>>1;
	return combine(get(id<<1, tl, mid, l, r), get(id<<1 | 1, mid+1, tr, l, r));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	build(1, 1, n);
	
	while (m--){
		cin>>type;
		if (type==1){
			cin>>l>>r;
			cout<<get(1, 1, n, l, r).sum<<'\n';
			continue ;
		}
		if (type==2){
			cin>>l>>r>>x;
			while (1){
				node tmp=get(1, 1, n, l, r);
				if (tmp.mx<x) break ;
				update(1, 1, n, tmp.mxid, tmp.mx%x);
			}
			continue ;
		}
		cin>>k>>x;
		update(1, 1, n, k, x);
	}
	
	return 0;
}