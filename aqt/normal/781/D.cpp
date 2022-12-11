
// Problem : D. Axel and Marston in Bitland
// Contest : Codeforces - Codeforces Round #403 (Div. 1, based on Technocup 2017 Finals)
// URL : https://codeforces.com/contest/781/problem/D
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
bitset<505> lft[505], rht[505];
bool mat[2][70][505][505];
bool crnt[505][505];
bool tmp[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i =1; i<=M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		mat[c][0][a][b] = 1;
	}
	for(int lvl = 1; lvl<=60; lvl++){
		for(int i = 1; i<=N; i++){
			for(int j =1; j<=N; j++){
				lft[i][j] = mat[0][lvl-1][i][j];
				rht[j][i] = mat[1][lvl-1][i][j];
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=N; j++){
				mat[0][lvl][i][j] = (lft[i] & rht[j]).count();
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j =1; j<=N; j++){
				lft[i][j] = mat[1][lvl-1][i][j];
				rht[j][i] = mat[0][lvl-1][i][j];
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=N; j++){
				mat[1][lvl][i][j] = (lft[i] & rht[j]).count();
			}
		}		
	}
	long long ans = -1;
	for(int lvl = 0; lvl <= 60; lvl++){
		bool t = 0;
		for(int i = 1; i<=N; i++){
			t |= mat[0][lvl][1][i];
		}
		if(!t){
			ans = (1LL << (lvl-1));
			if(!lvl){
				cout << 0 << endl;
				return 0;
			}
			for(int i = 1; i<=N; i++){
				for(int j = 1; j<=N; j++){
					crnt[i][j] = mat[0][lvl-1][i][j];
				}
			}
			break;
		}
	}
	if(ans == -1){
		cout << ans << endl;
		return 0;
	}
	/*
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cout << mat[1][0][i][j] << " ";
		}
		cout << "\n";
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cout << crnt[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	bool inv = 1;
	for(int lvl = 60; lvl>=0; lvl--){
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=N; j++){
				lft[i][j] = crnt[i][j];
				rht[j][i] = mat[inv][lvl][i][j];
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=N; j++){
				tmp[i][j] = (lft[i] & rht[j]).count();
			}
		}
		bool t = 0;
		for(int i = 1; i<=N; i++){
			t |= tmp[1][i];
		}
		if(t){
			ans += (1LL<<lvl);
			for(int i = 1; i<=N; i++){
				for(int j = 1; j<=N; j++){
					crnt[i][j] = tmp[i][j];
				}
			}
			inv ^= 1;
		}
	}
	if(ans > 1000000000000000000LL){
		ans = -1;
	}
	cout << ans;
}