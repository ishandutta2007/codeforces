#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int N = 500, mod = 998244353;

set <int> adj[N];
bool cycle_found = false;
vector <int> cur;
int back_degree[N];

void find_cycle(int v, int n) {
    vector <int> path(n, -1);
    queue <int> q;
    q.push(v);
    while (q.size()) {
        int vv = q.front(); q.pop();
        for (int u : adj[vv]) {
            if (u == v && !cycle_found) {
                cycle_found = true;
                int tmp = vv;
                do {
                    cur.push_back(tmp);
                    tmp = path[tmp];
                } while (tmp != -1);
                reverse(cur.begin(), cur.end());
            } else if (path[u] == -1) {
                path[u] = vv;
                q.push(u);
            }
        }
    }
}

bool topo(int n) {
    vector <int> degree(n), ans;
    queue <int> q;
    for (int i = 0; i < n; ++i) {
        degree[i] = back_degree[i];
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int v = q.front(); q.pop();
        ans.push_back(v);
        for (int u : adj[v]) {
            degree[u]--;
            if (degree[u] == 0) q.push(u);
        }
    }
    return ans.size() == n;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].insert(v);
        back_degree[v]++;
    }
    for (int i = 0; i < n; ++i) {
        find_cycle(i, n);
        if (cycle_found) {
            break;
        }
    }
    bool is = !cycle_found;
    for (int i = 0; i < cur.size(); ++i) {
        int j = (i + 1) % int(cur.size());
        adj[cur[i]].erase(cur[j]);
        back_degree[cur[j]]--;
        is |= topo(n);
        adj[cur[i]].insert(cur[j]);
        back_degree[cur[j]]++;
    }
    cout << (is ? "YES\n" : "NO\n");
}