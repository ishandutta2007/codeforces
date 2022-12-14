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

void solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a * 2 <= c && b * 2 <= d) {
        cout << a * 2 << " " << b * 2 << "\n";
        return;
    }

    vector <ll> va, vb;

    for (ll x = 1; x * x <= a; x++) if (a % x == 0) {
        va.p_b(x);
        if (x * x != a) va.p_b(a / x);
    }

    for (ll x = 1; x * x <= b; x++) if (b % x == 0) {
        vb.p_b(x);
        if (x * x != b) vb.p_b(b / x);
    }

    sort(all(va));
    sort(all(vb));

    ll x, y;

    for (auto i : va)
        for (auto j : vb) {
            x = (a / i) * j;
            y = (b / j) * i;            
            x *= a / x + 1;
            y *= b / y + 1;
            if (x <= c && y <= d) {
                cout << x << ' ' << y << "\n";
                return;
            }
        }

    
    
    cout << "-1 -1\n";
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