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

const ll MAXN = 5010;
const ll LOG = 22;
const ll INF = 8e18;
//const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , MOD , ans , S[MAXN][MAXN] , C[MAXN][MAXN] , pw[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> MOD;

    S[0][0] = 1;
    for(int i = 1 ; i < MAXN ; i++){
        for(int j = 1 ; j <= i ; j++){
            S[i][j] = (j * S[i - 1][j - 1] + S[i - 1][j] * (i + j - 1)) % MOD;
        }
    }

    for(int i = 0 ; i < MAXN ; i++){
        C[i][0] = 1;
        for(int j = 1 ; j <= i ; j++){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }

    for(int i = 0 ; i < MAXN ; i++){
        pw[i][0] = 1;
        for(int j = 1 ; j < MAXN ; j++){
            pw[i][j] = pw[i][j - 1] * i % MOD;
        }
    }

    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            if(i * 2 + j > n)   continue;
            if(i == 0 && j != n)    continue;
            ans = (ans + C[n][j] * pw[n - i - j][j] % MOD * C[n - j][i] % MOD * S[n - i - j][i] % MOD * pw[n - 1][i]) % MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
/*

*/