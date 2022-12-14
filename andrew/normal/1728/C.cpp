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

ll f(ll x) {
    ll r = 0;
    while (x) {
        x /= 10;
        r++;
    }
    return r;
}

void solve() {       
    ll n;
    cin >> n;
    multiset <ll> a, b;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.insert(x);
    }    
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        b.insert(x);
    }
    ll ans = 0;
    while (sz(a)) {
        ll xa = *--a.end(), xb = *--b.end();
        ans++;
        if (xa == xb) {
            a.erase(a.find(xa));
            b.erase(b.find(xb));
        }else if (xa > xb) {
            a.erase(a.find(xa));
            a.insert(f(xa));
        }else {
            b.erase(b.find(xb));            
            b.insert(f(xb));
        }
    }
    cout << ans - n << "\n";
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;  

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif  
    cin >> t;   

    while (t--) {
        solve();
    }


    return 0;
}