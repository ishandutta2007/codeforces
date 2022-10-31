#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define ll long long
#define int long long


struct Edge{
    int to, w, idx;
};

vector <vector <Edge>> gr;
vector <int> dist;
vector <int> par;
vector <int> ans;
int n, k;

void dijkstra() {
    dist.resize(n, 1e18);
    dist[0] = 1LL * 0;
    set <pii> s;
    s.insert({0, 0});
    par.resize(n, -1);
    forn (i, 0, min(n, k + 1)) {
        pii v = *s.begin();
        //cout << v.sc << " ";
        s.erase(v);
        ans.push_back(par[v.sc]);
        forn(u, 0, gr[v.sc].size()) {
            if (dist[gr[v.sc][u].to] > v.fs + gr[v.sc][u].w) {
                s.erase({dist[gr[v.sc][u].to], gr[v.sc][u].to});
                par[gr[v.sc][u].to] = gr[v.sc][u].idx;
                dist[gr[v.sc][u].to] = v.fs + gr[v.sc][u].w;
                s.insert({dist[gr[v.sc][u].to], gr[v.sc][u].to});
            }
        }
    }
}

signed main()
{
    //ios_base::sync_with_stdio(0), cin.tie(0);
    int m;
    cin >> n >> m >> k;
    gr.resize(n);
    forn (i, 1, m + 1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        Edge t;
        t.to = b, t.w = c, t.idx = i;
        gr[a].push_back(t);
        t.to = a;
        gr[b].push_back(t);
    }
    dijkstra();
    cout << ans.size() - 1<< "\n";
    for (int i = 1; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}