
// Problem : C. Rings
// Contest : Codeforces - Codeforces Round #741 (Div. 2)
// URL : https://codeforces.com/contest/1562/problem/C
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
		string s;
		cin >> N >> s;
		bool found = 0;
		for(int i = 0; i < N / 2; i++){
			if(!found && s[i] == '0'){
				cout << (i+1) << " " << N << " " << (i+2) << " " << N << "\n";
				found = 1;
			}
		}
		for(int i = N / 2; i < N; i++){
			if(!found && s[i] == '0'){
				cout << 1 << " " << (i+1) << " " << 1 << " " << i << "\n";
				found = 1;
			}
		}
		if(!found){
			cout << 1 << " " << N / 2 * 2 << " " << 1 << " " << N / 2 << "\n";		
		}
	}
}