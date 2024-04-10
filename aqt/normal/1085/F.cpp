
// Problem : F. Rock-Paper-Scissors Champion
// Contest : Codeforces - Technocup 2019 - Elimination Round 4
// URL : https://codeforces.com/contest/1085/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r;
	int cnt[3];
};

int N, M;
string s;
int arr[200005];
set<int> st[3];
Node seg[1000000];

void pu(int idx){
	for(int k = 0; k<3; k++){
		seg[idx].cnt[k] = seg[2*idx].cnt[k] + seg[2*idx+1].cnt[k];
	}
}

void build(int l, int r, int idx){
	seg[idx].l = l;
	seg[idx].r = r;
	if(l == r){
		seg[idx].cnt[arr[l]]++;
		return;
	}
	int mid = (l+r)/2;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	pu(idx);
}

void upd(int p, int t, int v, int idx){
	if(seg[idx].l == seg[idx].r){
		seg[idx].cnt[t] += v;
		return;
	}
	int mid = (seg[idx].l + seg[idx].r)/2;
	if(p <= mid){
		upd(p, t, v, 2*idx);
	}
	else{
		upd(p, t, v, 2*idx+1);
	}
	pu(idx);
}

int query(int l, int r, int t, int idx){
	if(seg[idx].l == l && seg[idx].r == r){
		return seg[idx].cnt[t];
	}
	int mid = (seg[idx].l + seg[idx].r)/2;
	if(r <= mid){
		return query(l, r, t, 2*idx);
	}
	else if(l > mid){
		return query(l, r, t, 2*idx+1);
	}
	else{
		return query(l, mid, t, 2*idx) + query(mid+1, r, t, 2*idx+1);
	}
}

int solve(){
	int ret = N;
	for(int k = 0; k<3; k++){
		if(st[(k+1)%3].size() && st[(k+2)%3].empty()){
			ret -= query(1, N, k, 1);
		}
		else{
			int ll = st[(k+1)%3].size() ? (*st[(k+1)%3].begin()) : N+2;
			int lw = st[(k+2)%3].size() ? (*st[(k+2)%3].begin()) : N+1;
			if(ll < lw){
				ret -= query(ll, lw-1, k, 1);
			}
			int rl = st[(k+1)%3].size() ? (*st[(k+1)%3].rbegin()) : -2;
			int rw = st[(k+2)%3].size() ? (*st[(k+2)%3].rbegin()) : -1;
			if(rl > rw){
				ret -= query(rw+1, rl, k, 1);
			}
		}
	}
	return ret;
}

int typ(char c){
	if(c == 'R'){
		return 0;
	}
	else if(c == 'P'){
		return 1;
	}
	else{
		return 2;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> s;
	for(int i = 1; i<=N; i++){
		arr[i] = typ(s[i-1]);
		st[arr[i]].insert(i);
	}
	build(1, N, 1);
	cout << solve() << "\n";
	while(M--){
		int n;
		char c;
		cin >> n >> c;
		upd(n, arr[n], -1, 1);
		st[arr[n]].erase(n);
		arr[n] = typ(c);
		upd(n, arr[n], 1, 1);
		st[arr[n]].insert(n);
		cout << solve() << "\n";
	}
}