#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ld long double

using namespace std;
typedef long long ll;
const ll MAXN = 1123456;

template <typename T> void vout(T s){
    cout << s << endl;
    exit(0);
}

ll c[20][20];

const ll MAX_MASK = 1ll << 18;

ll dp[20][MAX_MASK];
bool f[20][MAX_MASK];

ll step(ll x){
    return 1ll << x;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n, m, k;

    cin >> n >> m >> k;

    vector <ll> a(n);

    for(int i = 0; i < n; i++)cin >> a[i];

    while(k--){
        ll a, b, val;
        cin >> a >> b >> val;
        a--, b--;
        c[a][b] = val;
    }

    for(int i = 0; i < n; i++)dp[i][1ll << i] = a[i], f[i][1ll << i] = 1;

    ll musk = 1ll << n;

    ll ans = 0;

    for(int i = 0; i < musk; i++){
        for(int what = 0; what < n; what++)if(f[what][i]){
            ll val = dp[what][i];
            for(int j = 0; j < n; j++)if(!(step(j) & i)){
                ll val1 = val + a[j] + c[what][j];
                f[j][i | step(j)] = 1;
                dp[j][i | step(j)] = max(dp[j][i | step(j)], val1);
            }
            if(__builtin_popcount(i) == m)ans = max(ans, dp[what][i]);
        }
    }

    cout << ans << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}