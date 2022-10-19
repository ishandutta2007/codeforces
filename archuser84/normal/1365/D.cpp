#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, m;
bool ans, good;
vector <vector <char>> grid;
vector <vector <bool>> can, mark;
vector <int> dx = {1, -1, 0, 0};
vector <int> dy = {0, 0, 1, -1};

inline bool ok(int X, int Y) {
    return X < n and X > -1 and Y < m and Y > -1 and grid[X][Y] != '#';
}

void read_input() {
    good = false;
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            good |= grid[i][j] == 'G';
        }
    }
    return;
}

void solve() {
    ans = true;
    can.resize(n, vector <bool> (m));
    mark.resize(n, vector <bool> (m));
    can.assign(n, vector <bool> (m, false));
    mark.assign(n, vector <bool> (m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                for (int k = 0; k < 4; k++) {
                    if (ok(i + dx[k], j + dy[k]) and grid[i + dx[k]][j + dy[k]] == '.') {
                        grid[i + dx[k]][j + dy[k]] = '#';
                    }
                }
            }
        }
    }
    queue <pii> Q;
    can[n - 1][m - 1] = true;
    mark[n - 1][m - 1] = true;
    Q.push(pii{n - 1, m - 1});
    while (!Q.empty()) {
        pii tmp = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            if (ok(tmp.first + dx[i], tmp.second + dy[i]) and !mark[tmp.first + dx[i]][tmp.second + dy[i]]) {
                can[tmp.first + dx[i]][tmp.second + dy[i]] = true;
                Q.push(pii{tmp.first + dx[i], tmp.second + dy[i]});
                mark[tmp.first + dx[i]][tmp.second + dy[i]] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                ans &= !can[i][j];
            }
            if (grid[i][j] == 'G') {
                ans &= can[i][j];
            }
        }
    }
    return;
}

void write_output() {
    cout << (ans or !good? "Yes\n": "No\n");
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << can[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';
    return;
}

void test_cases() {
    int t;
    cin >> t;
    while (t--) {
        read_input();
        solve();
        write_output();
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    test_cases();
    return 0;
}