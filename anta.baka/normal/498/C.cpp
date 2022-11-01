#include <bits/stdc++.h>

using namespace std;

struct edge {
    int v, c, f, rev;
};

int n, m;
int x[100], y[100];
int V;
int s, t;
vector<vector<edge>> g;
vector<int> d;
vector<int> first;
map<int, int> cnt[100];
int ans;

bool bfs() {
    d.assign(V, -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(edge e : g[v])
            if(d[e.v] == -1 && e.c - e.f > 0) {
                d[e.v] = d[v] + 1;
                q.push(e.v);
            }
    }
    return (d[t] != -1);
}

int dfs(int u, int cmin) {
    if(u == t)
        return cmin;
    for(; first[u] < g[u].size(); first[u]++) {
        edge &e = g[u][first[u]];
        if(e.c - e.f > 0 && d[e.v] == d[u] + 1) {
            int x = dfs(e.v, min(cmin, e.c - e.f));
            if(x > 0) {
                e.f += x;
                g[e.v][e.rev].f -= x;
                return x;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int j = 2; j * j <= x; j++)
            if(x % j == 0) {
                x /= j;
                cnt[i][j]++;
                j--;
            }
        if(x > 1)
            cnt[i][x]++;
    }
    for(int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        --x[i]; --y[i];
    }
    vector<int> prime;
    for(int i = 0; i < n; i++)
        for(pair<int, int> pp : cnt[i])
            prime.push_back(pp.first);
    sort(prime.begin(), prime.end());
    prime.erase(unique(prime.begin(), prime.end()), prime.end());
    s = n;
    t = n + 1;
    V = n + 2;
    for(int pr : prime) {
        g.clear();
        g.resize(V);
        for(int i = 0; i < n; i++)
            if(i & 1) {
                g[i].push_back({t, cnt[i][pr], 0, g[t].size()});
                g[t].push_back({i, 0, 0, g[i].size() - 1});
            } else {
                g[s].push_back({i, cnt[i][pr], 0, g[i].size()});
                g[i].push_back({s, 0, 0, g[s].size() - 1});
            }
        for(int i = 0; i < m; i++) {
            int u = x[i];
            int v = y[i];
            if(u & 1)
                swap(u, v);
            g[u].push_back({v, min(cnt[u][pr], cnt[v][pr]), 0, g[v].size()});
            g[v].push_back({u, 0, 0, g[u].size() - 1});
        }
        while(bfs()) {
            first.assign(V, 0);
            while(dfs(s, INT_MAX));
        }
        for(edge e : g[s])
            ans += e.f;
    }
    cout << ans;
}