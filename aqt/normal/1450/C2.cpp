// Problem : C2. Errich-Tac-Toe (Hard Version)
// Contest : Codeforces - Codeforces Global Round 12
// URL : https://codeforces.com/contest/1450/problem/C2
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
char mp[305][305];
int fre[300][5];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		int K = 0;
		memset(fre, 0, sizeof fre);
		for(int i = 0; i<N; i++){
			for(int j = 0; j<N; j++){
				cin >> mp[i][j];
				if(mp[i][j] != '.'){
					K++;
				}
				fre[mp[i][j]][(i+j)%3]++;
			}
		}
		bool done = 0;
		for(int a = 0; a<3; a++){
			for(int b = 0; b<3; b++){
				if(!done && a == (b+1)%3 && fre['X'][a] + fre['O'][b] <= K/3){
					for(int i = 0; i<N; i++){
						for(int j = 0; j<N; j++){
							if((i+j)%3 == a && mp[i][j] == 'X'){
								mp[i][j] = 'O';
							}
							else if((i+j)%3 == b && mp[i][j] == 'O'){
								mp[i][j] = 'X';
							}
							cout << mp[i][j];
						}
						cout << "\n";
					}
					done = 1;
				}
			}
		}
	}
}