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
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll mul(ll a, ll b) {
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}

ll bp(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}


void solve() {
    ll n, m;
    cin >> n >> m;

    ll ans = m % mod, ans1 = m % mod;
    ll x = 1;

    vector <ll> p;

    ll h = 0;
    for (int i = 1; i <= n; i++) {
        (h += bp(m, i)) %= mod;         
    }

    for (ll len = 2; len <= n; len++) {     
        bool fl = 1;
        for (ll i = 2; i * i <= len; i++) if (len % i == 0) fl = 0;
        if (fl) {
            x /= __gcd(x, len);        
            if (m / x < len) break;
            x *= len;        
        }                   
        ans = mul(ans, (m / x));
        ans1 += ans;        
        if (ans1 >= mod) ans1 -= mod;            
    }    
    cout << (h - ans1 + mod) % mod << '\n';
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif    

    int t = 6;
    t = 1;

    while (t--) {
        solve();
    }

    return 0;
}