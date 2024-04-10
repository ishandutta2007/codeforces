
// Problem : A. Little Artem
// Contest : Codeforces Round #632 (Div. 2)
// URL : https://codeforces.com/contest/1333/problem/0
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
		cout << 'W';
		int N, M;
		cin >> N >> M;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				if(i == 1 && j == 1){
					
				}
				else{
					cout << 'B';
				}
			}
			cout << "\n";
		}
	}
}