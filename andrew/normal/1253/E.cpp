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

ll dp[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    ll n, m;
    cin >> n >> m;

    vector <pll> a(n);

    for(int i = 0; i < n; i++)cin >> a[i].fi >> a[i].se;

    for(int i = 0; i <= m; i++)dp[i] = inf;

    dp[0] = 0;

    for(int i = 0; i < m; i++){
        for(auto j : a){
            ll l = j.fi - j.se, r = j.fi + j.se;
            ll k = max(0ll,  l - i - 1);
            r += k;
            dp[min(r, m)] = min(dp[min(r, m)], dp[i] + k);
        }
    }

    ll ans = inf;

    for(int i = 0; i <= m; i++)ans = min(ans, dp[i] + m - i);

    cout << ans << "\n";

    return 0;
}