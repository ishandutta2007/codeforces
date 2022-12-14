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

    ll n, q;
    cin >> n >> q;

    vector <ll> a(n + 1), pref(n + 1);

    set <int> n0;

    map <pll, set <int>> mp;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] ^ a[i];
        mp[{pref[i], i % 2}].insert(i);
        if (a[i] > 0) {
            n0.insert(i);
        }
    }

    set <int> :: iterator it;

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (n0.lower_bound(l) == n0.end() || *n0.lower_bound(l) > r) {
            cout << "0\n";
        } else {
            if ((pref[r] ^ pref[l - 1]) != 0) {
                cout << "-1\n";
            }else if ((r - l + 1) % 2 == 1 || a[r] == 0 || a[l] == 0) {
                cout << "1\n";
            }else {
                if (mp.find({pref[l - 1], l % 2}) == mp.end()) {
                    cout << "-1\n";
                }else {
                    it = mp[{pref[l - 1], l % 2}].lower_bound(l);
                    if (it != mp[{pref[l - 1], l % 2}].end() && *it <= r) {
                        cout << "2\n";
                    }else {
                        cout << "-1\n";
                    }
                }
            }
        }
    }   

    return 0;
}