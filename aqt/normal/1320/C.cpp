
// Problem : C. World of Darkraft: Battle for Azathoth
// Contest : Codeforces Round #625 (Div. 1, based on Technocup 2020 Final Round)
// URL : https://codeforces.com/contest/1320/problem/C
// Memory Limit : 512.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

struct node{
	int l, r;
	long long v, lzy;
};

int N, M, K;
node seg[4000005];
pair<int, int> arr[200005];
pair<int, int> brr[200005];
pair<pair<int, int>, int> krr[200005];
vector<pair<int, int>> a;
vector<pair<int, int>> b;

void pd(int idx){
	if(seg[idx].lzy){
		seg[2*idx].v += seg[idx].lzy;
		seg[2*idx].lzy += seg[idx].lzy;
		seg[2*idx+1].v += seg[idx].lzy;
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
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].v += v;
		seg[idx].lzy += v;
		return;
	}
	pd(idx);
	int mid = seg[idx].l+seg[idx].r>>1;
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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	for(int i = 1; i<=M; i++){
		cin >> brr[i].first >> brr[i].second;
	}
	sort(arr+1, arr+1+N);
	sort(brr+1, brr+1+M);
	for(int i = 1; i<=N; i++){
		while(a.size() && a.back().second >= arr[i].second){
			a.pop_back();
		}	
		a.push_back(arr[i]);
	}
	int ed = arr[N].first;
	build(1, ed, 1);
	int lst = 0;
	for(auto p : a){
		if(lst+1 <= p.first){
			upd(lst+1, p.first, -p.second, 1);
		}
		lst = p.first;
	}
	for(int i = 1; i<=K; i++){
		cin >> krr[i].first.second >> krr[i].first.first;
		krr[i].first.second++, krr[i].first.first++;
		cin >> krr[i].second;
	}
	sort(krr+1, krr+1+K);
	int idx = 1;
	long long ans = LLONG_MIN/2;
	for(int i = 1; i<=M; i++){
		int c = brr[i].first;
		while(idx<= K && krr[idx].first.first <= c){
			if(krr[idx].first.second <= ed){
				upd(krr[idx].first.second, ed, krr[idx].second, 1);
			}
			idx++;
		}
		ans = max(ans, seg[1].v - brr[i].second);
	}
	cout << ans << "\n";
}