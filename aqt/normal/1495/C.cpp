
// Problem : C. Garden of the Sun
// Contest : Codeforces - Codeforces Round #706 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1495/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
char mp[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				cin >> mp[i][j];
			}
		}
		if(N == 1){
			for(int j =1 ; j<=M; j++){
				mp[1][j] = 'X';
			}
		}
		else if(M%3 == 0){
			for(int j = 2; j<=M; j+=3){
				for(int i = 1; i<=N; i++){
					mp[i][j] = 'X';
				}
			}
			for(int j = 5; j<=M; j+=3){
				if(mp[2][j-1] == 'X' || mp[2][j-2] == 'X'){
					mp[2][j-1] = mp[2][j-2] = 'X';
				}
				else{
					mp[1][j-1] = mp[1][j-2] = 'X';
				}
			}
		}
		else{
			for(int j = 1; j<=M; j+=3){
				for(int i = 1; i<=N; i++){
					mp[i][j] = 'X';
				}
			}
			for(int j = 4; j<=M; j+=3){
				if(mp[2][j-1] == 'X' || mp[2][j-2] == 'X'){
					mp[2][j-1] = mp[2][j-2] = 'X';
				}
				else{
					mp[1][j-1] = mp[1][j-2] = 'X';
				}
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				cout << mp[i][j];
			}
			cout << "\n";
		}
	}
}