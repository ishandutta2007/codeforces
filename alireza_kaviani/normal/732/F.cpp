#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , m , ans , root , par[MAXN] , sz[MAXN] , mark[MAXN] , mn[MAXN] , H[MAXN];
pii E[MAXN];
vector<pii> adj[MAXN];

int Find(int v){
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

void Union(int v , int u){
    v = Find(v); u = Find(u);
    if(v == u)  return;
    if(sz[v] < sz[u])   swap(v , u);
    par[u] = v;
    sz[v] += sz[u];
}

void PreDFS(int v , int p = -1){
    mn[v] = MOD;
    mark[v] = 1;
    for(pii i : adj[v]){
        int u = i.X;
        if(mark[u]){
            if(u != p){
                mn[v] = min(mn[v] , H[u]);
            }
            continue;
        }
        H[u] = H[v] + 1;
        PreDFS(u , v);
        if(mn[u] <= H[v]){
            Union(v , u);
        }
        mn[v] = min(mn[v] , mn[u]);
    }
}

void SolveDFS(int v , int p = -1){
    mark[v] = 1;
    for(pii i : adj[v]){
        int u = i.X , ind = i.Y;
        if(mark[u]){
            if(u != p){
                E[ind] = {v , u};
            }
            continue;
        }
        SolveDFS(u , v);
        E[ind] = {u , v};
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(par , par + MAXN , -1);
    fill(sz , sz + MAXN , 1);

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        adj[v].push_back({u , i});
        adj[u].push_back({v , i});
    }
    PreDFS(1);
    for(int i = 1 ; i <= n ; i++){
        if(Find(i) == i){
            if(sz[i] > ans){
                ans = sz[i];
                root = i;
            }
        }
    }
    fill(mark , mark + MAXN , 0);
    SolveDFS(root);
    cout << ans << endl;
    for(int i = 0 ; i < m ; i++){
        cout << E[i].X << sep << E[i].Y << endl;
    }

    return 0;
}
/*

*/