#include<bits/stdc++.h>
using namespace std;

int dp[43][200003] , N , M , Q , A , B , sum[200003];
set < pair < int , int > > pot;

int main(){
	cin >> N >> M >> Q; bool f = N > M; if(f) swap(N , M);
	for(int i = 1 ; i <= Q ; ++i){cin >> A >> B; if(f){swap(A , B);} if(A == N){sum[B] = 1;} pot.insert(make_pair(A , B));}
	sum[M] = 0;
	for(int i = M - 1 ; i ; --i) sum[i] = sum[min(M , sum[i] + N + i)] + 1;
	dp[0][1] = 1; int ans = 1e9;
	for(int i = 0 ; i < 40 ; ++i){
		if(dp[i][N]) ans = min(ans , i + sum[dp[i][N]]);
		for(int j = 1 ; j <= N ; ++j)
			if(dp[i][j]){
				bool f = pot.find(make_pair(j , dp[i][j])) != pot.end();
				dp[i + 1][min(dp[i][j] + j + f , N)] = max(dp[i + 1][min(dp[i][j] + j + f , N)] , dp[i][j]);
				dp[i + 1][j] = max(dp[i + 1][j] , min(dp[i][j] + j + f , M));
			}
	}
	cout << ans;
	return 0;
}