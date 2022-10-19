#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;
void update(ll &a, ll b){
	a += b;
	if(a >= Mod)
		a -= Mod; 
}

int n, m; 
bool done[555][555];
ll dp[555][555];
ll C[555][555];
ll pw[555][555];
ll dfs(int x, int y){
	if(x <= 0 || y <= 0)
		return 0;
	if(done[x][y])
		return dp[x][y];
	done[x][y] = 1;
	if(y <= x - 1){
		return dp[x][y] = (pw[y][x] - pw[y - 1][x] + Mod) % Mod;
	}
	dp[x][y] = 0;
	for(int nx = 2; nx <= x; nx++){
//		cout << x << " " << y << " " << nx << ": " << dfs(nx, y - (x - 1)) * C[x][nx] % Mod * pw[x - 1][x - nx] % Mod << endl;
		update(dp[x][y], dfs(nx, y - (x - 1)) * C[x][nx] % Mod * pw[x - 1][x - nx] % Mod);
	}
	return dp[x][y];
}

int main(){
	rep(i, 501)
		C[0][i] = 0, C[i][0] = 1;
	for(int i = 1; i <= 500; i++)
		for(int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
	rep(i, 501){
		pw[i][0] = 1;
		for(int j = 1; j <= 500; j++)
			pw[i][j] = pw[i][j - 1] * i % Mod;
	}
	ios::sync_with_stdio(false);
	cin >> n >> m;
	ll ans = 0;
	rep(y, m + 1)
		update(ans, dfs(n, y));
//	rep(i, n + 1){
//		rep(j, m + 1)
//			cout << dp[i][j] << " ";
//		cout << endl;
//	}
	cout << ans << endl;
	return 0;
}