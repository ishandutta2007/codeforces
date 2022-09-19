// har ki ro didi goft mikhad beshe meslemon !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 5e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


ll dp[2][N][2];

ll t[N], x[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> x[i];
	}
	x[0] = 0; t[0] = 0;
	
	memset(dp, 31, sizeof dp);
	for(int nc = 0; nc <= n; nc ++){
		if(abs(x[nc]) <= t[nc]) dp[0][nc][1] = abs(x[nc]);
	}

	ll oo = 2e9;
	ll pos;
	for(int i = 0; i < n; i++){
		int ii = (i + 1) & 1;
		memset(dp[ii], 31, sizeof dp[ii]);
		int I = i&1;
		for(int j = 0; j <= n; j++){
			for(int b = 0; b < 2; b++){
				if(dp[I][j][b] >= oo) continue;
				//if(dp[i][j][b] > t[i + 1]) continue;
				//cerr << i << " " << j << ' ' << b << ' ' << dp[i][j][b] << '\n'; 
				pos = (b == 0 ? x[i] : x[j]);
				if(j == i + 1 && dp[I][j][b] <= t[i + 1]){
					for(int nc = 0; nc <= n; nc ++){
						
						// if(max(dp[i][j][b] + abs(pos - x[nc]), t[i + 1]) <= t[nc])
							dp[ii][nc][1] = min(dp[ii][nc][1], max(dp[I][j][b] + abs(pos - x[nc]), t[i + 1]));
					}
				} else {
					if(dp[I][j][b] + abs(pos - x[i + 1]) <= t[i + 1]){
						dp[ii][j][0] = min(dp[ii][j][0], t[i + 1]);
					}
				}
			}
		}
	}
	for(int j = 0; j <= n; j++) for(int b= 0; b < 2; b++) if(dp[n&1][j][b] < oo) return cout << "YES\n", 0;
	cout << "NO\n";
	// cout << (min(dp[n][n][0], dp[n][n][1]) <= t[n] ? "YES\n" : "NO\n");
	return 0;
}