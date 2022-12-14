#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

const int SQRT = 350;
const int MOD = 1e9 + 7;

int dp[2][SQRT][SQRT], n, m;

inline void update(int a, int b, int c, int x){
	dp[a][b][c] += x;
	if (dp[a][b][c] >= MOD)
		dp[a][b][c] -= MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	int x;
	cin >> n >> m >> x;
	swap(n, m);
	if (m > n)
		return cout << 0 << endl, 0;
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++){
		bool p = i % 2;
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= j; k++)
				dp[1 - p][j][k] = 0;
		for (int j = 0; j <= m; j++){
			for (int k = 0; k <= j; k++){
				dp[p][j][k] %= MOD;
				int now = dp[p][j][k];
				// open some at i + 1;
				update(1 - p, j + 1, k + 1, now);
			
				// close first at i + 1;
				if (k > 0 and i != x - 1)
					update(1 - p, j, k - 1, now);	
				
				// open some at i + 1 and close first at i + 1
				update(1 - p, j + 1, k, now);
				
				// do nothing
				if (i != x - 1)
					update(1 - p, j, k, now);
			}
		}
	}
	int fac = 1;
	for (int i = 1; i <= m; i++)
		fac = 1ll * fac * i % MOD;
	cout << 1ll * fac * dp[n % 2][m][0] % MOD << '\n';
}