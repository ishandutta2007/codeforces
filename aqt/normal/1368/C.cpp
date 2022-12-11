
// Problem : C. Even Picture
// Contest : Codeforces - Codeforces Global Round 8
// URL : https://codeforces.com/contest/1368/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int K;
	cin >> K;
	for(int k = 0; k<=K+1; k++){
		ans.emplace_back(k, k);
	}
	for(int k = 0; k<=K; k++){
		ans.emplace_back(k, k+1);
		ans.emplace_back(k+1, k);
	}
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
}