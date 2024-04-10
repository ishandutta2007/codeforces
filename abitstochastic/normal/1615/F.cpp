#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7; int T , N; string S1 , S2;
int dp[2003][4003][2];

int main(){
	for(cin >> T ; T ; --T){
		cin >> N >> S1 >> S2; dp[0][N][0] = 1;
		for(int i = 0 ; i < N ; ++i)
			for(int p = 0 ; p < 2 ; ++p)
				for(int q = 0 ; q < 2 ; ++q)
					if(S1[i] != (p ^ 1) + '0' && S2[i] != (q ^ 1) + '0'){
						int dir = p == q ? 0 : ((p ^ (i & 1)) == 1 ? 1 : -1);
						for(int j = N - i ; j <= N + i ; ++j){
							dp[i + 1][j + dir][0] = (dp[i + 1][j + dir][0] + dp[i][j][0]) % P;
							dp[i + 1][j + dir][1] = (dp[i + 1][j + dir][1] + 1ll * dp[i][j][0] * abs(j + dir - N) + dp[i][j][1]) % P;
						}
					}
		cout << dp[N][N][1] << endl;
		for(int i = 0 ; i <= N ; ++i) for(int j = 0 ; j <= 2 * N ; ++j) dp[i][j][0] = dp[i][j][1] = 0;
	}
	return 0;
}