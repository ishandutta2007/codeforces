
// Problem : B. Integers Have Friends
// Contest : Codeforces - Codeforces Round #736 (Div. 1)
// URL : https://codeforces.com/contest/1548/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long g;
};

int T;
int N;
long long arr[200005];
long long dif[200005];
Node seg[4 * 200005];

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		seg[idx].g = dif[l];
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2 * idx);
	build(mid + 1, r, 2 * idx + 1);
	seg[idx].g = __gcd(seg[2*idx].g, seg[2*idx+1].g);
}

long long query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].g;
	}
	int mid = (seg[idx].l + seg[idx].r) / 2;
	if(r <= mid){
		return query(l, r, 2 * idx);
	}
	else if(l > mid){
		return query(l, r, 2 * idx + 1);
	}
	else{
		return __gcd(query(l, mid, 2 * idx), query(mid+1, r, 2 * idx + 1));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i <= N; i++){
			cin >> arr[i];
		}
		for(int i = 1; i < N; i++){
			dif[i] = abs(arr[i] - arr[i+1]);
		}
		if(N == 1){
			cout << 1 << "\n";
			continue;
		}
		build(1, N-1, 1);
		int bst = 1;
		for(int l = 1, r = 1; r < N; r++){
			while(l <= r && query(l, r, 1) == 1){
				l++;
			}
			bst = max(bst, r-l+2);
		}
		cout << bst << "\n";
	}
}