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

const ll MAXN = 2010 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , dp[MAXN][MAXN] , cnt[MAXN][MAXN];
string s , t;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n >> s >> t;
        s = "." + s; t = "." + t;
        for(int i = 0 ; i < n + 5 ; i++){
            fill(dp[i] , dp[i] + MAXN , 0);
            fill(cnt[i] , cnt[i] + MAXN , 0);
        }
        for(int i = 1 ; i <= n ; i++){
            if(i % 2 == 0 && s[i] != '?'){
                s[i] = (s[i] == '0' ? '1' : '0');
            }
            if(i % 2 == 0 && t[i] != '?'){
                t[i] = (t[i] == '0' ? '1' : '0');
            }
        }
        cnt[0][0] = 1;
        for(int i = 1 ; i <= n ; i++){
            cnt[0][i] = (cnt[0][i - 1] & (t[i] != '1'));
            cnt[i][0] = (cnt[i - 1][0] & (s[i] != '1'));
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(s[i] == '0'){
                    dp[i][j] = dp[i - 1][j];
                    cnt[i][j] = cnt[i - 1][j];
                    continue;
                }
                if(t[j] == '0'){
                    dp[i][j] = dp[i][j - 1];
                    cnt[i][j] = cnt[i][j - 1];
                    continue;
                }
                if(s[i] == '?'){
                    dp[i][j] = dp[i - 1][j];
                    cnt[i][j] = cnt[i - 1][j];
                }
                if(t[j] == '?'){
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
                    cnt[i][j] = (cnt[i][j] + cnt[i][j - 1]) % MOD;
                }
                if(s[i] == '?' && t[j] == '?'){
                    dp[i][j] = (dp[i][j] + MOD - dp[i - 1][j - 1]) % MOD;
                    cnt[i][j] = (cnt[i][j] + MOD - cnt[i - 1][j - 1]) % MOD;
                }
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + 1ll * cnt[i - 1][j - 1] * abs(i - j)) % MOD;
                cnt[i][j] = (cnt[i][j] + cnt[i - 1][j - 1]) % MOD;
            }
        }
        cout << dp[n][n] << endl;
    }

    return 0;
}
/*

*/