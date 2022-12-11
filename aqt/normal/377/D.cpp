
// Problem : D. Developing Game
// Contest : Codeforces Round #222 (Div. 1)
// URL : https://codeforces.com/contest/377/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r, mx, idx, lzy;
};

int N;
const int M = 300000;
int lft[300005], rht[300005], val[300005];
node seg[1500000];
vector<int> add[300005];
vector<int> rem[300005];

void build(int l, int r, int idx){
	seg[idx].l = l, seg[idx].r = r;
	seg[idx].idx = r;
	if(l == r){
		return;
	}
	int mid = l+r >> 1;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
}

void upd(int l, int r, int v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].mx += v;
		seg[idx].lzy += v;
		return;
	}
	if(seg[idx].lzy){
		seg[2*idx].mx += seg[idx].lzy;
		seg[2*idx+1].mx += seg[idx].lzy;
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].lzy += seg[idx].lzy;
		seg[idx].lzy = 0;
	}
	int mid = seg[idx].l + seg[idx].r>>1;
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
	if(seg[2*idx].mx > seg[2*idx+1].mx){
		seg[idx].idx = seg[2*idx].idx;
		seg[idx].mx = seg[2*idx].mx;
	}
	else{
		seg[idx].idx = seg[2*idx+1].idx;
		seg[idx].mx = seg[2*idx+1].mx;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i =1 ; i<=N; i++){
		cin >> lft[i] >> val[i] >> rht[i];
		add[lft[i]].push_back(i);
		rem[val[i]].push_back(i);
	}
	build(1, M, 1);
	int ans = -1, ansmn = 0, ansmx = 0;
	for(int i = 1; i<=M; i++){
		for(int n : add[i]){
			upd(val[n], rht[n], 1, 1);
		}
		if(seg[1].mx > ans){
			ans = seg[1].mx;
			ansmn = i;
			ansmx = seg[1].idx;
		}
		for(int n : rem[i]){
			upd(val[n], rht[n], -1, 1);
		}
	}
	cout << ans << "\n";
	for(int i = 1; i<=N; i++){
		if(val[i] <= ansmx && val[i] >= ansmn && lft[i] <= ansmn && rht[i] >= ansmx){
			cout << i << " ";
		}
	}
}