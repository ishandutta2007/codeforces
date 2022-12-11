
// Problem : G. A/B Matrix
// Contest : Codeforces - Codeforces Round #644 (Div. 3)
// URL : https://codeforces.com/contest/1360/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

bool mat[55][55];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, M, R, C;
		cin >> N >> M >> R >> C;
		if(N*R == M*C){
			for(int s = 0; s<M; s++){
				for(int i = 0; i<N; i++){
					for(int j = 0; j<M; j++){
						mat[i][j] = 0;
						if((i*s%M<=j && j<i*s%M+R) || (i*s%M-M <= j && j<i*s%M+R-M)){
							mat[i][j] = 1;
						}
					}
				}
				bool good = 1;
				for(int j = 0; j<M; j++){
					int sum = 0;
					for(int i = 0; i<N; i++){
						sum += mat[i][j];
					}
					if(sum != C){
						good = 0;
						break;
					}
				}
				if(good){
					cout << "YES\n";
					for(int i = 0; i<N; i++){
						for(int j = 0; j<M; j++){
							cout << mat[i][j];
						}
						cout << "\n";
					}
					break;
				}
				else if(s == M-1){
					cout << "NO\n";
				}
			}
		}
		else{
			cout << "NO\n";
		}
	}
}