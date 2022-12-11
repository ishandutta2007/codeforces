
// Problem : E. Salazar Slytherin's Locket
// Contest : Codeforces - Manthan, Codefest 17
// URL : https://codeforces.com/contest/855/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
long long dp[15][2][70][1<<10];
int base[15];

long long solve(int b, bool s, int p, int msk, bool bor, long long lim){
	if(p == -1){
		return (msk == 0);
	}
	if(!bor && dp[b][s][p][msk]+1){
		return dp[b][s][p][msk];
	}
	long long k = 1;
	for(int i = 0; i<p; i++){
		k *= b;
	}
	int l = (long long) ((lim/k))%b;
	if(!bor){
		l = b-1;
	}
	long long ret = 0;
	for(int d = 0; d<=l; d++){
		ret += solve(b, s&&(d == 0), p-1, msk^((1<<d)*(!(s&&(d==0)))), bor&&(d == l), lim);
	}
	if(!bor){
		dp[b][s][p][msk] = ret;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	memset(dp, -1, sizeof dp);
	for(int i = 2; i<=10; i++){
		base[i] = 18/log10(i);
	}
	while(T--){
		int b;
		long long l, r;
		cin >> b >> l >> r;
		cout << solve(b, 1, base[b], 0, 1, r) - solve(b, 1, base[b], 0, 1, l-1) << "\n";
	}
}