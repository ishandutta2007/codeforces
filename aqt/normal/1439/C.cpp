
// Problem : C. Greedy Shopping
// Contest : Codeforces - Codeforces Round #684 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1439/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long mn;
	long long sum;
	long long lzy;
};

int N, Q;
Node seg[1000000];
long long arr[200005];

void pu(int idx){
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
	seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
}

void pd(int idx){
	if(seg[idx].lzy){
		seg[2*idx].lzy = seg[idx].lzy;
		seg[2*idx].sum = (seg[2*idx].r - seg[2*idx].l + 1) * seg[idx].lzy;
		seg[2*idx+1].lzy = seg[idx].lzy;
		seg[2*idx+1].sum = (seg[2*idx+1].r - seg[2*idx+1].l + 1) * seg[idx].lzy;
		seg[2*idx].mn = seg[2*idx+1].mn = seg[idx].lzy;
		seg[idx].lzy = 0;
	}
}

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		seg[idx].mn = seg[idx].sum = arr[l];
		return;
	}
	int mid = (l+r)/2;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	pu(idx);
}

void upd(int l, int r, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].mn = v;
		seg[idx].sum = (seg[idx].r - seg[idx].l + 1) * v;
		seg[idx].lzy = v;
		return;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r)/2;
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
	pu(idx);
}

int walk(long long v, int lim, int idx){
	if(seg[idx].mn > v){
		return N+1;
	}
	if(seg[idx].l == seg[idx].r){
		return seg[idx].l;
	}
	pd(idx);
	if(seg[2*idx].r >= lim && seg[2*idx].mn <= v){
		return walk(v, lim, 2*idx);
	}
	else{
		return walk(v, lim, 2*idx+1);
	}
}

pair<long long, int> minsum(long long v, int lim, int idx){
	if(seg[idx].l == lim && seg[idx].sum <= v){
		return make_pair(seg[idx].sum, seg[idx].r - seg[idx].l + 1);
	}
	pd(idx);
	if(seg[2*idx].r >= lim){
		return minsum(v, lim, 2*idx);
	}
	else{
		return minsum(v, lim, 2*idx+1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i =1 ; i<=N; i++){
		cin >> arr[i];
	}
	build(1, N, 1);
	while(Q--){
		int cmd;
		cin >> cmd;
		if(cmd == 1){
			int idx;
			long long v;
			cin >> idx >> v;
			int lft = walk(v, 0, 1);
			if(lft <= idx){
				upd(lft, idx, v, 1);
			}
		}
		else{
			int idx;
			long long v;
			cin >> idx >> v;
			int ans = 0;
			while(idx != N + 1){
				int nxt = walk(v, idx, 1);
				if(nxt == N+1){
					break;
				}
				auto p = minsum(v, nxt, 1);
				v -= p.first;
				ans += p.second;
				idx = nxt+p.second;
			}
			cout << ans << "\n";
		}
	}
}