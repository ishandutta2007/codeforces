/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

ll n, k, ans, A[MAXN], Linv[MAXN], Rinv[MAXN];
Tree<pll> Tr1, Tr2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (ll i = 1; i <= n; i++) cin >> A[i];

    for (ll i = 1; i <= n; i++) {
        Linv[i] = Linv[i - 1] + SZ(Tr1) - ll(Tr1.order_of_key({A[i], INF}));
        Tr1.insert({A[i], i});
    }
    for (ll i = n; i >= 1; i--) {
        Rinv[i] = Rinv[i + 1] + ll(Tr2.order_of_key({A[i], -INF}));
        Tr2.insert({A[i], i});
    }
    Tr1 = Tree<pll>();
    Tr2.erase({A[1], 1});

    ll r = 2, invs = 0;
    for (ll i = 1; i <= n - 1; i++) {
        invs += Tr2.order_of_key({A[i], -INF});
        Tr1.insert({A[i], i});
        while (r <= i || r <= n && Linv[i] + Rinv[r] + invs > k) {
            invs -= SZ(Tr1) - ll(Tr1.order_of_key({A[r], INF}));
            Tr2.erase({A[r], r});
            r++;
        }
        ans += n + 1 - r;
    }
    cout << ans << endl;


    return 0;
}
/*

*/