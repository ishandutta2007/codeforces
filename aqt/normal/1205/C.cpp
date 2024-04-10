
// Problem : C. Palindromic Paths
// Contest : Codeforces - Codeforces Round #580 (Div. 1)
// URL : https://codeforces.com/contest/1205/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int query(int x1, int y1, int x2, int y2){
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int n;
	cin >> n;
	return n;
}

int tbl[55][55];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	tbl[1][1] = 1;
	for(int i = 3; i<=N; i+=2){
		tbl[1][i] = query(1, i-2, 1, i)^1^tbl[1][i-2];
	}
	for(int i = 2; i<=N; i+=2){
		tbl[2][i] = query(1, i-1, 2, i)^1^tbl[1][i-1];
	}
	for(int i = 3; i<=N; i+=2){
		for(int j = 1; j<=N; j+=2){
			tbl[i][j] = query(i-2, j, i, j)^1^tbl[i-2][j];
		}
	}
	for(int i = 4; i<=N; i+=2){
		for(int j = 2; j<=N; j+=2){
			tbl[i][j] = query(i-2, j, i, j)^1^tbl[i-2][j];
		}
	}
	for(int i = 4; i<=N; i+=2){
		tbl[1][i] = query(1, i-2, 1, i) ^ 1 ^ tbl[1][i-2];
	}
	//cout << "here" << endl;
	for(int i = 2; i<=N; i++){
		int k = (i%2 ? 2 : 3);
		for(int j = k; j<=N; j+=2){
			tbl[i][j] = query(i-1, j-1, i, j) ^ 1 ^ tbl[i-1][j-1];
		}
		if(k == 3){		
			tbl[i][k-2] = query(i, k-2, i, k) ^ 1 ^ tbl[i][k];
		}
	}
	//cout << "here" << endl;
	for(int n = 1; n<=N; n++){
		if(tbl[n][n] && !tbl[n+2][n+2]){
			bool b1 = query(n, n, n+2, n+1);
			bool b2 = query(n+1, n, n+2, n+2);
			bool c1 = (tbl[n][n] == tbl[n+2][n+1]) && (((1<<tbl[n+1][n]) | (1<<tbl[n][n+1])) & ((1<<tbl[n+2][n]) | (1<<tbl[n+1][n+1])));
			bool c2 = (tbl[n+1][n] == tbl[n+2][n+2] && (((1<<tbl[n+2][n]) | (1<<tbl[n+1][n+1])) & ((1<<tbl[n+2][n+1]) | (1<<tbl[n+1][n+2]))));
			//cout << b1 << " " << b2 << " " << c1 << " " << c2 << endl;
			if((b1 != c1) || (c2 != b2)){
				for(int i = 1; i<=N; i++){
					for(int j = 1; j<=N; j++){
						tbl[i][j] ^= (i+j)%2;
					}
				}
			}
			break;
		}
	}
	cout << "!" << endl;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cout << tbl[i][j];
		}
		cout << endl;
	}
}