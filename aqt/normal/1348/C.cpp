
// Problem : C. Phoenix and Distribution
// Contest : Codeforces - Codeforces Round #638 (Div. 2)
// URL : https://codeforces.com/contest/1348/problem/C
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
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		vector<string> v (K, "");
		set<char> st;
		for(int i = K; i<N; i++){
			st.insert(s[i]);
		}
		set<char> stb;
		for(int i = 0; i<K; i++){
			v[i].push_back(s[i]);
			stb.insert(s[i]);
		}
		if(stb.size() == 1 && st.size() == 1){
			for(int i = K; i<N; i++){
				v[i%K].push_back(s[i]);
			}
			cout << v[0] << "\n";
		}
		else if(stb.size() != 1){
			for(int i = K; i<N; i++){
				v[0].push_back(s[i]);
			}
			cout << v[K-1] << "\n";
		}
		else{
			for(int i = K; i<N; i++){
				v[0].push_back(s[i]);
			}
			cout << v[0] << "\n";
		}
	}
}