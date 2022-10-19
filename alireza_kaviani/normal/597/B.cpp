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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , L[MAXN] , R[MAXN] , dp[MAXN];
vector<ll> Q[MAXN];
vector<ll> vec;

void compress(){
    Sort(vec);
    vec.resize(unique(all(vec)) - vec.begin());
    for(ll i = 0 ; i < n ; i++){
        L[i] = lower_bound(all(vec) , L[i]) - vec.begin() + 1;
        R[i] = lower_bound(all(vec) , R[i]) - vec.begin() + 1;
    }
}

int main() {
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++){
        cin >> L[i] >> R[i];
        vec.push_back(L[i]);
        vec.push_back(R[i]);
    }
    compress();

    for(ll i = 0 ; i < n ; i++){
        Q[R[i]].push_back(L[i]);
    }

    for(ll i = 1 ; i < MAXN ; i++){
        dp[i] = dp[i - 1];
        for(ll j : Q[i]){
            dp[i] = max(dp[i] , dp[j - 1] + 1);
        }
    }
    cout << dp[MAXN - 1] << endl;

    return 0;
}
/*

*/