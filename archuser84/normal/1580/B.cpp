///
///   If you lose you die.
///   If you win you live.
///   If you don't fight you can't win.
///   Tatakae! Tatakae!
///

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
typedef long long ll;
typedef long long qw;
typedef __int128 ow;
using namespace std;

const int N = 102;
int dp[N][N][N]; // m, n, k
int C[N][N];
int n, m, k, mod;

void solve()
{
	C[0][0] = 1;
	Loop(n,1,N){
		C[n][0] = C[n][n] = 1;
		Loop(r,1,n) C[n][r] = (C[n-1][r-1] + C[n-1][r]) % mod;
	}

	dp[1][0][0] = 1;
	dp[1][1][1] = 1;
	Loop(i,2,N) dp[1][i][1] = qw(dp[1][i-1][1])*i % mod;
	Loop(m,2,N) {
		dp[m][0][0] = 1;
		Loop(n,1,N) Loop(k,0,n+1)
		{
			qw ans = 0;
			Loop(i,0,n){
				ow ans2 = 0;
				Loop(j,0,k+1)
					ans2 += qw(dp[m-1][i][j])*dp[m-1][n-1-i][k-j];
				ans2 = ans2*C[n-1][i] % mod;
				ans += ans2;
			}
			dp[m][n][k] = ans % mod;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k >> mod;
	auto t1 = clock();
	if(mod == 1) return cout << "0\n", 0;
	solve();
	cout << dp[m][n][k] << '\n';
	#ifndef ONLINE_JUDGE
	cout << double(clock()-t1)/CLOCKS_PER_SEC << '\n';
	#endif
}