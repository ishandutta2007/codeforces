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
const int N = 1e6;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

map <ll, ll> mp, a;
map <ll, set <ll>> st;
map <ll, set<ll> > s1;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;

    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        // cin >> t;
    #endif    

    ll q;
    cin >> q;

    a[0] = 1;

    while (q--) {
        char tp;
        cin >> tp;
        if (tp == '+') {
            ll x;
            cin >> x;        
            a[x] = 1;
        }else if (tp == '-') {
            ll x;
            cin >> x;        
            a[x] = 0;
            if (s1.find(x) != s1.end()) {
                for (auto i : s1[x]) {
                    st[i].insert(x / i);
                }
                s1[x].clear();
            }
        }else {
            ll k;
            cin >> k;
            if (mp.find(k) == mp.end()) {
                mp[k] = 1;
            }
            ll t = mp[k], xx;

            while (sz(st[k])) {
                xx = *st[k].begin();
                if (a[xx * k]) {
                    st[k].erase(st[k].begin());
                    s1[xx * k].insert(k);
                }else break;
            }

            if (sz(st[k])) {
                cout << *st[k].begin() * k << "\n";
                continue;
            }
            
            while (a[t * k]) {
                s1[t * k].insert(k);
                t++;
            }
            mp[k] = t;
            cout << t * k << "\n";
        }
    }

    

    return 0;
}