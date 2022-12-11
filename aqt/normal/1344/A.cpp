
// Problem : A. Hilbert's Hotel
// Contest : Codeforces - Codeforces Round #639 (Div. 1)
// URL : https://codeforces.com/contest/1344/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
		int N;
		cin >> N;
		set<int> st;
		for(int i = 0; i<N; i++){
			int n;
			cin >> n;
			st.insert(((n+i)%N+N)%N);
		}
		cout << (st.size() == N ? "YES\n" : "NO\n");
	}
}