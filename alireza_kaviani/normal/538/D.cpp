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

const ll MAXN = 110;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;
string mp[MAXN] , ans[MAXN];
vector<pll> moves , piece;

int main() {
    fast_io;

    cin >> n;
    for(ll i = 0 ; i < n ; i++){
        cin >> mp[i];
        for(ll j = 0 ; j < n ; j++){
            if(mp[i][j] == 'o'){
                piece.push_back({i , j});
            }
        }
    }

    for(ll i = 1 - n ; i < n ; i++){
        for(ll j = 1 - n ; j < n ; j++){
            ll ok = 1;
            for(pll k : piece){
                ll x = k.X + i , y = k.Y + j;
                if(x < 0 || x >= n || y < 0 || y >= n)  continue;
                if(mp[x][y] == '.') ok = 0;
                if(mp[x][y] == 'x') ok |= 2;
            }
            if(ok == 3) moves.push_back({i , j});
        }
    }
    
    for(pll i : piece){
        for(pll j : moves){
            ll x = i.X + j.X , y = i.Y + j.Y;
            if(x < 0 || x >= n || y < 0 || y >= n)  continue;
            mp[x][y] = '.';
        }
    }
    
    for(ll i = 0 ; i < n ; i++){
        for(ll j = 0 ; j < n ; j++){
            if(mp[i][j] == 'x') return cout << "NO" << endl , 0;
        }
    }

    cout << "YES" << endl;
    fill(ans , ans + MAXN, string(2 * n - 1 , '.'));
    ans[n - 1][n - 1] = 'o';
    for(pll i : moves){
        ans[n - 1 + i.X][n - 1 + i.Y] = 'x';
    }
    for(ll i = 0 ; i < 2 * n - 1 ; i++) cout << ans[i] << endl;

    return 0;
}
/*

*/