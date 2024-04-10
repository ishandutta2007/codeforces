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

void solve(){
    ll n, q;
    cin >> n >> q;
    vector <ll> a(n), ans(n);
    ll musk = pw(31) - 1;
    vector <pair <pll, ll>> arr(q);
    for (auto &i : arr) {
        cin >> i.fi.fi >> i.fi.se >> i.se;
        if (i.fi.fi > i.fi.se) swap(i.fi.fi, i.fi.se);
        i.fi.fi--;
        i.fi.se--;
    }
    sort(all(arr));
    // reverse(all(arr));
    for (auto i : arr) {
        a[i.fi.fi] |= musk ^ i.se;
        a[i.fi.se] |= musk ^ i.se;
    }

    for (auto i : arr) {
        for (int j = 0; j < 30; j++) if ((i.se & pw(j))) {
            if ((a[i.fi.fi] & pw(j))) {
                ans[i.fi.se] |= pw(j);
            }else if ((a[i.fi.se] & pw(j))) {
                ans[i.fi.fi] |= pw(j);
            }
        }
    }

    for (auto i : arr) {
        for (int j = 0; j < 30; j++) if ((i.se & pw(j))) {
            if ((ans[i.fi.fi] & pw(j))) {
                continue;
            }else if ((ans[i.fi.se] & pw(j))) {
                continue;
            }else {
                ans[i.fi.se] |= pw(j);
            }
        }
    }

    for (auto i : ans) cout << i << " ";
    cout << "\n";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;    
    t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        cin >> t;
    #endif    
    //cin >> t;
    
    while(t--){
        solve();
    }


    return 0;
}