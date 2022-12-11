
// Problem : E. Partition Game
// Contest : Codeforces - Codeforces Round #721 (Div. 2)
// URL : https://codeforces.com/contest/1527/problem/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long mx;
	long long lzy;
};

int N, K;
int arr[35005];
int lst[35005];
int pre[35005];
long long dp[105][35005];
Node seg[350005 * 4];

void build(int l, int r, int k, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	seg[idx].lzy = 0;
	if(l == r){
		seg[idx].mx = dp[k][l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, k, 2 * idx);
	build(mid + 1, r, k, 2 * idx + 1);
	seg[idx].mx = max(seg[2 * idx].mx, seg[2 * idx + 1].mx);
}

void pd(int idx){
	//if(seg[idx].lzy){
		seg[2 * idx].mx += seg[idx].lzy;
		seg[2 * idx].lzy += seg[idx].lzy;
		seg[2 * idx + 1].mx += seg[idx].lzy;
		seg[2 * idx + 1].lzy += seg[idx].lzy;
		seg[idx].lzy = 0;
	//}
}

void upd(int l, int r, long long v, long long idx){
	if(seg[idx].l == l && seg[idx].r == r){
		seg[idx].mx += v;
		seg[idx].lzy += v;
		return;
	}
	pd(idx);
	int mid = (seg[idx].l + seg[idx].r) / 2;
	if(r <= mid){
		upd(l, r, v, 2 * idx);
	}
	else if(l > mid){
		upd(l, r, v, 2 * idx + 1);
	}
	else{
		upd(l, mid, v, 2 * idx);
		upd(mid + 1, r, v, 2 * idx + 1);
	}
	seg[idx].mx = max(seg[2 * idx].mx, seg[2 * idx + 1].mx);
}

long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].mx;
	}
	int mid = (seg[idx].l + seg[idx].r) / 2;
	if(r <= mid){
		return query(l, r, 2 * idx);
	}
	else if(l > mid){
		return query(l, r, 2 * idx + 1);
	}
	else{
		return max(query(l, mid, 2 * idx), query(mid + 1, r, 2 * idx + 1));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	long long tot = 0;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		pre[i] = lst[arr[i]];
		if(pre[i]){
			tot += i - pre[i];
		}
		lst[arr[i]] = i;
	}	
	for(int k = 2; k <= K; k++){
		build(0, N, k - 1, 1);
		for(int n = 1; n <= N; n++){
			if(pre[n]){
				upd(pre[n], n - 1, n - pre[n], 1);
			}
			dp[k][n] = query(0, n - 1, 1);
		}
	}
	cout << tot - dp[K][N];
}