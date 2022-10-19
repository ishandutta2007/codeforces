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

set_random;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , l , r , A[MAXN] , B[MAXN];
vector<ll> cnt(40 , 0);

ll check(ll x){
    vector<ll> c = cnt;

    for(ll i = 39 ; i > B[x] ; i--){
        c[i - 1] += c[i] * 2;
        c[i] = 0;
    }

    for(ll i = x ; i >= 0 ; i--){
        c[B[i]] += c[B[i] + 1] * 2;
        c[B[i] + 1] = 0;

        if(c[B[i]] == 0)  return 0;
        c[B[i]]--;
    }
    return 1;
}

int main() {
    fast_io;

    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++){
        cin >> A[i];
        for(ll j = 0 ; j < 40 ; j++){
            cnt[j] += ((A[i] & (1LL << j)) != 0);
        }
    }
    for(ll i = 0 ; i < m ; i++) cin >> B[i];
    sort(B , B + m);

    ll l = -1 , r = m;
    while(r - l > 1){
        ll mid = (l + r) / 2;
        if(check(mid))  l = mid;
        else    r = mid;
    }
    cout << l + 1 << endl;


    return 0;
}
/*

*/