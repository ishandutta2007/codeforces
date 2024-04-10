
// Problem : B. Same Parity Summands
// Contest : Codeforces - Codeforces Round #640 (Div. 4)
// URL : https://codeforces.com/contest/1352/problem/B
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
		int N, K;
		cin >> N >> K;
		if(K > N){
			cout << "NO\n";
		}
		else if(K%2 == 0 && N%2 == 1){
			cout << "NO\n";
		}
		else if(K%2 == 1 && N%2 == 0 && 2*K > N){
			cout << "NO\n";
		}
		else if(K%2 == 1 && N%2 == 0){
			cout << "YES\n";
			K--;
			while(K--){
				cout << 2 << " ";
				N -= 2;
			}
			cout << N << "\n";
		}
		else{
			cout << "YES\n";
			K--;
			while(K--){
				cout << 1 << " ";
				N--;
			}
			cout << N << "\n";
		}
	}
}