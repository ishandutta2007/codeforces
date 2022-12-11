
// Problem : F. Balanced Domino Placements
// Contest : Codeforces - Codeforces Global Round 5
// URL : https://codeforces.com/contest/1237/problem/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, K;
bool row[3605], col[3605];
long long fact[3605];
long long dpr[3605][3605], dpc[3605][3605];
long long pas[3605][3605];
const long long MOD = 998244353;

long long add(long long a, long long b){
	return (a + b) % MOD;
}

long long mult(long long a, long long b){
	return a * b % MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	fact[0] = 1;
	for(int i = 0; i <= max(N, M); i++){
		if(i){
			fact[i] = mult(fact[i-1], i);
		}
		pas[i][0] = 1;
		for(int j = 1; j <= i; j++){
			pas[i][j] = add(pas[i-1][j-1], pas[i-1][j]);
		}
	}
	while(K--){
		for(int t = 0; t < 2; t++){
			int r, c;
			cin >> r >> c;
			row[r] = 1;
			col[c] = 1;
		}
	}
	int r = 0;
	for(int i = 1; i <= N; i++){
		r += !row[i];
	}
	int c = 0;
	for(int i = 1; i <= M; i++){
		c += !col[i];
	}	
	row[0] = col[0] = 1;
	dpr[0][0] = 1;
	for(int n = 1; n <= N; n++){
		for(int v = 0; v <= n; v++){
			dpr[n][v] = dpr[n-1][v];
			if(!row[n] && !row[n-1]){
				dpr[n][v] = add(dpr[n][v], dpr[n-2][v-1]);
			}
		}
	}
	dpc[0][0] = 1;
	for(int n = 1; n <= M; n++){
		for(int h = 0; h <= n; h++){
			dpc[n][h] = dpc[n-1][h];
			if(!col[n] && !col[n-1]){
				dpc[n][h] = add(dpc[n][h], dpc[n-2][h-1]);
			}
		}
	}
	long long ans = 0;
	for(int v = 0; v <= N; v++){
		for(int h = 0; h <= M; h++){
			if(v + 2 * h > c || h + 2 * v > r){
				break;
			}
			ans = add(ans, mult(mult(dpr[N][v], dpc[M][h]), 
			mult(mult(pas[r - 2 * v][h], fact[h]), mult(pas[c - 2 * h][v], fact[v]))));
		}
	}
	cout << ans;
}