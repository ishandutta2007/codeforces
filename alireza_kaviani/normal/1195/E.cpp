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

const ll MAXN = 3e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , a , b , last , x , y , z , ans , mat[MAXN][MAXN] , mn[MAXN][MAXN];
deque<ll> mnx[MAXN] , mny[MAXN];

int main(){
    fast_io;

    cin >> n >> m >> a >> b >> last >> x >> y >> z;
    for(ll i = 0 ; i < MAXN ; i++)  mat[0][i] = mat[i][0] = -1;
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= m ; j++){
            mat[i][j] = last;
            last = (last * x + y) % z;
        }
    }

    for(ll i = 1 ; i <= n ; i++){
        mnx[i].push_back(0);
        for(ll j = 1 ; j <= m ; j++){
            while(mnx[i].size() > 0 && mnx[i].front() <= j - b) mnx[i].pop_front();
            while(mnx[i].size() > 0 && mat[i][mnx[i].back()] >= mat[i][j])  mnx[i].pop_back();
            mnx[i].push_back(j);

            if(j >= b){
                mn[i][j - b] = mat[i][mnx[i].front()];
            }
        }
        mnx[i] = deque<ll>();
    }

    for(ll i = 0 ; i < m - b + 1 ; i++){
        mny[i].push_back(0);
        for(ll j = 1 ; j <= n ; j++){
            while(mny[i].size() > 0 && mny[i].front() <= j - a) mny[i].pop_front();
            while(mny[i].size() > 0 && mn[mny[i].back()][i] >= mn[j][i])    mny[i].pop_back();
            mny[i].push_back(j);

            if(j >= a){
                ans += mn[mny[i].front()][i];
            }
        }
    }
    cout << ans << endl;

    return 0;
}