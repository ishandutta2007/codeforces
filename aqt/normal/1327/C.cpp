
// Problem : C. Game with Chips
// Contest : Educational Codeforces Round 84 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1327/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	string ans;
	for(int i = 1; i<N; i++){
		ans.push_back('D');
	}
	for(int i = 1; i<M; i++){
		ans.push_back('R');
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<M; j++){
			if(i%2 == 1){
				ans.push_back('L');
			}
			else{
				ans.push_back('R');
			}
		}
		if(i != N){
			ans.push_back('U');
		}
	}
	cout << ans.size() << "\n";
	cout << ans << "\n";
}