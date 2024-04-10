#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
mt19937 rng((size_t) make_shared<char>().get());

int ask(int x1, int y1, int x2, int y2) {
    assert(x1 + y1 + 2 <= x2 + y2);
    cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
    int r;
    cin >> r;
    return r;
}

int n;

void dfs(auto& a, auto& can, string& s, int sx, int sy, int x, int y) {
    if ((x + y) - (sx + sy) > 7 || x >= n || y >= n) {
        return;
    }
    s += char(a[x][y] + '0');
    bool ok = true;
    for (int i = 0; i < isz(s); i++) {
        if (s[i] != s[isz(s) - i - 1]) {
            ok = false;
            break;
        }
    }
    if (ok && sx + sy + 2 <= x + y) {
        can.insert({sx, sy, x, y});
    }

    dfs(a, can, s, sx, sy, x + 1, y);
    dfs(a, can, s, sx, sy, x, y + 1);

    s.pop_back();
}

int main(int argc, char** argv) {
#ifdef VSE
    // if (argc > 1) assert(freopen(argv[1], "r", stdin));
    rng.seed(0);
#endif
#ifndef cin
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif

    cin >> n;

    vector<vector<int>> a(n, vector<int>(n, -1));
    a[0][0] = 1;
    a[n - 1][n - 1] = 0;

    int dx[6] = {-2, -1, 0, 2, 1, 0};
    int dy[6] = {0, -1, -2, 0, 1, 2};

    queue<pair<int, int>> q;

    auto f = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    };

    auto go = [&](int sx, int sy) {
        q.push({sx, sy});
        while (!q.empty()) {
            auto [vx, vy] = q.front();
            q.pop();
            for (int i = 0; i < 6; i++) {
                int x = vx + dx[i];
                int y = vy + dy[i];
                if (!f(x, y) || a[x][y] != -1) {
                    continue;
                }
                int r = (i < 3 ? ask(x, y, vx, vy) : ask(vx, vy, x, y));
                if (r) {
                    a[x][y] = a[vx][vy];
                } else {
                    a[x][y] = 1 - a[vx][vy];
                }
                q.push({x, y});
            }
        }
    };

    go(0, 0);

    a[0][1] = 0;
    go(0, 1);

    auto b = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) & 1) {
                b[i][j] = 1 - b[i][j];
            }
        }
    }

    bool ff = false;

    string s;
    set<tuple<int, int, int, int>> sa, sb;

    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < n; jj++) {
            int i = 0, j = 0;
            dfs(a, sa, s, i + ii, j + jj, i + ii, j + jj);
            dfs(b, sb, s, i + ii, j + jj, i + ii, j + jj);
            
        }
    }

    for (auto& t : sa) {
        if (sb.find(t) == end(sb)) {
            ff = true;
            auto [x1, y1, x2, y2] = t;
            int r = ask(x1, y1, x2, y2);
            if (!r) {
                a.swap(b);
            }
            break;
        }
    }

    if (!ff) {
        for (auto& t : sb) {
            if (sa.find(t) == end(sa)) {
                ff = true;
                auto [x1, y1, x2, y2] = t;
                int r = ask(x1, y1, x2, y2);
                if (r) {
                    a.swap(b);
                }
                break;
            }
        }
    }

    cout << "!" << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}