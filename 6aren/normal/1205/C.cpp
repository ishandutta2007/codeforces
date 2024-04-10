#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int n;
int ans[55][55];
string s[55];

bool query(int x, int y, int xx, int yy) {
    if (x > xx) {
        swap(x, xx);
        swap(y, yy);
    }
    if (y > yy) {
        swap(x, xx);
        swap(y, yy);
    }
    cout << "? " << x << ' ' << y << ' ' << xx << ' ' << yy << endl;
    bool palin;
    cin >> palin;
    // palin = (s[x][y] == s[xx][yy]);
    // cout << palin << endl;
    return palin;
}

int dx[] = {-1, 2, 0, 1, -2, 0};
int dy[] = {-1, 0, 2, 1, 0, -2};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     cin >> s[i];
    //     s[i] = " " + s[i];
    // }
    memset(ans, -1, sizeof(ans));
    ans[1][1] = 1;
    ans[n][n] = 0;
    if (query(1, 1, 2, 2)) ans[2][2] = 1;
    else ans[2][2] = 0;
    for (int i = 3; i <= n; i += 2) {
        if (query(i - 2, 1, i, 1)) {
            ans[i][1] = ans[i - 2][1];
        } else ans[i][1] = 1 - ans[i - 2][1];
    }
    for (int i = 4; i <= n; i += 2) {
        if (query(i - 2, 2, i, 2)) {
            ans[i][2] = ans[i - 2][2];
        } else ans[i][2] = 1 - ans[i - 2][2];
    }
    for (int i = 1; i <= n; i++) {
        int beg = 1;
        if (i % 2 == 0) beg = 2;
        for (int j = beg + 2; j <= n; j += 2) {
            if (query(i, j - 2, i, j)) {
                ans[i][j] = ans[i][j - 2];
            } else ans[i][j] = 1 - ans[i][j - 2];
        }
    }
    ans[1][2] = 0;
    queue<ii> q;
    q.push({1, 2});
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int x = v.x + dx[i];
            int y = v.y + dy[i];
            if (x < 1 || x > n) continue;
            if (y < 1 || y > n) continue;
            if (ans[x][y] != -1) continue;
            if (query(x, y, v.x, v.y)) ans[x][y] = ans[v.x][v.y];
            else ans[x][y] = 1 - ans[v.x][v.y];
            q.push({x, y});
        }
    }
    int ok = 1;
    ii pivot = {0, 0};
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
            if (ans[i][j] != ans[i - 1][j + 1]) {
                pivot = make_pair(i, j);
                break;
            }
        }
    }
    if (pivot != make_pair(0, 0)) {
        bool check;
        int x = pivot.x - 1;
        int y = pivot.y;
        int xx = pivot.x;
        int yy = pivot.y + 2;
        if (pivot.y == n - 1) {
            y = pivot.y - 1;
            xx = pivot.x;
            yy = pivot.y + 1;
        }
        check = query(x, y, xx, yy);
        if (check == (ans[x][y] == ans[xx][yy])) ok = 1;
        else ok = 0;
    } else {
        bool ok2 = 0;
        for (int i = 1; i < n - 1; i++) {
            if ((ans[i][i] ^ ans[i + 1][i + 1]) == (ans[i + 1][i] ^ ans[i + 2][i + 1])) {
                bool check = query(i, i, i + 2, i + 1);
                if (check == (ans[i][i] == ans[i + 2][i + 1])) ok = 1;
                else ok = 0;
                ok2 = 1;
            }
            if (ok2 == 1) break;
        }
        if (ok2 == 0) {
            for (int i = 2; i < n; i++) {
                if ((ans[i][i] ^ ans[i + 1][i + 1]) == (ans[i - 1][i] ^ ans[i][i + 1])) {
                    bool check = query(i - 1, i, i + 1, i + 1);
                    if (check == (ans[i - 1][i] == ans[i + 1][i + 1])) ok = 1;
                    else ok = 0;
                    ok2 = 1;
                }
                if (ok2 == 1) break;
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << ans[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << "----------\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i % 2 == j % 2) continue;
            if (!ok) ans[i][j] ^= 1; 
        }
    }
    // cout << ok << endl;
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
// 7
// 1011111
// 1010011
// 1100011
// 1100111
// 1001111
// 0011010
// 1100000