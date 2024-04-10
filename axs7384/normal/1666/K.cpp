#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 100001;
const ll inf = 1000000000ll * 2000;
struct edge { int v, p; ll c; };
vector<edge> g[N]; int n;
int dis[N], cur[N];
 
void adde(int u, int v, ll c) {
    // cout<<u<<' '<<v<<' '<<c<<endl;
    g[u].push_back({ v, (int)g[v].size(), c });
    g[v].push_back({ u, (int)g[u].size() - 1, 0});
}
 
bool bfs(int s, int t) {
    fill_n(dis, n, INT_MAX);
    queue<int> q; q.push(t); dis[t] = 0;
    while (!q.empty() ){
        int u = q.front(); q.pop();
        for (const edge& e : g[u]) {
            int v = e.v;
            if (dis[v] != INT_MAX || !g[e.v][e.p].c)
                continue;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    // cout<<s<<' '<<t<<':';
    // for (int i=1;i<n;++i)
    //     cout<<dis[i]<<' ';cout<<endl;
    return dis[s] != INT_MAX;
}
 
ll dfs(int u, int t, ll f) {
    if (u == t) return f;
    ll sf = 0;
    for (int& i = cur[u]; i != g[u].size(); ++i) {
        edge& e = g[u][i];
        int v = e.v;
        if (!e.c || dis[v] + 1 != dis[u]) continue;
        ll df = dfs(v, t, min(e.c, f));
        sf += df; f -= df; e.c -= df; g[v][e.p].c += df;
        if (!f) break;
    }
    return sf;
}
 
ll maxflow(int s, int t, ll mf) {
    ll sf = 0;
    // cout<<"!"<<s<<' '<<t<<endl;
    while (bfs(s, t)) {
        fill_n(cur, n, 0);
        ll f = dfs(s, t, mf);
        sf += f;
        mf -= f;
        if (!mf) break;
    }
    return sf;
}
 
int main(void) {
    // typedef pair<int, int> pii;
    // typedef pair<int, pii> piii;
    int nn, mm; scanf("%d %d", &nn, &mm);
    // vector<piii>
    int s, t; scanf("%d %d", &s, &t);
    n = nn * 2 + 3;
    for (int i = 1; i <= mm; ++i) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        adde(u, nn + v, d);
        adde(v+nn,u,d);
        adde(u+nn,v,d);
        adde(v, nn + u, d);
        // cout<<u<<' '<<nn+v<<endl<<v<<' '<<u+nn<<endl;
    }
    //A s t
    //B t s
    //C s s
    adde(n-2,s,inf);
    adde(s+nn,n-1,inf);
    adde(n-2,t+nn,inf);
    adde(t,n-1,inf);
    ll ans = maxflow(n-2, n-1, LLONG_MAX);
    bfs(n-2,n-1);
    string ss;
    for (int i = 1; i <= nn; ++i) {
        bool f1 = dis[i] != INT_MAX;//t
        bool f2 = dis[nn + i] != INT_MAX;
        // if (f1 && f2)
        //     ss.push_back('B');
        // else if (!f1 && !f2)
        //     ss.push_back('A');
        // else 
        //     ss.push_back('C');
        if (f1==f2)
            ss.push_back('C');
        else
            ss.push_back(f1?'B':'A');
    }
    cout << ans << endl << ss << endl;
    
    return 0;
}