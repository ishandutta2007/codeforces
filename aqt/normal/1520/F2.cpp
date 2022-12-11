
// Problem : F2. Guess the K-th Zero (Hard version)
// Contest : Codeforces - Codeforces Round #719 (Div. 3)
// URL : https://codeforces.com/contest/1520/problem/F2
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> seg;

int query(int l, int r){
	if(seg.count(make_pair(l, r))){
		return seg[make_pair(l, r)];
	}
	cout << "? " << l << " " << r << endl;
	int n;
	cin >> n;
	return seg[make_pair(l, r)] = n;
}

void solve(int l, int r, int k){
	if(l == r){
		cout << "! " << l << endl;
		return;
	}
	int mid = (l + r)/2;
	if(mid - l + 1 - query(l, mid) >= k){
		solve(l, mid, k);
		seg[make_pair(l, mid)]++;
	}
	else{
		solve(mid+1, r, k - (mid - l + 1 - seg[make_pair(l, mid)]));
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, Q;
	cin >> N >> Q;
	while(Q--){
		int k;
		cin >> k;
		solve(1, N, k);
	}
}