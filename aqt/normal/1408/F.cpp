
// Problem : F. Two Different
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> ans;

void pairing(int l, int r){
	for(int i = l; i<=(l+r)/2; i++){
		ans.emplace_back(i, r-i+l);
	}
}

void solve(int l, int r){
	if(r-l+1 == 1){
		return;
	}
	int mid = l+r>>1;
	solve(l, mid);
	solve(mid+1, r);
	pairing(l, r);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int p = 31 - __builtin_clz(N);
	solve(1, (1<<p));
	solve(N - (1<<p) + 1, N);
	assert(ans.size() <= 500000);
	cout <<ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
}