#include<bits/stdc++.h>
using namespace std;

#define int long long
int N , M , T; int dst[503][503] , val[503][503]; bool vis[503][503];

signed main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; int ans = 1e18;
		memset(dst , 0x3f , sizeof(dst));
		memset(val , 0x3f , sizeof(val));
		memset(vis,  0 , sizeof(vis));
		for(int i = 1 ; i <= M ; ++i){
			int s , t , w; cin >> s >> t >> w;
			val[s][t] = min(val[s][t] , w);
			dst[s][t] = dst[t][s] = 1;
			val[t][s] = min(val[t][s] , w);
			vis[s][t] = vis[t][s] = 1;
		}
		for(int i = 1 ; i <= N ; ++i) dst[i][i] = 0;
		for(int k = 1 ; k <= N ; ++k)
			for(int i = 1 ; i <= N ; ++i)
				for(int j = 1 ; j <= N ; ++j)
					dst[i][j] = min(dst[i][j] , dst[i][k] + dst[k][j]);
		for(int i = 1 ; i <= N ; ++i)
			for(int j = i + 1 ; j <= N ; ++j)
				if(vis[i][j]){
					int cnt = min(dst[1][i] + dst[N][j] , dst[N][i] + dst[1][j]);
					for(int k = 1 ; k <= N ; ++k)
						cnt = min(cnt , min(dst[j][k] , dst[i][k]) + 1 + dst[k][N] + dst[k][1]);
					ans = min(ans , (cnt + 1) * val[i][j]);
				}
		cout << ans << endl;
	}
	return 0;
}