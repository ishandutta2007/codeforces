#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100 * 1000 + 5, INF = 2000 * 1000 * 1000 + 5;
int d[MAXN];
vector<int> t[MAXN];
vector<int> nxt[MAXN];
vector< pair<int, int> > g[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--;
        u--;
        g[v].push_back(make_pair(u, w));
        g[u].push_back(make_pair(v, w));
    }
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        t[i].resize(k);
        for(int j = 0; j < k; j++)
            cin >> t[i][j];
    }
    for(int i = 0; i < n; i++) {
        nxt[i].resize(t[i].size());
        for(int j = (int)t[i].size() - 1; j >= 0; j--)
            nxt[i][j] = ((j == (int)t[i].size() - 1 ||
                          t[i][j] + 1 != t[i][j + 1])?
                         t[i][j] + 1 : nxt[i][j + 1]);
    }
    for(int i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;
    int p = 0;
    while(p < (int)t[0].size() && t[0][p] == d[0]) {
        d[0]++;
        p++;
    }
    priority_queue< pair<int, int>, vector< pair<int, int> >,
                    greater< pair<int, int> > > pq;
    pq.push(make_pair(d[0], 0));
    while(!pq.empty()) {
        int v = pq.top().second;
        if(pq.top().first != d[v]) {
            pq.pop();
            continue;
        }
        pq.pop();
        for(size_t i = 0; i < g[v].size(); i++) {
            int u = g[v][i].first, w = g[v][i].second, tt = d[v] + w,
                pos = lower_bound(t[u].begin(), t[u].end(), tt) - t[u].begin();
            if(u != n - 1 && pos < (int)t[u].size() && t[u][pos] == tt)
                tt = nxt[u][pos];
            if(tt < d[u]) {
                d[u] = tt;
                pq.push(make_pair(d[u], u));
            }
        }
    }
    if(d[n - 1] >= INF)
        cout << -1 << '\n';
    else
        cout << d[n - 1] << '\n';
    return 0;
}