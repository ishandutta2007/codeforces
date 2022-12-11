
// Problem : G. Special Permutation
// Contest : Codeforces - Codeforces Round #640 (Div. 4)
// URL : https://codeforces.com/contest/1352/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

bool chk(vector<int> v){
	for(int i = 1; i<v.size(); i++){
		if(abs(v[i]-v[i-1]) > 4 || abs(v[i]-v[i-1]) < 2){
			return 0;
		}
	}
	return 1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		if(N < 4){
			cout << -1 << "\n";
			continue;
		}
		vector<int> ans(N);
		for(int i = 0; i<(N-4); i+=4){
			ans[i] = i+1;
			ans[i+1] = i+3;
			ans[i+2] = i;
			ans[i+3] = i+2;
		}
		for(int i = (N-4)/4*4; i<N; i++){
			ans[i] = i;
		}
		do{
			if(chk(ans)){
				break;
			}
		}
		while(next_permutation(ans.begin()+(N-4)/4*4, ans.end()));
		for(int n : ans){
			cout << n+1 << " ";
		}
		cout << "\n";
	}
}