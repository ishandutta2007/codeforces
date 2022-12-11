
// Problem : F. Daniel and Spring Cleaning
// Contest : Codeforces Round #597 (Div. 2)
// URL : https://codeforces.com/contest/1245/problem/F
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
long long dp[3][35][2][2];

long long solve(int p, int L, int R, bool bL, bool bR, int t){
	if(p == -1){
		return 1;
	}
	if(dp[t][p][bL][bR] != -1){
		return dp[t][p][bL][bR];
	}	
	//cout << p << " " << L << " " << R << " " << bL << " " << bR << " " << t << "\n";
	long long ret = 0;
	int c1 = L>>p&1, c2 = R>>p&1;
	for(int d = 0; d<3; d++){
		int b1 = d&1, b2 = (d&2)>>1;
		if(bL && b1 > c1){
			continue;
		}
		if(bR && b2 > c2){
			continue;
		}
		ret += solve(p-1, L, R, bL && b1 == c1, bR && b2 == c2, t);
		//cout << p << " " << L << " " << R << " " << bL << " " << bR << " " << t << "\n";		
	}
	//cout << t << " " << ret << "\n";
	return dp[t][p][bL][bR] = ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		long long L, R;
		cin >> L >> R;
		for(int d = 30; d>=0; d--){
			for(int k = 0; k<3; k++){
				dp[k][d][0][0] = dp[k][d][0][1] = dp[k][d][1][0] = dp[k][d][1][1] = -1;
			}
		}
		L--;
		long long out = solve(30, R, R, 1, 1, 0);
		if(L >= 0){
			out += -2*solve(30, L, R, 1, 1, 1) + solve(30, L, L, 1, 1, 2);
		}
		cout << out << "\n";
	}
}