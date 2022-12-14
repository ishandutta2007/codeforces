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

ll ask(ll a, ll b) {
    ll x;
    cout << "? " << a << " " << b << endl;
    cin >> x;
    return x;
}

void solve() {
    ll n;
    cin >> n;
    vector <ll> v;
    for (int i = 1; i <= pw(n); i++) {
        v.p_b(i);
    }
    while (sz(v) > 1) {
        if (sz(v) == 2) {
            ll x;
            if (ask(v[0], v[1]) == 1) {
                x = v[0];
            }else {
                x = v[1];
            }
            v.clear();
            v.p_b(x);
        }else {
            vector <ll> tb;
            for (int i = 0; i < sz(v); i += 4) {
                ll a, b, c, d;
                a = v[i];
                b = v[i + 1];
                c = v[i + 2];
                d = v[i + 3];
                ll t = ask(a, c);
                if (t == 0) {
                    if (ask(b, d) == 1) {
                        tb.p_b(b);
                    }else {
                        tb.p_b(d);
                    }
                } else if (t == 1) {
                    if (ask(a, d) == 1) {
                        tb.p_b(a);
                    }else {
                        tb.p_b(d);
                    }
                }else {
                    if (ask(b, c) == 1) {
                        tb.p_b(b);
                    }else {
                        tb.p_b(c);
                    }
                }
            }
            v.clear();
            for (auto i : tb) {
                v.p_b(i);
            }
        }
    }
    cout << "! " << v.back() << endl;
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