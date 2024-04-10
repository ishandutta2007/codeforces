#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <functional>
#include <set>
#include <algorithm>
#include <ctime>
#include <vector>
#include <memory>
#include <string>
#include <optional>

using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const ll INF = 1e9 + 10;
const int M = 1e3 + 10;
const int N = 1e6 + 10;

vector<int> g[N];
int p[N];
int dist[N];
int tot_out[N];
set<int> good[N];

void solve() {
    int n, m;
    cin >> n >> m; 
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        g[--u].push_back(--v);
        tot_out[v]++;
    }
    int qq;
    cin >> qq;
    for (int i = 0; i < qq; ++i) {
        cin >> p[i];
        --p[i];
    }
    fill(dist, dist + n, INF);
    dist[p[qq - 1]] = 0;
    queue<int> q;
    q.push(p[qq - 1]);
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto u: g[v]) {
            if (dist[u] == INF) {
                dist[u] = dist[v] + 1;
                q.push(u);
                good[u].insert(v);
            } else if (dist[u] == dist[v] + 1) {
                good[u].insert(v);
            }
        }
    }

    int mina = 0, maxa = 0;
    for (int i = 0; i + 1 < qq; ++i) {
        if (!good[p[i]].count(p[i + 1])) {
            mina++;
        }
        if (!good[p[i]].count(p[i + 1]) || (int)good[p[i]].size() >= 2) {
            maxa++;
        }
    }
    cout << mina << " " << maxa << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}