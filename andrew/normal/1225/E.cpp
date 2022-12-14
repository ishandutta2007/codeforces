#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2111;
const ll inf = 3e18;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

bool f[N][N];

ll dp[N][N][2];

ll u[N][N][2];
ll pr[N][N][2], st[N];


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m;
    if(n == 1 && m == 1)vout(1);

    char Val;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        cin >> Val;
        if(Val == 'R')f[i][j] = 1;
    }

    dp[1][1][0] = 1;
    dp[1][1][1] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pr[i][j][0] = pr[i][j - 1][0] + f[i][j];
            pr[i][j][1] = pr[i - 1][j][1] + f[i][j];
        }
    }


    for(int i = 1; i <= n; i++){
        ll sc = 0;
        for(int j = 1; j <= m; j++){
            (sc += u[i][j][1]) %= mod;
            (dp[i][j][0] += sc) %= mod;
            (st[j] += u[i][j][0]) %= mod;
            (dp[i][j][1] += st[j]) %= mod;
            if(j < m){
                ll val = pr[i][m][0] - pr[i][j][0];
                (u[i][j + 1][1] += dp[i][j][1]) %= mod;
                u[i][1 + m - val][1] -= dp[i][j][1];
                if(u[i][m - val + 1][1] < 0)u[i][m - val + 1][1] += mod;
            }
            if(i < n){
                ll val = pr[n][j][1] - pr[i][j][1];
                (u[i + 1][j][0] += dp[i][j][0]) %= mod;
                u[n - val + 1][j][0] -= dp[i][j][0];
                if(u[n - val + 1][j][0] < 0)u[n - val + 1][j][0] += mod;
            }
        }
    }

    cout << (dp[n][m][0] + dp[n][m][1]) % mod << "\n";

    return 0;
}