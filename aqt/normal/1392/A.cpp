
// Problem : A. Omkar and Password
// Contest : Codeforces - Codeforces Global Round 10
// URL : https://codeforces.com/contest/1392/problem/A
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
		set<int> st;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			st.insert(n);
		}
		if(st.size() == 1){
			cout << N << "\n";
		}
		else{
			cout << 1 << "\n";
		}
	}
}