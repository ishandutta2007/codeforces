#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
inline void uadd(int &a, int b){
	a += b - Mod;
	a += (a >> 31) & Mod;
}
inline int add(int a, int b){
	a += b - Mod;
	return a += (a >> 31) & Mod;
}

int n, m, lmt;
int dp[2][111][111][111];
int C[333][333];
int main(){
	rep(i, 301)
		C[0][i] = 0, C[i][0] = 1;
	rep(i, 300) rep(j, 300){
		C[i+1][j+1] = min(200, C[i][j] + C[i][j+1]);
	}
	ios::sync_with_stdio(false);
	cin >> n >> m >> lmt;
	int ans = 0;
	rep(i, m-1){
		int now = i & 1, nxt = (i+1) & 1;
		memset(dp[nxt], 0, sizeof(dp[nxt]));
		for(int c = 1; c <= n/2; ++c)
			uadd(dp[now][c][c][1], 1);
		rep(cnt, n+1) for(int j = 1; j <= min(cnt, n-cnt); ++j){
			for(int d = j; cnt+d <= n; ++d){
//				cout << i << " " << cnt << " " << j << " " << d << endl;
				int nval = C[d-1][j-1];
				for(int k = 1; k * nval <= lmt; ++k)
					uadd(dp[nxt][cnt+d][d-j][k * nval], dp[now][cnt][j][k]);
			}
			for(int k = 1; k <= lmt; ++k){
//				if(dp[now][cnt][j][k])
//					cout << "-ansadd " << i << " " << cnt << " " << j << " " << k << ": " << dp[now][cnt][j][k] << endl;
				uadd(ans, dp[now][cnt][j][k]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}