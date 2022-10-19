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

const ll MAXN = 500 + 10;
const ll LOG = 22;
const ll INF = 2e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , m , dist[2][MAXN][MAXN];
pair<pair<int , int> , int> par[2][MAXN][MAXN];
vector<int> adj[MAXN];
vector<int> v1 , v2;

void BFS(int x , int y , int z){
    for(int i = 0 ; i < MAXN ; i++)  for(int j = 0 ; j < MAXN ; j++)  dist[0][i][j] = dist[1][i][j] = INF;
    queue<int> q;
    q.push(x) ; q.push(y) ; q.push(z);
    dist[z][x][y] = 0;

    while(!q.empty()){
        int x = q.front() ; q.pop();
        int y = q.front() ; q.pop();
        int z = q.front() ; q.pop();
        if(z == 0) {
            for (int i : adj[x]) {
                int nx = i;
                if (dist[z ^ 1][nx][y] == INF) {
                    dist[z ^ 1][nx][y] = dist[z][x][y] + 1;
                    par[z ^ 1][nx][y] = {{x, y}, z};
                    q.push(nx);
                    q.push(y);
                    q.push(z ^ 1);
                }
            }
        }
        if(z == 1){
            for (int i : adj[y]) {
                if(i == x) continue;
                int ny = i;
                if (dist[z ^ 1][x][ny] == INF) {
                    dist[z ^ 1][x][ny] = dist[z][x][y] + 1;
                    par[z ^ 1][x][ny] = {{x, y}, z};
                    q.push(x);
                    q.push(ny);
                    q.push(z ^ 1);
                }
            }
        }
    }
}

int main() {
    fast_io;

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    BFS(1 , n , 0);
    if(dist[0][n][1] == INF)    return cout << -1 << endl , 0;
    cout << dist[0][n][1] / 2 << endl;
    
    int x = n , y = 1 , z = 0;
    while(x != 1 || y != n){
        v1.push_back(x);
        v2.push_back(y);
        pair<pair<int , int> , int> A = par[z][x][y];
        x = A.X.X , y = A.X.Y , z = A.Y;
        A = par[z][x][y];
        x = A.X.X , y = A.X.Y , z = A.Y;
    }
    v1.push_back(1);
    v2.push_back(n);
    reverse(all(v1)) ; reverse(all(v2));
    for(int i : v1)  cout << i << sep;
    cout << endl;
    for(int i : v2)  cout << i << sep;

    return 0;
}
/*

*/