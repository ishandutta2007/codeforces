
// Problem : D. Ceil Divisions
// Contest : Codeforces - Educational Codeforces Round 101 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1469/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
		int N;
		cin >> N;
		vector<pair<int, int>> ans;
		for(int i = N; i > 2; ){
			for(long long j = i; j; j--){
				if(j * j < i){
					for(int k = i - 1; k > j + 1; k--){
						ans.emplace_back(k, i);
					}
					ans.emplace_back(i, j + 1);
					ans.emplace_back(i, j + 1);
					i = j + 1;
				}
			}
		}
		cout << ans.size() << "\n";
		for(auto p : ans){
			cout << p.first << " " << p.second << "\n";
		}
	}
}