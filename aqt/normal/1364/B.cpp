
// Problem : B. Most socially-distanced subsequence
// Contest : Codeforces - Codeforces Round #649 (Div. 2)
// URL : https://codeforces.com/contest/1364/problem/B
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
		int N;
		cin >> N;
		vector<int> v, ans;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			v.push_back(n);
		}
		ans.push_back(v[0]);
		for(int i = 1; i+1<N; i++){
			if((v[i] < v[i+1] && v[i] < v[i-1])){
				ans.push_back(v[i]);
			}
			else if(v[i] > v[i+1] && v[i] > v[i-1]){
				ans.push_back(v[i]);
			}
		}
		ans.push_back(v.back());
		cout << ans.size() << "\n";
		for(int n : ans){
			cout << n << " ";
		}
		cout << "\n";
	}
}