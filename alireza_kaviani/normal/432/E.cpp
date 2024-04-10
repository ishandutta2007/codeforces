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

const ll MAXN = 1e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , m , A[MAXN][MAXN];

int main() {
    fast_io;
    //freopen("output.txt" , "w" , stdout);

    cin >> n >> m;
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= m ; j++){
            if(A[i][j] != 0)    continue;
            for(ll k = 1 ; k <= 26 ; k++){
                if(k != A[i - 1][j] && k != A[i][j - 1] && k != A[i][j + 1] && k != A[i + 1][j]){
                    A[i][j] = k;
                    break;
                }
                if(k == A[i - 1][j - 1])    continue;
                if(k == A[i - 1][j]){
                    ll L = i - 1;
                    for(ll l = i - 1 ; l >= 1 ; l--){
                        if(A[l][j] == k){
                            L = l;
                        }
                        else    break;
                    }
                    if(j + i - L > m)   continue;
                    ll ok = 1;
                    for(ll l = j ; l <= j + i - L ; l++)
                        if(A[i][l] != 0)    ok = 0;
                    for(ll l = L ; l <= i ; l++)
                        if(A[l][j + i - L] != 0)    ok = 0;

                    if(ok == 0) continue;
                    for(ll l = j ; l <= j + i - L ; l++)    A[i][l] = k;
                    for(ll l = L ; l <= i ; l++)    A[l][j + i - L] = k;
                    break;
                }
                if(k == A[i][j - 1]){
                    ll L = j - 1;
                    for(ll l = j - 1 ; l >= 1 ; l--){
                        if(A[i][l] == k){
                            L = l;
                        }
                        else    break;
                    }
                    if(i + j - L > n)   continue;
                    for(ll l = i ; l <= i + j - L ; l++)    A[l][j] = k;
                    for(ll l = L ; l <= j ; l++)    A[i + j - L][l] = k;
                    break;
                }
            }
        }
    }

    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= m ; j++){
            cout << char(64 + A[i][j]);
        }
        cout << endl;
    }

    return 0;
}
/*

*/