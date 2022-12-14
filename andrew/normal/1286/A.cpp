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
const ll N = 2e6;
const ll inf = 3e18;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T> void vout(T s){cout << s << endl;exit(0);}

ll dp[101][101][2];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n;
    cin >> n;
    vector <ll> a(n + 1);
    vector <bool> f(n + 1);

    ll sca, scb;
    sca = (n + 1) / 2;
    scb = n / 2;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        f[a[i]] = 1;
        if((a[i] & 1))sca--;
        else if(a[i])scb--;
    }

    ll kol = 0;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)dp[i][j][0] = dp[i][j][1] = inf;

    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    ll S = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n; j++)
            for(int last = 0; last < 2; last++){
                if(a[i] == 0){
                    if(S - j + 1 <= sca)dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][last] + (1 != last));
                    if(j + 1 <= scb)dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i - 1][j][last] + (0 != last));
                }else{
                    dp[i][j][a[i] & 1] = min(dp[i][j][a[i] & 1], dp[i - 1][j][last] + (a[i] % 2 != last));
                }
            }
        if(!a[i])S++;
    }

    ll ans = inf;
    for(int i = 0; i <= n; i++)
        for(int i1 = 0; i1 < 2; i1++)ans = min(ans, dp[n][i][i1]);

    cout << ans << "\n";

    return 0;
}