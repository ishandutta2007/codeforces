
// Problem : B. Shuffle
// Contest : Codeforces - Educational Codeforces Round 89 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1366/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, M, X;
		cin >> N >> X >> M;
		int l = X, r = X;
		while(M--){
			int a, b;
			cin >> a >> b;
			if(a<=l && b>=l){
				l = min(a, l);
			}
			if(a<=r && b>=r){
				r = max(r, b);
			}
		}
		//cout << l << " " << r << "\n";
		cout << r-l+1 << "\n";
	}
}