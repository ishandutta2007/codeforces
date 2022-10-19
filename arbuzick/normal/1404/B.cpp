#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
vector<vector<int>> g;
int bfs(int n, int s, int t = -1, bool d = 0){
    vector<int> dist(n, n+1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u: g[v])
            if(dist[u] > dist[v]+1)
                dist[u] = dist[v]+1, q.push(u);
    }
    if(t > -1)
        return dist[t];
    int v = 0;
    for(int i = 0; i < n; ++i)
        if(dist[i] > dist[v])
            v = i;
    if(d)
        return dist[v];
    return v;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        a--, b--;
        g.clear();
        g.resize(n);
        for(int i = 0; i < n-1; ++i){
            int v, u;
            cin >> v >> u;
            v--, u--;
            g[v].pb(u);
            g[u].pb(v);
        }
        if(bfs(n, a, b) <= da){
            cout << "Alice\n";
            continue;
        }
        if(da*2 >= bfs(n, bfs(n, 0), -1, 1)){
            cout << "Alice\n";
            continue;
        }
        if(db > da*2)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
    return 0;
}