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
const ll inf = 3e18;
const ll N = 1500;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[N][N];

ll dp1[N];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)dp[i][j] = -1;

    vector <ll> a(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i][a[i]] = i;
    }

    ll ukl, ukr;

    for(int i = 1; i < N; i++){
        for(int uk = 1; uk <= n; uk++)if(dp[uk][i] != -1 && dp[uk][i] < n){
            ukl = dp[uk][i];
            if(dp[ukl + 1][i] != -1){
                ukr = dp[ukl + 1][i];
                dp[uk][i + 1] = ukr;
            }
        }
    }

    for(int i = 0; i <= n; i++)dp1[i] = inf;

    dp1[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= N; j++)if(dp[i][j] != -1){
            ll res = dp1[i - 1] + 1;
            dp1[dp[i][j]] = min(dp1[dp[i][j]], res);
        }
    }

    cout << dp1[n] << "\n";

    return 0;
}