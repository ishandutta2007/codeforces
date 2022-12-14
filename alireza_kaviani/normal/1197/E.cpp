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

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , mn = INF , diff[MAXN];
pll ans = {0 , INF} , box[MAXN] , dp[MAXN] , ps[MAXN];


void merge(pll &A , pll B){
    if(A.Y == B.Y){
        A = {(A.X + B.X) % MOD , A.Y};
        return;
    }
    if(A.Y > B.Y){
        A = B;
        return;
    }
    return;
}

int main() {
    fast_io;

    cin >> n;
    for(ll i = 1 ; i <= n ; i++){
        cin >> box[i].Y >> box[i].X;
        mn = min(mn , box[i].Y);
    }
    box[0] = {INF , INF};
    sort(box , box + n + 1 , greater<pll>());

    ps[0] = {0 , INF};

    for(ll i = 1 ; i <= n ; i++)
        diff[i] = box[i].X - box[i].Y;

    for(ll i = 1 ; i <= n ; i++){
        ll ind = upper_bound(box , box + n + 1 , Mp(box[i].Y , -INF) , greater<pll>()) - box - 1;
        pll p = {ps[ind].X , ps[ind].Y + diff[i]};
        if(ind == 0){
            dp[i] = {1 , box[i].X};
        }
        else{
            dp[i] = p;
        }
        ps[i] = ps[i - 1];
        merge(ps[i] , dp[i]);
    }

    for(ll i = 1 ; i <= n ; i++){
        if(box[i].X < mn){
            merge(ans , dp[i]);
        }
    }
    cout << ans.X << endl;

    return 0;
}
/*

*/