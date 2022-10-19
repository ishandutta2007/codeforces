#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9;


signed main() {
    int n, m;
    cin >> n >> m;
    vector <int> d(m);
    for (int i = 0; i < m; ++i) cin >> d[i];
    sort(d.begin(), d.end());
    int g, r;
    cin >> g >> r;
    vector <vector <int>> dist(m, vector <int> (g, INF));
    deque <pair <int, int>> q;
    dist[0][0] = 0;
    q.push_front({0, 0});
    while (!q.empty()) {
        pair <int, int> now = q.front();
        q.pop_front();
        if (now.first != m - 1) {
            int len = d[now.first + 1] - d[now.first];
            if (now.second + len == g) {
                if (dist[now.first + 1][0] > dist[now.first][now.second] + 1) {
                    dist[now.first + 1][0] = dist[now.first][now.second] + 1;
                    q.emplace_back(now.first + 1, 0);
                }
            }
            if (now.second + len < g) {
                if (dist[now.first + 1][now.second + len] > dist[now.first][now.second]) {
                    dist[now.first + 1][now.second + len] = dist[now.first][now.second];
                    q.emplace_front(now.first + 1, now.second + len);
                }
            }
        }
        if (now.first != 0) {
            int len = d[now.first] - d[now.first - 1];
            if (now.second + len == g) {
                if (dist[now.first - 1][0] > dist[now.first][now.second] + 1) {
                    dist[now.first - 1][0] = dist[now.first][now.second] + 1;
                    q.emplace_back(now.first - 1, 0);
                }
            }
            if (now.second + len < g) {
                if (dist[now.first - 1][now.second + len] > dist[now.first][now.second]) {
                    dist[now.first - 1][now.second + len] = dist[now.first][now.second];
                    q.emplace_front(now.first - 1, now.second + len);
                }
            }
        }
    }
    int maxx = INF;
    for (int i = 0; i < m; ++i) {
        int len = d[m - 1] - d[i];
        if (len > g) continue;
        maxx = min(maxx, dist[i][0] * (r + g) + len);
    }
    if (maxx == INF) cout << -1;
    else cout << maxx;
	return 0;
}