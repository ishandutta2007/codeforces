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

int n , m , par[MAXN] , sz[MAXN] , H[MAXN] , Par[LOG][MAXN] , ps[MAXN];
vector<int> adj[MAXN];
vector<pii> E;

int Find(int v){
    return (par[v] == -1 ? v : par[v] = Find(par[v]));
}

int Union(int v , int u){
    v = Find(v); u = Find(u);
    if(v == u)  return 0;
    if(sz[v] < sz[u])   swap(u , v);
    par[u] = v;
    sz[v] += sz[u];
    return 1;
}

void DFS(int v , int p = 0){
    Par[0][v] = p;
    H[v] = H[p] + 1;
    for(int u : adj[v]){
        if(u == p)  continue;
        DFS(u , v);
    }
}

int getPar(int v , int h){
    for(int i = 0 ; i < LOG ; i++){
        if(h & (1 << i)){
            v = Par[i][v];
        }
    }
    return v;
}

int LCA(int v , int u){
    if(H[v] > H[u]) swap(v , u);
    u = getPar(u , H[u] - H[v]);
    if(v == u){
        return v;
    }
    for(int i = LOG - 1 ; i >= 0 ; i--){
        if(Par[i][v] != Par[i][u]){
            v = Par[i][v];
            u = Par[i][u];
        }
    }
    return Par[0][v];
}

void SolveDFS(int v , int p = -1){
    for(int u : adj[v]){
        if(u == p)  continue;
        ps[u] += ps[v];
        SolveDFS(u , v);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fill(sz , sz + MAXN , 1);
    fill(par , par + MAXN , -1);

    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int v , u;
        cin >> v >> u;
        if(Union(v , u)){
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        else{
            E.push_back({v , u});
        }
    }

    DFS(1);
    for(int i = 1 ; i < LOG ; i++){
        for(int j = 1 ; j <= n ; j++){
            Par[i][j] = Par[i - 1][Par[i - 1][j]];
        }
    }

    for(pii i : E){
        int v = i.X , u = i.Y;
        if(H[v] > H[u]) swap(v , u);
        int lca = LCA(v , u);
        if(lca != v){
            ps[v]++;
            ps[u]++;
        }
        else{
            ps[1]++;
            ps[getPar(u , H[u] - H[v] - 1)]--;
            ps[u]++;
        }
    }

    SolveDFS(1);
    for(int i = 1 ; i <= n ; i++){
        if(ps[i] == SZ(E)){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }

    return 0;
}
/*

*/