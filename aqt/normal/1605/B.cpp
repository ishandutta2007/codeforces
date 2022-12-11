
// Problem : B. Reverse Sort
// Contest : Codeforces - Codeforces Round #754 (Div. 2)
// URL : https://codeforces.com/contest/1605/problem/B
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
		string s;
		int N;
		cin >> N;
		cin >> s;
		int cnt0 = 0;
		for(char c : s){
			cnt0 += (c == '0');
		}
		vector<int> v;
		for(int i = 0; i < N; i++){
			if(i < cnt0){
				if(s[i] == '1'){
					v.push_back(i);
				}
			}
			else{
				if(s[i] == '0'){
					v.push_back(i);
				}
			}
		}
		if(v.empty()){
			cout << 0 << "\n";
		}
		else{
			cout << 1 << "\n";
			cout << v.size() << " ";
			for(int n : v){
				cout << n+1 << " ";
			}
			cout << "\n";
		}
	}
}