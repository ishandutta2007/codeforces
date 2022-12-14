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
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN];

ll ask(ll x) {
    if (A[x] == INF) {
        cout << "? " << x << endl;
        cout.flush();
        cin >> A[x];
    }
    return A[x];
}

ll get(ll x) {
    return ask(x) - ask(x + n / 2);
}

ll cost(ll x) {
    return (A[x] == INF) + (A[x + n / 2] == INF);
}

void output(ll x) {
    cout << "! " << x << endl;
    cout.flush();
    exit(0);
}

int main() {
    fast_io;
    fill(A, A + MAXN, INF);

    cin >> n;
    if (n % 4 != 0) output(-1);

    ll l = 1, r = n / 2;
    while (l != r) {
        ll mid = (l + r) / 2;
        ll x = get(mid);
        if (x == 0) output(mid);
        if (cost(r) < cost(l)) {
            ll y = get(r);
            if (y == 0) output(r);
            if (x > 0 && y < 0 || x < 0 && y > 0) l = mid + 1;
            else r = mid - 1;
        } else {
            ll y = get(l);
            if (y == 0) output(l);
            if (x > 0 && y < 0 || x < 0 && y > 0) r = mid - 1;
            else l = mid + 1;
        }
    }
    if (get(l) == 0) output(l);
    output(-1);

    return 0;
}
/*

*/