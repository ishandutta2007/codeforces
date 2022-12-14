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
const int MAXN = 1e6 + 1e5;;
const int M = pw(16);
const long long mod = 998244353;
const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll r[MAXN], f[MAXN], fact[MAXN];

ll bp(ll a, ll n) {
    ll r = 1;
    while (n) {
        if (n & 1) {
            (r *= a) %= mod;
        }
        (a *= a) %= mod;
        n >>= 1;
    }
    return r;
}

ll fc(ll n, ll k) {
    if (k == 0) return 1;
    if (k > n) return 0;
    if (k < 0) return 0;
    return (fact[n] * bp((fact[n - k] * fact[k]) % mod, mod - 2)) % mod;
}

void solve() {       
    
    ll n;
    cin >> n;

    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2] * (i - 1)) % mod;       
    }

    ll ans = 0;
    ll zmen = 1;        
    for (ll c4 = 0; c4 * 4 <= n; c4++) {
        ll res = (fc(n - 2 * c4, 2 * c4) * zmen) % mod;
        (zmen *= 4 * c4 + 2) %= mod;                
        (ans += (f[n - c4 * 4] * res) % mod) %= mod;
    }
    
    cout << ans << "\n";
}

void pre_calc() {    
    // ll s = 0;
    // for (int n = 10; n <= 10; n++) {
    //     ll ans = 0;
    //     vector <ll> p(n);
    //     vector <int> wh(n);
    //     iota(all(p), 0);
    //     int st = 0, c;
    //     do{
    //         for (int i = 0; i < n; i++) wh[p[i]] = i;
    //         bool f = 1;
    //         for (int i = 0; i < n; i++) if (abs(wh[i] - p[i]) > 1) f = 0;
    //         st = c = 0;   
    //         vector <int> vv;
    //         do {
    //             c++;
    //             st = p[st];
    //             vv.p_b(st);
    //         }while (st != 0);
    //         if (c != 4) f = 0;
    //         if (f) {
    //             ans++;
    //             // for (auto j : p) cout << j << " ";
    //             for (auto j : vv) cout << j << " ";
    //             cout << "\n";
    //         }
    //     }while(next_permutation(all(p)));
    //     // cout << ans << ", ";
    //     s = ans;
    // }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif  

    // pre_calc();    
    // return 0;   

    cin >> t;   

    while (t--) {
        solve();
    }


    return 0;
}