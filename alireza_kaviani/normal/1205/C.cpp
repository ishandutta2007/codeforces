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

const ll MAXN = 60;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , ans[MAXN][MAXN];

ll query(ll x1 , ll y1 , ll x2 , ll y2){
    ll x;
    cout << "? " << x1 << sep << y1 << sep << x2 << sep << y2 << endl;
    cout.flush();
    cin >> x;
    return x;
}

void rev(){
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= n ; j++){
            if((i + j) % 2 == 1){
                ans[i][j] = 1 - ans[i][j];
            }
        }
    }
}

void print(){
    cout << "!" << endl;
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= n ; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
    cout.flush();
    exit(0);
}

int main() {
    fast_io;
    for(ll i = 0 ; i < MAXN ; i++){
        for(ll j = 0 ; j < MAXN ; j++)  ans[i][j] = -1;
    }

    cin >> n;

    ans[1][1] = 1;
    ans[1][2] = 1;
    ans[2][1] = 1;
    ans[n][n] = 0;

    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= n ; j++){
            if(ans[i][j] == -1){
                if(i >= 2 && j >= 2)
                    ans[i][j] = (query(i - 1 , j - 1 , i , j) == 1 ? ans[i - 1][j - 1] : 1 - ans[i - 1][j - 1]);
                if(i == 1){
                    ans[i][j] = (query(i , j - 2 , i , j) == 1 ? ans[i][j - 2] : 1 - ans[i][j - 2]);
                }
                if(j == 1){
                    ans[i][j] = (query(i - 2 , j , i , j) == 1 ? ans[i - 2][j] : 1 - ans[i - 2][j]);
                }
            }
        }
        if(i == 2){
            ans[2][1] = (query(2 , 1 , 2 , 3) == 1 ? ans[2][3] : 1 - ans[2][3]);
        }
    }

    for(ll i = 1 ; i + 1 <= n ; i++){
        for(ll j = 1 ; j + 2 <= n ; j++){
            if(ans[i][j + 1] != ans[i + 1][j] || ans[i][j + 2] != ans[i + 1][j + 1] || ans[i][j] != ans[i + 1][j + 2] && ans[i][j + 1] != ans[i][j + 2] || ans[i][j] == ans[i + 1][j + 2] && ans[i][j + 1] == ans[i][j + 2]){
                ll x = query(i , j , i + 1 , j + 2);
                if(x == 1 && ans[i][j] != ans[i + 1][j + 2] || x == 0 && ans[i][j] == ans[i + 1][j + 2]) rev();
                print();
            }
        }
    }

    return 0;
}
/*

*/