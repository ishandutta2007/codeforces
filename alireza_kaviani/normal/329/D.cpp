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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , x;

int main() {
    fast_io;

    cin >> n >> x;
    if(n == 5){
        return cout << ">...v\n"
                       "v.<..\n"
                       "..^..\n"
                       ">....\n"
                       "..^.<\n"
                       "1 1" << endl , 0;
    }
    if(n == 3){
        return cout << ">vv\n"
                       "^<.\n"
                       "^.<\n"
                       "1 3" << endl , 0;
    }

    for(ll i = 0 ; i < 50 ; i++){
        cout << "v.";
        for(ll j = 0 ; j < 24 ; j++){
            cout << "<.";
        }
        cout << string(50 , '<') << endl;
        cout << string(50 , '>');
        for(ll j = 0 ; j < 24 ; j++){
            cout << ".>";
        }
        cout << ".^" << endl;
    }
    cout << 1 << sep << 1 << endl;

    return 0;
}
/*

*/