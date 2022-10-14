#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

#define pb push_back
#define all(x) x.begin(), x.end()

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    map <pair<int, int>, int> ma;
    vector <vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a - 1].pb({b - 1, c});
        g[b - 1].pb({a - 1, c});
        ma[{min(a - 1, b - 1), max(a - 1, b - 1)}] = i + 1;
    }
    int now = 0;
    vector <int> last(n, -1);
    set <pair<int, int>> e;
    vector <long long> dist(n, INF);
    dist[0] = 0;
    set <pair<long long, int>> s;
    s.insert({0, 0});
    while (now < k + 1 && !s.empty()) {
        now++;
        int cur = s.begin() -> second;
        s.erase(s.begin());
        if (last[cur] != -1) {
            e.insert({cur, last[cur]});
        }
        for (auto to : g[cur]) {
            if (dist[to.first] > dist[cur] + to.second) {
                last[to.first] = cur;
                s.erase({dist[to.first], to.first});
                dist[to.first] = dist[cur] + to.second;
                s.insert({dist[to.first], to.first});
            }
        }
    }
    cout << e.size() << "\n";
    for (auto edge : e) {
        cout << ma[{min(edge.first, edge.second), max(edge.first, edge.second)}] << " ";
    }
    return 0;
}