
// Problem : A. Colour the Flag
// Contest : Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1534/problem/A
// Memory Limit : 256 MB
// Time Limit : 1500 ms
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
		int N, M;
		cin >> N >> M;
		int red = -1, white = -1;
		bool good = 1;
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				char c;
				cin >> c;
				if(c == 'R'){
					if(red == -1){
						red = (i + j)%2;
						white = red ^ 1;
					}
					else if(red != (i + j) % 2){
						good = 0;
					}
				}
				else if(c == 'W'){
					if(white == -1){
						white = (i +j )%2;
						red = white ^ 1;
					}
					else if(white != (i + j) % 2){
						good = 0;
					}
				}
			}
		}
		if(good){
			cout << "YES\n";
			if(red == -1){
				red = 0;
				white = 1;
			}
			for(int i = 1; i <= N; i++){
				for(int j = 1; j <= M; j++){
					if(red == (i + j)%2){
						cout << 'R';
					}
					else{
						cout << 'W';
					}
				}
				cout << "\n";
			}
		}
		else{
			cout << "NO\n";
		}
	}
}