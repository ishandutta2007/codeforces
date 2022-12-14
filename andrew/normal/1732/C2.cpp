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


ll pref[N], _xor[N];

ll get(ll l, ll r) {
    return (pref[r] - pref[l - 1]) - (_xor[r] ^ _xor[l - 1]);
}

bool u(ll &a, ll b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

void solve() {
    ll n, q;
    cin >> n >> q;

    vector <ll> a(n + 1), pos;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) pos.p_b(i);
        pref[i] = pref[i - 1] + a[i];
        _xor[i] = _xor[i - 1] ^ a[i];
    }

    vector <ll> :: iterator it;

    while (q--) {
        int l, r;
        cin >> l >> r;        
        ll ans = 0;
        ll le = l, ri = l;

        vector <ll> rofl;

        ll con = 35;

        it = lower_bound(all(pos), l);
        while (it != pos.end() && *it <= r && con > 0) {
            con--;
            rofl.p_b(*it);
            it++;
        }

        con = 35;
        it = upper_bound(all(pos), r);

        while (true) {
            if (con == 0 || it == pos.begin()) break;
            con--;
            --it;
            if (*it < l) break;
            rofl.p_b(*it);
        }

        sort(all(rofl));
        rofl.erase(unique(all(rofl)), rofl.end());

        for (int j : rofl) {
            for (int i : rofl) if (i < j){
                if (u(ans, get(i, j)) || (ans == get(i, j) && j - i + 1 < ri - le + 1)) {
                    le = i, ri = j;
                }
            }
        }

        cout << le << " " << ri << "\n";
    }    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;

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