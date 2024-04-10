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
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , k;

int main() {
    fast_io;

    cin >> n >> k;
    if(k == 2 && n > 4){
        cout << n - 1 << endl;
        for(ll i = 1 ; i < n ; i++) cout << i << sep << i + 1 << endl;
        return 0;
    }
    if(k == 3 && n >= 4){
        cout << 2 * n - 5 << endl;
        for(ll i = 3 ; i <= n ; i++)    cout << 1 << sep << i << endl;
        for(ll i = 4 ; i <= n ; i++)    cout << 2 << sep << i << endl;
        return 0;
    }
    cout << -1 << endl;

    return 0;
}
/*

*/