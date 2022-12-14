#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
#define pw(x) (1ll << (x))
#define sz(x) (int)x.size()
#define fout(x) {cout << x << "\n"; return; }

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e6;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const ll inf = 1e18;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll f(ll x){
    return x * (x + 1) / 2;
}

void solve(){
    ll n;
    cin >> n;
    vector <ll> k(n + 1), h(n + 1), dp(n + 1, inf);
    dp[0] = 0;
    k[0] = 0;
    for(int i = 1; i <= n; i++) cin >> k[i];
    for(int i = 1; i <= n; i++) cin >> h[i];

    for(int i = 1; i <= n; i++){
        ll t = k[i];
        for(int j = i; j <= n; j++){
            t = min(t, k[j] - h[j] + 1);
            if(t <= k[i - 1]) break;
            dp[j] = min(dp[j], dp[i - 1] + f(k[j] - t + 1));
        }
    }

    cout << dp[n] << "\n";

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //cin >> t;
    #endif    
    cin >> t;
    
    while(t--){
        solve();
    }


    return 0;
}