#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 210;
const ll LOG = 25;
const ll INF = 8e18;
// const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , MOD , ans , C[MAXN][MAXN] , dp[LOG][MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> MOD;
    for(int i = 0 ; i < MAXN ; i++){
        C[i][0] = 1;
        for(int j = 1 ; j <= i ; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }

    for(int x = max(1ll , n - 22) ; x <= n + 1 ; x++){
        memset(dp , 0 , sizeof(dp));
        dp[0][0][0] = 1;
        for(int i = 0 ; i <= n - x + 1 ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int k = 0 ; k <= x ; k++){
                    if(k + x * j > x * (x + i)){
                        break;
                    }
                    int bound = min((ll)j , (i == 0 ? n : k / i));
                    if(j + (i == 0 ? n : x / i) < n){
                        continue;
                    }
                    for(int l = 0 ; l <= bound ; l++){
                        dp[i + 1][j][k] += dp[i][j - l][k - i * l] * C[j][l];
                        if((l & 7) == 7){
                            dp[i + 1][j][k] %= MOD;
                        }
                    }
                    dp[i + 1][j][k] %= MOD;
                    //cout << i << sep << j << sep << k << sep << dp[i + 1][j][k] << endl;
                }
            }
        }
        for(int i = 0 ; i <= x ; i++){
            ans = (ans + dp[n - x + 2][n][i]) % MOD;
        }
        //cout << ans << endl;
        //cout << "==============" << endl;
    }
    cout << ans << endl;

    return 0;
}
/*

*/