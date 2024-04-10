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

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8.5e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , A = 1 , B , C , mn = INF , x[MAXN] , y[MAXN];
pair<ll , ll> p[MAXN];

ll dist(ll i , ll j){
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() {
    fast_io;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++){
        cin >> x[i] >> y[i];
        p[i] = {dist(i , 1) , i};
    }
    sort(p + 2 , p + n + 1);
    B = p[2].Y;

    for(ll i = 1 ; i <= n ; i++){
        ll ang = abs((x[B] - x[A]) * (y[i] - y[A]) - (x[i] - x[A]) * (y[B] - y[A]));
        if(ang != 0){
            if(ang < mn){
                mn = ang;
                C = i;
            }
        }
    }
    cout << A << sep << B << sep << C << endl;

    return 0;
}
/*

*/