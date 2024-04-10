
// Problem : B. New Theatre Square
// Contest : Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1359/problem/B
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
		int N, M, A, B;
		cin >> N >> M >> A >> B;
		long long ans = 0;
		for(int i = 1; i<=N; i++){
			string s;
			cin >> s;
			s.push_back('*');
			for(int j = 0; j<M; j++){
				if(B < 2*A && s[j] == '.' && s[j+1] == '.'){
					j++;
					ans += B;
				}
				else if(s[j] == '.'){
					ans += A;
				}
			}
		}
		cout << ans << "\n";
	}
}