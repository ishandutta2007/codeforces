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

ll q, n, B[MAXN], col[MAXN], L[20], R[20];
string s;

ll MAIN() {
    cin >> n >> s;
    fill(B, B + n + 10, 0);
    fill(col, col + n + 10, 0);
    for (ll i = 0; i < 20; i++) L[i] = INF, R[i] = -INF;

    for (ll i = 0; i < n; i++) B[i] = s[i] - 48;
    for (ll i = 0; i < n; i++) {
        L[B[i]] = min(L[B[i]], i);
        R[B[i]] = i;
    }

    ll ind = 0;
    for (ll i = 1; i < 10; i++) {
        if (L[i] == INF || L[i] > R[i - 1]) ind++, R[i] = max(R[i], R[i - 1]);
        else break;
    }

    vector<ll> vec;
    for (ll i = 0; i < n; i++) {
        if (B[i] <= ind) col[i] = 1;
        else if (B[i] == ind + 1 && i >= R[ind]) col[i] = 1;
        else col[i] = 2, vec.push_back(B[i]);
    }
    for (ll i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) return cout << "-" << endl, 0;
    }
    for (ll i = 0; i < n; i++) cout << col[i];
    cout << endl;
}

int main() {
    fast_io;

    cin >> q;
    while (q--) MAIN();

    return 0;
}
/*

*/