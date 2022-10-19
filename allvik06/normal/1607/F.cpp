#include <bits/stdc++.h>

using namespace std;

signed main() {
    srand(1303);
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <vector <char>> a(n, vector <char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector <vector <int>> used(n, vector <int> (m));
        vector <vector <int>> ans(n, vector <int> (m));
        vector <vector <pair <int, int>>> edge(n, vector <pair <int, int>> (m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x = i, y = j;
                if (a[i][j] == 'L') --y;
                else if (a[i][j] == 'R') ++y;
                else if (a[i][j] == 'D') ++x;
                else --x;
                edge[i][j] = make_pair(x, y);
            }
        }
        int cur = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (used[i][j]) continue;
                vector <pair <int, int>> st;
                int x = i, y = j;
                while (x >= 0 && x < n && y >= 0 && y < m && !used[x][y]) {
                    st.emplace_back(x, y);
                    used[x][y] = cur;
                    int new_x = edge[x][y].first, new_y = edge[x][y].second;
                    x = new_x;
                    y = new_y;
                }
                if (x >= 0 && x < n && y >= 0 && y < m && used[x][y] == cur) {
                    int cnt = 0;
                    bool ok = false;
                    vector <pair <int, int>> tmp;
                    for (auto k : st) {
                        if (k.first == x && k.second == y) {
                            ok = true;
                        }
                        if (ok) {
                            ans[k.first][k.second] = (int)st.size() - cnt;
                        } else {
                            ++cnt;
                            tmp.push_back(k);
                        }
                    }
                    reverse(tmp.begin(), tmp.end());
                    for (auto k : tmp) {
                        ans[k.first][k.second] = ans[edge[k.first][k.second].first][edge[k.first][k.second].second] + 1;
                    }
                } else {
                    reverse(st.begin(), st.end());
                    for (auto k : st) {
                        int new_x = edge[k.first][k.second].first;
                        int new_y = edge[k.first][k.second].second;
                        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) ans[k.first][k.second] = ans[new_x][new_y] + 1;
                        else ans[k.first][k.second] = 1;
                    }
                }
                ++cur;
            }
        }
        int maxx = 0, ansx, ansy;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxx = max(maxx, ans[i][j]);
                if (maxx == ans[i][j]) {
                    ansx = i;
                    ansy = j;
                }
            }
        }
        cout << ansx + 1 << " " << ansy + 1 << " " << maxx << "\n";
    }
}