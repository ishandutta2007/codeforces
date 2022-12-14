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

void solve() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    map <ll, ll> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    ll mx = 0, r = 0;
    ll l = n - 1;
    while (l > 0 && a[l] >= a[l - 1]) l--;
    ll ans = 0;
    map <ll, bool> f;
    while (true) {
        if (mx <= r && r >= l) break;
        if (mx == r) {
            mx++;
            continue;
        }
        while (r < mx) {
            mx = max(mx, mp[a[r]]);
            ans += (f[a[r]] == 0);
            f[a[r]] = 1;
            r++;
        }
    }
    cout << ans << "\n";
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