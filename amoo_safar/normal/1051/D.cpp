#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld Pi = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) 9223372036854775;

ll dp[MAXN][2*MAXN][4];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    dp[1][1][0] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 1;
    dp[1][1][3] = 1;
    for(int i = 2;i<=1000;i++){
        for(int j = 1;j<=2*i;j++){
            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][3])%MOD;
            dp[i][j][3] = (dp[i-1][j][3] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][0])%MOD;
            if(j==1){
                dp[i][j][1] = (dp[i-1][j][1] + dp[i-1][j-1][0] + dp[i-1][j-1][3] )%MOD;
                dp[i][j][2] = (dp[i-1][j][2] + dp[i-1][j-1][0] + dp[i-1][j-1][3] )%MOD;
            } else {
                dp[i][j][1] = (dp[i-1][j][1] + dp[i-1][j-1][0] + dp[i-1][j-1][3] + dp[i-1][j-2][2])%MOD;
                dp[i][j][2] = (dp[i-1][j][2] + dp[i-1][j-1][0] + dp[i-1][j-1][3] + dp[i-1][j-2][1])%MOD;
            }
            //dp[i][j][1] = (dp[i-1][j][1] + dp[i-1][j-1][0] + dp[i-1][j-1][3] + dp[i-1][j-2][2])%MOD;
            //dp[i][j][2] = (dp[i-1][j][2] + dp[i-1][j-1][0] + dp[i-1][j-1][3] + dp[i-1][j-2][1])%MOD;
        }
    }
    ll n,k;
    cin >> n >> k;
    cout << (dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%MOD;
    return 0;

}