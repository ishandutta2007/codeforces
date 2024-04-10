
// Problem : F. Fruit Sequences
// Contest : Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1428/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	long long l, r, mx, sum, lzy;
};

int N;
string s;
Node seg[2000005];
vector<pair<int, int>> stk;

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		return;
	}
	int mid = l+r>>1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void pd(int idx){
	if(seg[idx].lzy){
		for(int i = 2*idx; i<=2*idx+1; i++){
			seg[i].sum = seg[idx].lzy * (seg[i].r - seg[i].l + 1);
			seg[i].mx = seg[idx].lzy;
			seg[i].lzy = seg[idx].lzy;
		}
		seg[idx].lzy = 0;
	}
}

void upd(int l, int r, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].sum = 1LL*v*(seg[idx].r - seg[idx].l+1);
		seg[idx].lzy = v;
		seg[idx].mx = v;
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
	seg[idx].sum = seg[2*idx].sum + seg[2*idx+1].sum;
	seg[idx].mx = min(seg[2*idx].mx, seg[2*idx+1].mx);
}

int walk(long long v, int idx){
	if(seg[idx].l == seg[idx].r){
		return seg[idx].l;
	}
	pd(idx);
	if(seg[2*idx].mx <= v){
		return walk(v, 2*idx);
	}
	else{
		return walk(v, 2*idx+1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	build(1, N, 1);
	long long ans = 0, lst = 0;
	for(int i = 1; i<=N; i++){
		char c;
		cin >> c;
		if(c == '1'){
			int ptr = walk(i - lst, 1);
			if(ptr <= lst){
				upd(ptr, lst, i - lst, 1);
			}
			ans += seg[1].sum + 1LL*(i - lst) * (i - lst +1)/2;
		}
		else{
			for(int j = lst+1; j<i; j++){
				upd(j, j, i - j, 1);
			}
			ans += seg[1].sum;
			lst = i;
		}
	}
	cout << ans;
}