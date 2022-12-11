
// Problem : B. Phoenix and Beauty
// Contest : Codeforces - Codeforces Round #638 (Div. 2)
// URL : https://codeforces.com/contest/1348/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		vector<int> v;
		set<int> st;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			v.push_back(n);
			st.insert(n);
		}
		if(st.size() > K){
			cout << -1 << "\n";
			continue;
		}
		vector<int> seq;
		for(int n : st){
			seq.push_back(n);
		}
		while(seq.size() < K){
			seq.push_back(*st.begin());
		}
		vector<int> ans;
		int idx1 = 0, idx2 = 0;
		while(idx2 < N){
			if(v[idx2] == seq[idx1]){
				ans.push_back(v[idx2]);
				idx2++;
				idx1++;
				idx1 %= K;
			}
			else{
				ans.push_back(seq[idx1]);
				idx1++;
				idx1%=K;
			}
		}
		if(ans.empty()){
			cout << -1 << "\n";
			continue;
		}
		else{
			cout << ans.size() << "\n";
			for(int n : ans){
				cout << n << " ";
			}
			cout << "\n";			
		}
	}
}