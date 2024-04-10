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

const ll MOD = (ll) 1e9 + 7;
const ll MAXN = (ll) 1e2 + 10;
const ll INF = (ll) 3e18;
const ld EPS = (ld) 1e-8;

ll dp[MAXN][MAXN][MAXN];

ll c[MAXN];

ll p[MAXN][MAXN];

int main(){
    for(int i =0;i<MAXN;i++){
        for(int j =0;j<MAXN;j++) fill(dp[i][j], dp[i][j] + MAXN, INF);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i =0;i<n;i++) cin >> c[i];
    for(int i = 0; i < n; i++){
        for(int j =0;j<m;j++) cin >> p[i][j];
    }
    if(c[0] == 0){
        for(int i = 1;i<=m;i++){
            dp[0][1][i] = p[0][i - 1];
        }
    } else {
        dp[0][1][c[0]] = 0;
    }

    for(int i = 1;i<n;i++){
        if(c[i] == 0){
            for(int co = 1;co<=m;co++){
                for(int j = 1;j<=k;j++){
                    for(int kk =1;kk<=m;kk++){
                        if(kk == co){
                            dp[i][j][co] = min(dp[i][j][co],dp[i-1][j][co] + p[i][co-1]);
                        } else {
                            dp[i][j][co] = min(dp[i][j][co],dp[i-1][j - 1][kk] + p[i][co-1]);
                        }
                    }
                }
            }
        } else {
            for(int j = 1;j<=k;j++){
                for(int kk =1;kk<=m;kk++){
                    if(kk == c[i]){
                        dp[i][j][c[i]] = min(dp[i][j][c[i]],dp[i-1][j][c[i]]);
                    } else {
                        dp[i][j][c[i]] = min(dp[i][j][c[i]],dp[i-1][j - 1][kk]);
                    }
                }
            }
        }
    }
    ll ans = INF;
    for(int j =1;j<=m;j++) ans = min(ans, dp[n-1][k][j]);
    if(ans >= INF) cout << -1;
    else cout << ans;
    return 0;
}

/*
*/