#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 200005;

int n, m;
vector<int> g[N];
int pre[N], d[N];
bool check[N];
int p[N];
int k;
int s, t;
set<int> adj[N];

void dijkstra(int u) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, u});
    d[u] = 0;
    while (!pq.empty()) {
        auto foo = pq.top();
        pq.pop();
        int v = foo.y;
        int dis = foo.x;
        if (check[v]) continue;
        check[v] = 1;
        for (int e : g[v]) {
            if (d[e] > dis + 1) {
                d[e] = dis + 1;
                pq.push({dis + 1, e});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) d[i] = 1e9;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[v].pb(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> p[i];
    }
    s = p[1]; t = p[k];
    dijkstra(t);
    for (int i = 1; i <= n; i++) {
        for (int e : g[i]) {
            if (d[e] == d[i] + 1) adj[e].insert(i);
        }
    }
    int mn = 0, mx = 0;
    for (int i = 2; i < k; i++) {
        // cout << p[i] << ' ' << p[i - 1] << ' ' << d[p[i]] << ' ' << d[p[i - 1]] << endl;
        if (d[p[i]] != d[p[i - 1]] - 1) mn++, mx++;
        else if (adj[p[i - 1]].size() > 1) mx++;
    }
    cout << mn << ' ' << mx;
    return 0;
}