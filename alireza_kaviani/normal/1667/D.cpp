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

int q , n , flag , col[MAXN];
vector<int> adj[MAXN] , g[MAXN][2];

void PreDFS(int v , int p = -1){
    int cnt0 = SZ(adj[v]) / 2 , cnt1 = (SZ(adj[v]) + 1) / 2;
    for(int u : adj[v]){
        if(u == p)  continue;
        PreDFS(u , v);
        if(col[u] == 0) cnt0--;
        if(col[u] == 1) cnt1--;
        g[v][col[u]].push_back(u);
    }
    if(cnt0 < 0 || cnt1 < 0){
        flag = 1;
    }
    if(cnt0 > 0)    col[v] = 0;
    if(cnt1 > 0)    col[v] = 1;
}

void SolveDFS(int v , int p = -1){
    for(int i = SZ(adj[v]) ; i >= 1 ; i--){
        int c = i % 2;
        if(SZ(g[v][c]) == 0){
            cout << v << sep << p << endl;
            continue;
        }
        int u = g[v][c].back();
        g[v][c].pop_back();
        SolveDFS(u , v);
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n; flag = 0;
        for(int i = 0 ; i <= n + 2 ; i++){
            adj[i].clear();
            g[i][0].clear();
            g[i][1].clear();
        }
        for(int i = 1 ; i < n ; i++){
            int v , u;
            cin >> v >> u;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        PreDFS(1);
        if(flag){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        SolveDFS(1);
    }

    return 0;
}
/*

*/