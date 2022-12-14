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
// const int N = 3e5;
const int inf = 1e9;
template <typename T> void vout(T s){cout << s << endl;exit(0);}

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    ll n, q;
    cin >> n >> q;
    map <ll, ll> v[2];
    ll s[2] = {0, 0};

    vector <ll> a(n);

    ll sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        v[a[i] % 2][i] = 1;
    }
    while (q--) {        
        ll tp, val;
        cin >> tp >> val;
        if (tp == 0) {
            sum += val * (ll)v[0].size();
            if (val % 2 == 0) {
                s[0] += val;
            }else {
                if (v[1].size() == 0) {
                    swap(s[0], s[1]);
                    swap(v[0], v[1]);
                    s[1] += val;                    
                }else {
                    s[0] += val;
                    for (auto i : v[0]) {
                        a[i.fi] += s[0];
                        a[i.fi] -= s[1];
                        v[1][i.fi] = 1;
                    }
                    s[0] = 0;
                    v[0].clear();
                }
            }
        }else {
            sum += val * (ll)v[1].size();
            if (val % 2 == 0) {
                s[1] += val;
            }else {
                if (v[0].size() == 0) {
                    swap(s[0], s[1]);
                    swap(v[0], v[1]);
                    s[0] += val;                    
                }else {
                    s[1] += val;
                    for (auto i : v[1]) {
                        a[i.fi] += s[1];
                        a[i.fi] -= s[0];
                        v[0][i.fi] = 1;
                    }
                    s[1] = 0;
                    v[1].clear();
                }
            }
        }
        cout << sum << "\n";
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif    

    cin >> t;    

    while (t--) {
        solve();
    }

    return 0;
}