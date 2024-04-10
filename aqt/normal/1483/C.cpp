
// Problem : C. Skyline Photo
// Contest : Codeforces - Codeforces Round #709 (Div. 1, based on Technocup 2021 Final Round)
// URL : https://codeforces.com/contest/1483/problem/C
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long mx, mxdp;
	long long lzy;
};

int N;
int h[300005];
int b[300005];
Node seg[4 * 300005];
long long dp[300005];
const long long oo = LLONG_MAX / 2;

void build(int l, int r, int idx){
	seg[idx].lzy = oo;
	seg[idx].l = l;
	seg[idx].r = r;
	seg[idx].mx = -oo;
	seg[idx].mxdp = -oo;
	if(l == r){
		return;
	}
	int mid = l + r >> 1;
	build(l, mid , 2 * idx);
	build(mid + 1, r, 2 * idx + 1);
}

void pd(int idx){
	if(seg[idx].lzy != oo){
		seg[2 * idx].mx = seg[idx].lzy + seg[2 * idx].mxdp;
		seg[2 * idx + 1].mx = seg[idx].lzy + seg[2 * idx + 1].mxdp;
		seg[2 * idx].lzy = seg[2 * idx + 1].lzy = seg[idx].lzy;
		seg[idx].lzy = oo;
	}	
}

void pu(int idx){
	seg[idx].mx = max(seg[2 * idx].mx, seg[2 * idx + 1].mx);
	seg[idx].mxdp = max(seg[2 * idx].mxdp, seg[2 * idx + 1].mxdp);
}

void upds(int p, long long v, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].mxdp = v;
		seg[idx].mx = v + seg[idx].lzy;
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(p <= mid){
		upds(p, v, 2 * idx);
	}
	else{
		upds(p, v, 2 * idx + 1);
	}
	pu(idx);
}

void updr(int l, int r, long long v, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].lzy = v;
		seg[idx].mx = seg[idx].mxdp + v;
		return;
	}
	pd(idx);
	int mid = seg[idx].l + seg[idx].r >> 1;
	if(r <= mid){
		updr(l, r, v, 2 * idx);
	}
	else if(l > mid){
		updr(l, r, v, 2 * idx + 1);
	}
	else{
		updr(l, mid, v, 2 * idx);
		updr(mid + 1, r, v, 2 * idx + 1);
	}
	pu(idx);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> h[i];
	}
	for(int i = 1; i <= N; i++){
		cin >> b[i];
	}
	build(0, N, 1);
	vector<pair<int, int>> stk = {make_pair(0, 0)};
	upds(0, 0, 1);
	for(int i = 1; i <= N; i++){
		pair<int, int> p = make_pair(i, h[i]);
		while(stk.size() && stk.back().second > p.second){
			stk.pop_back();
		}
		//cout << i << " " << stk.back().second << endl;
		updr(stk.back().first, i - 1, b[i], 1);
		dp[i] = seg[1].mx;
		stk.push_back(p);
		upds(i, dp[i], 1);
	}
	cout << dp[N];
}