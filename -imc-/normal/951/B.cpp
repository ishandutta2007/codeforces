#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read);

#define int li

ostream& dbgPrintContainer(ostream& os, const auto& container, const char* brackets = "[]") {
    os << brackets[0] << " ";
    for (auto& elem : container) {
        os << elem << " ";
    }
    os << brackets[1];
    return os;
}

ostream& operator<<(ostream& os, const pair<auto, auto>& p) {
    return os << "(" << p.first << " " << p.second << ")";
}

ostream& operator<<(ostream& os, const vector<auto>& v) { return dbgPrintContainer(os, v, "[]"); }
ostream& operator<<(ostream& os, const set<auto>& v) { return dbgPrintContainer(os, v, "{}"); }
ostream& operator<<(ostream& os, const map<auto, auto>& v) { return dbgPrintContainer(os, v, "{}"); }

signed main() {
    auto t0 = clock();
    cout << fixed << setprecision(12);

#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

#if 0
    while (true) {
        solve(false);
    }
#endif

#ifdef YA
    cerr << endl << endl << fixed << setprecision(5) << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

const int N = 55;
int cube[N][N];
int dest[N][N];

int orig_cube[N][N];

char ban[N][N];
int n;

vector<array<int, 4>> ans;

int pr[N][N];

void roll_nearest(int x, int y) {
    if (cube[x][y]) {
        return;
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            pr[i][j] = -1;
        }
    }
    pr[x][y] = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (cube[p.first][p.second]) {
            cube[x][y] = cube[p.first][p.second];
            cube[p.first][p.second] = 0;

            while (p.first != x || p.second != y) {
                bool ok = false;
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (ok) {
                            break;
                        }
                        if (abs(i) + abs(j) != 1) {
                            continue;
                        }
                        int nx = p.first + i, ny = p.second + j;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            continue;
                        }
                        if (pr[nx][ny] == pr[p.first][p.second] - 1) {
                            ok = true;
                            ans.push_back({p.first, p.second, nx, ny});
                            p = {nx, ny};
                        }
                    }
                }
            }
            return;
        }
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (abs(i) + abs(j) != 1) {
                    continue;
                }
                int nx = p.first + i, ny = p.second + j;
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                    continue;
                }
                if (ban[nx][ny]) {
                    continue;
                }
                if (pr[nx][ny] > -1) {
                    continue;
                }
                pr[nx][ny] = pr[p.first][p.second] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void printAnswer() {
    cout << ans.size() << "\n";
    for (auto v : ans) {
        for (int x : v) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }

    if (ans.size() > 10800) {
        while (true);
    }
}

void checkAnswer() {
    for (auto v : ans) {
        int i0 = v[0], j0 = v[1], i1 = v[2], j1 = v[3];

        //cout << "move " << i0 << " " << j0 << " -> " << i1 << " " << j1 << endl;

        assert(i0 < n && i1 < n && j0 < n && j1 < n);
        assert(i0 >= 0 && j0 >= 0 && i1 >= 0 && j1 >= 0);
        assert(orig_cube[i0][j0] != 0);
        assert(orig_cube[i1][j1] == 0);
        assert(abs(i0 - i1) + abs(j0 - j1) == 1);

        orig_cube[i1][j1] = orig_cube[i0][j0];
        orig_cube[i0][j0] = 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            assert(orig_cube[i][j] == dest[i][j]);
        }
    }
}

