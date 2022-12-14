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
const int N = 50001;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll f(vector <ll> a, ll x) {
    ll ans = 0;
    for (auto &i : a) {
        if (i * 2 < x) {
            i = 1e9;
            ans++;            
        }
    }
    ll mn = *min_element(all(a));    
    ll cres = 2;
    for (int i = 0; i + 1 < sz(a); i++) {
        if (min(mn * 2, min(a[i], a[i + 1])) >= x) {
            return ans;
        }
        if (max(a[i], a[i + 1]) >= x) cres = 1;
    }
    return ans + cres;    
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n), b;
    for (auto &i : a) cin >> i;
    ll l = 0, r = 1e9;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (f(a, mid) > k) r = mid - 1;
        else l = mid;
    }
    cout << l << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;    

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