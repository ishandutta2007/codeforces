#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 710;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , ans , pw10[MAXN] , dp[MAXN][MAXN][2];
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	pw10[1] = 1;
	for(int i = 2 ; i < MAXN ; i++)	pw10[i] = (pw10[i - 1] * 10 + 1) % MOD;
	
	cin >> s; 
	n = s.size();
	for(int i = 1 ; i < 10 ; i++){
		memset(dp , 0 , sizeof(dp));
		dp[0][0][1] = 1;
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k <= j ; k++){
				for(int l = 0 ; l < 10 ; l++){
					dp[j + 1][k + (l >= i)][0] = (dp[j + 1][k + (l >= i)][0] + dp[j][k][0]) % MOD;
					if(l <= int(s[j] - 48)){
						dp[j + 1][k + (l >= i)][(l == int(s[j] - 48))] = (dp[j + 1][k + (l >= i)][(l == int(s[j] - 48))] + dp[j][k][1]) % MOD;
					}
				}
			}
		}
		for(int j = 0 ; j <= n ; j++){
			ans = (ans + (dp[n][j][0] + dp[n][j][1]) * pw10[j]) % MOD;
		}
	}
	cout << ans << endl;

    return 0;
}
/*

*/