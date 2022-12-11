
// Problem : B. Belted Rooms
// Contest : Codeforces - Codeforces Raif Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1428/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		string s;
		cin >> s;
		bool hasA = 0, hasB = 0;
		int ans = 0;
		for(int i = 0; i<N; i++){
			if(s[i] == '-' || s[(i+N-1)%N] == '-'){
				ans++;
			}
			if(s[i] == '>'){
				hasA = 1;
			}
			if(s[i] == '<'){
				hasB = 1;
			}
		}
		if(!hasA || !hasB){
			cout << N << "\n";
		}
		else{
			cout << ans << "\n";
		}
	}	
}