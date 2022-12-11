
// Problem : E. Non-Decreasing Dilemma
// Contest : Codeforces - Codeforces Round #742 (Div. 2)
// URL : https://codeforces.com/contest/1567/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	long long lft, rht;
	long long cnt;
};

int N, Q;
Node seg[200005 * 4];
int arr[200005];
int dif[200005];

Node f(Node lft, Node rht){
	Node n;
	n.l = lft.l;
	n.r = rht.r;
	n.cnt = lft.rht * rht.lft + lft.cnt + rht.cnt;
	if(lft.lft == lft.r - lft.l + 1){
		n.lft = lft.lft + rht.lft;
	}
	else{
		n.lft = lft.lft;
	}
	if(rht.rht == rht.r - rht.l + 1){
		n.rht = rht.rht + lft.rht;
	}
	else{
		n.rht = rht.rht;
	}
	return n;
}

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(seg[idx].l == seg[idx].r){
		seg[idx].cnt = seg[idx].lft = seg[idx].rht = (dif[l] >= 0);
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, 2 * idx);
	build(mid+1, r, 2 * idx + 1);
	seg[idx] = f(seg[2*idx], seg[2*idx+1]);
}

void upd(int p, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].lft = seg[idx].rht = seg[idx].cnt = (dif[p] >= 0);
		return;
	}
	int mid = (seg[idx].l + seg[idx].r) / 2;
	if(p <= mid){
		upd(p, 2 * idx);
	}
	else if(p > mid){
		upd(p, 2 * idx + 1);
	}
	seg[idx] = f(seg[2*idx], seg[2*idx+1]);
}

Node query(int l, int r, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx];
	}
	int mid = (seg[idx].l + seg[idx].r) / 2;
	if(r <= mid){
		return query(l, r, 2 * idx);
	}
	else if(l > mid){
		return query(l, r, 2 * idx + 1);
	}
	else{
		return f(query(l, mid, 2 * idx), query(mid+1, r, 2 * idx + 1));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	if(N == 1){
		cin >> arr[1];
		while(Q--){
			int t, x, y;
			cin >> t >> x >> y;
			if(t == 1){
				
			}
			else{
				cout << 1 << "\n";
			}
		}
		return 0;
	}
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i < N; i++){
		dif[i] = arr[i+1] - arr[i];
	}
	build(1, N - 1, 1);
	while(Q--){
		int t;
		cin >> t;
		if(t == 1){
			int x, y;
			cin >> x >> y;
			arr[x] = y;
			dif[x-1] = arr[x] - arr[x-1];
			dif[x] = arr[x+1] - arr[x];
			if(x - 1 >= 1){
				upd(x-1, 1);
			}
			if(x < N){
				upd(x, 1);
			}
		}
		else{
			int l, r;
			cin >> l >> r;
			if(l == r){
				cout << 1 << "\n";
			}
			else{
				Node n = query(l, r-1, 1);
				cout << n.cnt + r - l + 1<< "\n";
			}
		}
	}
}