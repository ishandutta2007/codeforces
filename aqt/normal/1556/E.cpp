
// Problem : E. Equilibrium
// Contest : Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1556/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long mn, mx;
};

int N, Q;
long long arr[100005];
long long pre[100005];
Node seg[4 * 100005];

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		seg[idx].mn = seg[idx].mx = pre[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2 * idx);
	build(mid+1, r, 2 * idx + 1);
	seg[idx].mn = min(seg[2*idx].mn, seg[2*idx+1].mn);
	seg[idx].mx = max(seg[2*idx].mx, seg[2*idx+1].mx);
}

long long getmn(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].mn;
	}
	int mid = (seg[idx].l + seg[idx].r) / 2;
	if(r <= mid){
		return getmn(l, r, 2 * idx);
	}
	else if(l > mid){
		return getmn(l, r, 2 * idx + 1);
	}
	else{
		return min(getmn(l, mid, 2 * idx), getmn(mid+1, r, 2 * idx+1));
	}
}

long long getmx(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].mx;
	}
	int mid = (seg[idx].l + seg[idx].r) / 2;
	if(r <= mid){
		return getmx(l, r, 2 * idx);
	}
	else if(l > mid){
		return getmx(l, r, 2 * idx + 1);
	}
	else{
		return max(getmx(l, mid, 2 * idx), getmx(mid+1, r, 2 * idx+1));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= N; i++){
		long long n;
		cin >> n;
		arr[i] = n - arr[i];
		pre[i] = pre[i-1] + arr[i];
	}
	/*
	for(int i = 1; i <= N; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
	for(int i = 1; i <= N; i++){
		cout << pre[i] << " ";
	}
	*/
	build(0, N, 1);
	while(Q--){
		int l, r;
		cin >> l >> r;
		if(pre[r] != pre[l-1]){
			cout << -1 << "\n";
			continue;
		}
		//cout << getmn(l, r, 1) << " " << pre[l-1] << "\n";
		if(getmn(l, r, 1) < pre[l-1]){
			cout << -1 << "\n";
			continue;
		}
		cout << getmx(l, r, 1) - pre[l-1] << "\n";
	}
}