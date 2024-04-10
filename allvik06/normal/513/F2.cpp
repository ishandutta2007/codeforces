//#pragma GCC optimize("O3,no-stack-protector")
//#pragma GCC target("avx2")

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>
#include <queue>

using namespace std;
#define ll long long

int len, mash = 1;
const int INF = 1e9;

struct edge {
    int to, c, f = 0;
    int ind_p, num_p;

    edge(int to, int c, int ind_p, int num_p) : to(to), c(c), ind_p(ind_p), num_p(num_p) {}

    edge() {}
};

vector <edge> g[100000];
vector<int> dist, f;

int dfs(int v, int cmin) {
    if (v == len - 1) return cmin;
    for (int _ = f[v]; _ < (int)g[v].size(); ++_) {
        auto& i = g[v][_];
        if (i.c - i.f >= mash && dist[v] + 1 == dist[i.to]) {
            int minn = dfs(i.to, min(cmin, i.c - i.f));
            if (minn == 0) {
                ++f[v];
            } else {
                i.f += minn;
                g[i.ind_p][i.num_p].f -= minn;
                return minn;
            }
        } else {
            ++f[v];
        }
    }
    return 0;
}

inline bool dinic() {
    dist.assign(len, INF);
    f.assign(len, 0);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto i : g[now]) {
            if (i.c - i.f >= mash && dist[now] + 1 < dist[i.to]) {
                dist[i.to] = dist[now] + 1;
                q.push(i.to);
            }
        }
    }
    if (dist[len - 1] == INF) return false;
    while (dfs(0, INF)) {}
    return true;
}

int n, m, ma, fm;

inline int get_num1(int x, int y) {
    return 1 + ma + x * m + y;
}

inline int get_num2(int x, int y) {
    return 1 + ma + x * m + y + n * m;
}

inline void add_edge(int x, int y) {
    edge tmp1(y, 1, y, (int)g[y].size());
    edge tmp2(x, 0, x, (int)g[x].size());
    g[x].push_back(tmp1);
    g[y].push_back(tmp2);
}

inline void clear() {
    for (int i = 0; i < 100000; ++i) {
        vector <edge>().swap(g[i]);
    }
}

void solve() {
    cin >> n >> m >> ma >> fm;
    vector <array <int, 3>> all_m, all_f;
    char a[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    if (ma == fm - 1) {
        int x, y, t;
        cin >> x >> y >> t; --x; --y;
        all_m.push_back({x, y, t});
    } else if (ma - 1 == fm) {
        int x, y, t;
        cin >> x >> y >> t; --x; --y;
        all_f.push_back({x, y, t});
    } else {
        cout << -1;
        return;
    }
    for (int i = 0; i < ma; ++i) {
        int x, y, t;
        cin >> x >> y >> t; --x; --y;
        all_m.push_back({x, y, t});
    }
    for (int i = 0; i < fm; ++i) {
        int x, y, t;
        cin >> x >> y >> t; --x; --y;
        all_f.push_back({x, y, t});
    }
    ma = max(ma, fm);
    fm = max(ma, fm);
    len = 2 + ma + fm + 2 * n * m;
    ll l = -1, r = 1e12;
    vector <vector <int>> d;
    vector <vector <vector <array <int, 3>>>> flex(n, vector <vector <array <int, 3>>> (m));
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') continue;
            flex[i][j].push_back({i, j, 0});
            d.assign(n, vector <int> (m, INF));
            queue <pair <int, int>> q;
            q.push(make_pair(i, j));
            d[i][j] = 0;
            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#') continue;
                    if (d[nx][ny] > d[x][y] + 1) {
                        d[nx][ny] = d[x][y] + 1;
                        q.push(make_pair(nx, ny));
                        flex[i][j].push_back({nx, ny, d[nx][ny]});
                    }
                }
            }
        }
    }
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        clear();
        for (int i = 0; i < ma; ++i) {
            add_edge(0, i + 1);
        }
        for (int i = 0; i < ma; ++i) {
            ll cnt = mid / all_m[i][2];
            for (auto j : flex[all_m[i][0]][all_m[i][1]]) {
                if (j[2] > cnt) break;
                add_edge(i + 1, get_num1(j[0], j[1]));
            }
        }
        for (int i = 0; i < fm; ++i) {
            add_edge(1 + ma + 2 * n * m + i, len - 1);
        }
        for (int i = 0; i < ma; ++i) {
            ll cnt = mid / all_f[i][2];
            for (auto j : flex[all_f[i][0]][all_f[i][1]]) {
                if (j[2] > cnt) break;
                add_edge(get_num2(j[0], j[1]), 1 + ma + 2 * n * m + i);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                add_edge(get_num1(i, j), get_num2(i, j));
            }
        }
        while (dinic()) {}
        int flow = 0;
        for (auto i : g[0]) {
            flow += i.f;
        }
        if (flow == ma) r = mid;
        else l = mid;
    }
    if (r == 1e12) {
        cout << -1;
        return;
    }
    cout << r;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        // cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*

 */