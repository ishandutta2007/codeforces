
// Problem : C. More Reclamation
// Contest : Codeforces - MemSQL start[c]up Round 2 - online version
// URL : https://codeforces.com/contest/335/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int dp[105][2][2][2][2];
bool tkn[105][2];

int solve(int n, int tl, int tr, int bl, int br){
	if(n <= 0){
		return 0;
	}
	if(dp[n][tl][tr][bl][br] + 1){
		return dp[n][tl][tr][bl][br];
	}
	set<int> st;
	for(int i = 1+tl; i<=n-tr; i++){
		st.insert(solve(i-1, tl, 0, bl, 1)^solve(n-i, 0, tr, 1, br));
	}
	for(int i = 1+bl; i<=n-br; i++){
		st.insert(solve(i-1, tl, 1, bl, 0)^solve(n-i, 1, tr, 0, br));
	}
	int g = 0;
	while(st.count(g)){
		g++;
	}
	return dp[n][tl][tr][bl][br] = g;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> N >> K;
	while(K--){
		int r, c;
		cin >> r >> c;
		c--;
		tkn[r][c] = 1;
		tkn[r-1][c^1] = tkn[r][c^1] = tkn[r+1][c^1] = 1;
	}
	int x = 0;
	int lst = 0;
	tkn[N+1][0] = tkn[N+1][1] = 1;
	for(int i = 1; i<=N+1; i++){
		if(tkn[i][0] && tkn[i][1]){
			x ^= (solve(i-lst-1, tkn[lst+1][0], tkn[i-1][0], tkn[lst+1][1], tkn[i-1][1]));
			lst = i;
		}
	}
	cout << (x ? "WIN" : "LOSE");
}