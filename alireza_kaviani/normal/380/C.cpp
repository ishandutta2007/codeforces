#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , q , ps[MAXN] , mn[LOG][MAXN] , lg[MAXN];
string s;

ll getMin(ll l , ll r){
    ll sz = r - l + 1;
    return min(mn[lg[sz]][l] , mn[lg[sz]][r - (1ll << lg[sz]) + 1]);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    for(ll i = 2 ; i < MAXN ; i++)  lg[i] = lg[i / 2] + 1;
    cin >> s >> q;
    n = s.size();
    s = "." + s;
    for(ll i = 1 ; i <= n ; i++)    mn[0][i] = ps[i] = ps[i - 1] + (s[i] == '(' ? 1 : -1);
    for(ll i = 1 ; i < LOG ; i++){
        for(ll j = 0 ; j + (1ll << (i - 1)) < MAXN ; j++){
            mn[i][j] = min(mn[i - 1][j] , mn[i - 1][j + (1LL << (i - 1))]);
        }
    }

    while(q--){
        ll l , r;
        cin >> l >> r;
        ll mn = getMin(l , r);
        cout << r - l + 1 - ps[l - 1] - ps[r] + min(ps[l - 1] , mn) * 2 << endl;
    }

    return 0;
}
/*

*/