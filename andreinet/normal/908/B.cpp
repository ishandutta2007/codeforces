#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    int sx = -1, sy = -1;
    int ex = -1, ey = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    string s;
    cin >> s;
    vector<int> moves;
    for (char c: s) {
        moves.push_back(c - '0');
    }

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};
    vector<int> order(4);
    for (int i = 0; i < 4; ++i) {
        order[i] = i;
    }
    int ans = 0;
    do {
        int x = sx, y = sy;
        bool ok = true;
        for (int d: moves) {
            int nx = x + dx[order[d]];
            int ny = y + dy[order[d]];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != '#') {
                x = nx;
                y = ny;
            } else {
                ok = false;
                break;
            }
            if (x == ex && y == ey) {
                break;
            }
        }
        if (ok && x == ex && y == ey) {
            ans++;
        }
    } while (next_permutation(order.begin(), order.end()));
    cout << ans << '\n';
}