void solve(bool __attribute__((unused)) read) {
    ans.clear();
    memset(pr, 0, sizeof(pr));
    memset(cube, 0, sizeof(cube));
    memset(dest, 0, sizeof(dest));
    memset(orig_cube, 0, sizeof(orig_cube));
    memset(ban, 0, sizeof(ban));

    vector<pair<int, int>> untaken1, untaken2;

    bool doPrint = false;

    int m;
    if (read) {
        cin >> n >> m;
    } else {
        n = rand() % 3 + 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                untaken1.emplace_back(i + 1, j + 1);
            }
        }
        untaken2 = untaken1;
        random_shuffle(all(untaken1));
        random_shuffle(all(untaken2));

        m = rand() % n + 1;
        if (doPrint)
        cout << "TEST " << n << " " << m << endl;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        if (read) {
            cin >> x >> y;
        } else {
            int ind = rand() % untaken1.size();
            x = untaken1[ind].first;
            y = untaken1[ind].second;
            untaken1.erase(untaken1.begin() + ind);
            if (doPrint)
            cout << x << " " << y << endl;
        }
        cube[x - 1][y - 1] = i + 1;
    }

    memcpy(orig_cube, cube, sizeof(cube));

    for (int i = 0; i < m; ++i) {
        int x, y;
        if (read) {
            cin >> x >> y;
        } else {
            int ind = rand() % untaken2.size();
            x = untaken2[ind].first;
            y = untaken2[ind].second;
            untaken2.erase(untaken2.begin() + ind);
            if (doPrint)
            cout << x << " " << y << endl;
        }
        dest[x - 1][y - 1] = i + 1;
    }

    if (!read) {
        if (doPrint)
        cout << "END TEST" << endl;
    }

    vector<int> cnt_r(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dest[i][j]) {
                cnt_r[i] += 1;
            }
        }
    }

    int row = -1;
    for (int i = 0; i < n; ++i) {
        int cn = 0, sm = 0;
        for (int j = -1; j <= 1; ++j) {
            if (i + j >= 0 && i + j < n) {
                ++cn;
                sm += cnt_r[i + j];
            }
        }
        if (sm <= cn) {
            row = i;
        }
    }
    assert(row > -1);

    for (int i = 0; i < n; ++i) {
        roll_nearest(row, i);
        ban[row][i] = 1;
    }

    vector<pair<int, int>> dests;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dest[i][j]) {
                dests.push_back({i, j});
            }
        }
    }
    sort(all(dests), [&](const pair<int, int>& p, const pair<int, int>& q) {
        return abs(p.first - row) > abs(q.first - row);
    });

    for (auto p : dests) {
        if (abs(p.first - row) <= 1) {
            break;
        }
        int color = dest[p.first][p.second];
        int col = -1;
        for (int i = 0; i < n; ++i) {
            if (cube[row][i] == color) {
                col = i;
            }
        }
        assert(col > -1);
        cube[p.first][p.second] = cube[row][col];
        cube[row][col] = 0;

        int dx = (p.first < row) ? -1 : 1;
        int dy = (p.second < col) ? -1 : 1;
        ans.push_back({row, col, row + dx, col});
        for (int i = 0; i < abs(p.second - col); ++i) {
            ans.push_back({row + dx, col + i * dy, row + dx, col + (i + 1) * dy});
        }
        for (int i = 1; i < abs(p.first - row); ++i) {
            ans.push_back({row + i * dx, p.second, row + (i + 1) * dx, p.second});
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ban[i][j] = (abs(i - row) > 1);
        }
    }

    int cnt = 0;
    int cn = 0;
    for (int i = -1; i <= 1; ++i) {
        if (row + i >= 0 && row + i < n) {
            cnt += cnt_r[row + i];
            cn += 1;
        }
    }

    if (cnt == 0) {
        printAnswer();
        checkAnswer();
        return;
    }

    if (cn == 3 && cnt_r[row] == 3) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ban[i][j] = (abs(i - row) > 1);
            }
        }
        for (int i = 0; i < 3; ++i) {
            roll_nearest(row - 1 + i, 0);
            ban[row - 1 + i][0] = 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (dest[row][i]) {
                int color = dest[row][i];
                int r = row - 1;
                while (cube[r][0] != color) {
                    ++r;
                }

                cube[r][0] = 0;
                cube[row][i] = color;
                int y = 0;
                if (i != 0) {
                    ans.push_back({r, 0, r, 1});
                    y = 1;
                }
                if (r != row) {
                    ans.push_back({r, y, row, y});
                }
                while (y < i) {
                    ans.push_back({row, y, row, y + 1});
                    y += 1;
                }
            }
        }

        printAnswer();
        checkAnswer();
        return;
    }

    int l, r;
    if (cn == 3) {
        int rw = (cnt_r[row + 1] >= 1) ? row + 1 : row - 1;
        int dx = (rw > row) ? 1 : -1;
        for (int i = 0; i < n; ++i) {
            if (cube[row][i]) {
                ans.push_back({row, i, row - dx, i});
                cube[row - dx][i] = cube[row][i];
                cube[row][i] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (dest[rw][i]) {
                int color = dest[rw][i];
                int col = -1;
                for (int i = 0; i < n; ++i) {
                    if (cube[row - dx][i] == color) {
                        col = i;
                    }
                }
                assert(col > -1);
                cube[rw][i] = cube[row - dx][col];
                cube[row - dx][col] = 0;

                int dy = (i < col) ? -1 : 1;
                ans.push_back({row - dx, col, row, col});
                for (int j = 0; j < abs(i - col); ++j) {
                    ans.push_back({row, col + j * dy, row, col + (j + 1) * dy});
                }
                ans.push_back({row, i, rw, i});
            }
        }
        l = row - dx;
        r = row;
        if (dx < 0) {
            swap(l, r);
        }
        row = row - dx;
    } else {
        l = max<li>(0, row - 1);
        r = min<li>(n - 1, row + 1);
    }

    cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = l; j <= r; ++j) {
            if (dest[j][i]) {
                ++cnt;
            }
        }
    }

    if (cnt == 0) {
        printAnswer();
        checkAnswer();
        return;
    }

    if (cnt == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ban[i][j] = !(i == l || i == r);
            }
        }
        for (int i = l; i <= r; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dest[i][j]) {
                    roll_nearest(i, j);
                }
            }
        }
    } else {
        if (cnt_r[row] < cnt_r[l + r - row]) {
            row = l + r - row;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ban[i][j] = !(i == l || i == r);
            }
        }
        for (int i = 0; i < cnt; ++i) {
            roll_nearest(row, i);
            ban[row][i] = 1;
        }

        if (cnt_r[l] == 1 && cnt_r[r] == 1) {
            int color_row_dest = *max_element(dest[row], dest[row] + n);
            for (int i = 0; i < n; ++i) {
                if (cube[row][i] && cube[row][i] != color_row_dest) {
                    cube[l + r - row][i] = cube[row][i];
                    cube[row][i] = 0;
                    ans.push_back({row, i, l + r - row, i});
                }
            }
            for (int i = l; i <= r; ++i) {
                int col = max_element(dest[i], dest[i] + n) - dest[i];
                int y = max_element(cube[i], cube[i] + n) - cube[i];
                int dy = (col < y) ? -1 : 1;
                while (y != col) {
                    ans.push_back({i, y, i, y + dy});
                    y += dy;
                }
            }
        } else {
            int sample_dest = max_element(dest[row], dest[row] + n) - dest[row];
            int color_row_dest = dest[row][sample_dest];
            int such_cube = find(cube[row], cube[row] + n, color_row_dest) - cube[row];
            ans.push_back({row, such_cube, l + r - row, such_cube});
            cube[l + r - row][such_cube] = cube[row][such_cube];
            cube[row][such_cube] = 0;

            for (int i = l; i <= r; ++i) {
                int color = *max_element(cube[i], cube[i] + n);
                int col = find(dest[row], dest[row] + n, color) - dest[row];
                int y = max_element(cube[i], cube[i] + n) - cube[i];
                int dy = (col < y) ? -1 : 1;
                while (y != col) {
                    ans.push_back({i, y, i, y + dy});
                    y += dy;
                }
            }
            ans.push_back({l + r - row, sample_dest, row, sample_dest});
        }
    }

    printAnswer();
    checkAnswer();
}