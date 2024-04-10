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

const ll MAXN = 100 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n , k , A[MAXN] , cnt[MAXN] , C[MAXN][MAXN] , dist[2][MAXN][MAXN] , dp[2][MAXN][MAXN];

void BFS(ll x , ll y){
    queue<ll> q;
    dist[0][x][y] = 0;
    dp[0][x][y] = 1;
    q.push(x);
    q.push(y);
    q.push(0);

    while(!q.empty()){
        ll x = q.front() ; q.pop();
        ll y = q.front() ; q.pop();
        ll z = q.front() ; q.pop();
        if(z == 0){
            for(ll i = 0 ; i <= x ; i++){
                for(ll j = 0 ; j <= y ; j++){
                    if(i == 0 && j == 0) continue;
                    if(i * 50 + j * 100 > k) break;
                    if(dist[1][x - i][y - j] == INF){
                        dist[1][x - i][y - j] = dist[0][x][y] + 1;
                        q.push(x - i);
                        q.push(y - j);
                        q.push(1);
                    }
                    if(dist[1][x - i][y - j] == dist[0][x][y] + 1){
                        dp[1][x - i][y - j] += dp[0][x][y] * C[i][x] % MOD * C[j][y] % MOD;
                        dp[1][x - i][y - j] %= MOD;
                    }
                }
            }
        }
        if(z == 1){
            for(ll i = 0 ; i <= cnt[50] - x ; i++){
                for(ll j = 0 ; j <= cnt[100] - y ; j++){
                    if(i == 0 && j == 0) continue;
                    if(i * 50 + j * 100 > k) break;
                    if(dist[0][x + i][y + j] == INF){
                        dist[0][x + i][y + j] = dist[1][x][y] + 1;
                        q.push(x + i);
                        q.push(y + j);
                        q.push(0);
                    }
                    if(dist[0][x + i][y + j] == dist[1][x][y] + 1){
                        dp[0][x + i][y + j] += dp[1][x][y] * C[i][cnt[50] - x] % MOD * C[j][cnt[100] - y] % MOD;
                        dp[0][x + i][y + j] %= MOD;
                    }
                }
            }
        }
    }
}

int main() {
    fast_io;
    for(ll i = 0 ; i < MAXN ; i++)  for(ll j = 0 ; j < MAXN ; j++)  dist[0][i][j] = dist[1][i][j] = INF;

    for(ll i = 0 ; i < MAXN ; i++)  C[0][i] = 1;
    for(ll i = 1 ; i < MAXN ; i++){
        for(ll j = 1 ; j < MAXN ; j++){
            C[i][j] = (C[i - 1][j - 1] + C[i][j - 1]) % MOD;
        }
    }

    cin >> n >> k;
    for(ll i = 0 ; i < n ; i++) cin >> A[i] , cnt[A[i]]++;

    BFS(cnt[50] , cnt[100]);
    cout << (dist[1][0][0] == INF ? -1 : dist[1][0][0]) << endl << dp[1][0][0];

    return 0;
}
/*

*/