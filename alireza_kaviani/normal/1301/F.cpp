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
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e3 + 10;
const ll MAXK = 42;
const ll LOG = 22;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

template<class T , int SZ>
struct FastDeque{
    T Q[SZ * 2 + 10];
    int l = SZ , r = SZ;
    void push_back(T x)     {Q[r++] = x;}
    void push_front(T x)    {Q[--l] = x;}
    void pop_front()    {l++;}
    void pop_back()     {r--;}
    T front()   {return Q[l];}
    T back()    {return Q[r - 1];}
    void clear()    {l = r = SZ;}
    bool empty()    {return (l == r);}
};

ll n , m , k , col[MAXN][MAXN];
int dist[MAXK][MAXN][MAXN] , dx[4] = {1 , -1 , 0 , 0} , dy[4] = {0 , 0 , 1 , -1};
vector<pair<int , int>> adj[MAXN];
FastDeque<pair<int , int> , MAXN * MAXN> dq;

void BFS(ll root){
    for(ll i = 0 ; i <= n ; i++)    for(ll j = 0 ; j < MAXN ; j++)  dist[root][i][j] = INF;
    dist[root][0][root] = -1;
    dq.clear();
    dq.push_back({0 , root});

    while(!dq.empty()){
        pll A = dq.front(); dq.pop_front();
        ll x = A.X , y = A.Y;
        if(x == 0){
            for(pll j : adj[y]){
                ll nx = j.X , ny = j.Y;
                if(dist[root][nx][ny] == INF){
                    dist[root][nx][ny] = dist[root][x][y] + 1;
                    dq.push_back({nx , ny});
                }
            }
        }
        else{
            if(dist[root][0][col[x][y]] > dist[root][x][y]){
                dist[root][0][col[x][y]] = dist[root][x][y];
                dq.push_front({0 , col[x][y]});
            }
            for(ll i = 0 ; i < 4 ; i++) {
                ll nx = x + dx[i], ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (dist[root][nx][ny] == INF) {
                    dist[root][nx][ny] = dist[root][x][y] + 1;
                    dq.push_back({nx , ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for(ll i = 1 ; i <= n ; i++){
        for(ll j = 1 ; j <= m ; j++){
            cin >> col[i][j];
            adj[col[i][j]].push_back({i , j});
        }
    }

    for(ll i = 1 ; i <= k ; i++)    BFS(i);

    /*for(ll i = 1 ; i <= k ; i++){
        cout << i << endl;
        for(ll j = 1 ; j <= n ; j++){
            for(ll k = 1 ; k <= m ; k++){
                cout << dist[i][j][k] << sep;
            }
            cout << endl;
        }
        cout << endl;
    }*/

    ll q;
    cin >> q;
    while(q--){
        int r1 , c1 , r2 , c2 , ans;
        cin >> r1 >> c1 >> r2 >> c2;
        ans = abs(r1 - r2) + abs(c1 - c2);
        for(ll i = 1 ; i <= k ; i++)    ans = min(ans , dist[i][r1][c1] + dist[i][r2][c2] + 1);
        cout << ans << endl;
    }

    return 0;
}
/*

*/