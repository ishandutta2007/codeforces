#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1010;
const int M = 1e7;
const ll inf = 1e18;
const int mod = 998244353;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int dp[N][N][2][4];

int sum(int a, int b){
    a += b;
    if(a >= mod)a -= mod;
    return a;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    string x, y;
    cin >> x >> y;

    int n = sz(x), m = sz(y);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i + 1][j][0][1]++;
            dp[i][j + 1][1][2]++;
        }
    }

    char c;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++)
            for(int i1 = 0; i1 < 4; i1++){
                if(i != 0){
                    c = x[i - 1];
                    if(i < n){
                        if(c != x[i]){
                            dp[i + 1][j][0][i1 | 1] = sum(dp[i + 1][j][0][i1 | 1], dp[i][j][0][i1]);
                        }
                    }
                    if(j < m){
                        if(c != y[j]){
                            dp[i][j + 1][1][i1 | 2] = sum(dp[i][j + 1][1][i1 | 2], dp[i][j][0][i1]);
                        }
                    }
                }
                if(j != 0){
                    c = y[j - 1];
                    if(i < n){
                        if(c != x[i]){
                            dp[i + 1][j][0][i1 | 1] = sum(dp[i + 1][j][0][i1 | 1], dp[i][j][1][i1]);
                        }
                    }
                    if(j < m){
                        if(c != y[j]){
                            dp[i][j + 1][1][i1 | 2] = sum(dp[i][j + 1][1][i1 | 2], dp[i][j][1][i1]);
                        }
                    }
                }
            }
    }

    int ans = 0;

    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= m + 1; j++){
            ans = sum(ans, dp[i][j][0][3]);
            ans = sum(ans, dp[i][j][1][3]);
        }

    cout << ans << "\n";

    return 0;
}