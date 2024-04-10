#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void bfs(const vector<string>& a,
         vector<vector<bool>>& used,
         vector<pair<int, int>>& cc,
         int x, int y) {
    used[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cc.push_back(make_pair(x, y));

        if (x == 0 || x == SZ(a) - 1 || y == 0 || y == SZ(a[0]) - 1) {
            cc[0].first = 0;
        }

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= SZ(a) || ny < 0 || ny >= SZ(a[0])) {
                continue;
            }
            if (used[nx][ny] || a[nx][ny] != '.') {
                continue;
            }
            used[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> A(n);

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    vector<vector<bool>> used(n, vector<bool>(m, false));

    vector<vector<pair<int, int>>> ccs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == '.' && !used[i][j]) {
                vector<pair<int, int>> cc;
                cc.push_back(make_pair(1, 1));
                bfs(A, used, cc, i, j);
                if (cc[0].first) {
                    cc.erase(cc.begin());
                    ccs.push_back(cc);
                }
            }
        }
    }

    sort(ccs.begin(), ccs.end(), [](const auto& a, const auto& b) -> bool {
        return SZ(a) < SZ(b);
    });

    k = SZ(ccs) - k;
    int ans = 0;
    for (vector<pair<int, int>>& p: ccs) {
        if (k-- == 0) {
            break;
        }
        ans += SZ(p);
        while (!p.empty()) {
            A[p.back().first][p.back().second] = '*';
            p.pop_back();
        }
    }
    cout << ans << '\n';

    for (const string& p: A) {
        cout << p << '\n';
    }
}