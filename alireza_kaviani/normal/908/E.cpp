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

const ll MAXN = 1010;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , mark[MAXN] , dp[MAXN] , C[MAXN][MAXN];
string s[MAXN] , t[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(int i = 0 ; i < MAXN ; i++){
        C[i][0] = 1;
        for(int j = 1 ; j <= i ; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    dp[0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        for(int j = 1 ; j <= i ; j++){
            dp[i] = (dp[i] + 1ll * dp[i - j] * C[i - 1][j - 1]) % MOD;
        }
    }

    cin >> m >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
        for(int j = 0 ; j < m ; j++){
            t[j].push_back(s[i][j]);
        }
    }

    ll ans = 1;
    for(int i = 0 ; i < m ; i++){
        if(mark[i]) continue;
        int cnt = 0;
        for(int j = 0 ; j < m ; j++){
            if(t[i] == t[j]){
                mark[j] = 1;
                cnt++;
            }
        }
        ans = ans * dp[cnt] % MOD;
    }
    cout << ans << endl;

    return 0;
}
/*

*/