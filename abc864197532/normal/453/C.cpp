#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
const int N = 100000;
vector <int> adj[N];
vector <int> aa;
vector <bool> vis;
vector <int> order;

void add(int n) {
    order.pb(n);
    aa[n] ^= 1;
}


void dfs(int v, int p) {
    vis[v] = true;
    add(v);
    for (int u : adj[v]) {
        if (u == p or vis[u]) continue;
        dfs(u, v);
        add(v);
    }
    if (aa[v] and p != -1) {
        add(p);
        add(v);
    }
}

int main () {
    int n, m, u, v;
    cin >> n >> m;
    aa.resize(n);
    vis.resize(n, false);
    fop (i,0,m) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int s = 0;
    fop (i,0,n) {
        cin >> aa[i];
        if (aa[i] == 1) s = i;
    }
    dfs(s, -1);
    int is = 0;
    if (aa[s]) aa[s] = 0, is = 1;
    if (count(aa.begin(), aa.end(), 1) != 0) {
        cout << -1 << endl;
    } else {
        cout << order.size() - is << endl;
        fop (i,is,order.size()) cout << order[i] + 1 << " \n"[i == order.size() - 1];
    }
}