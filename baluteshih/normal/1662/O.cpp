#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()

int vis[400][25], edge[400][25][4];
int dx[4] = {0, 0, 1, 359}, dy[4] = {1, -1, 0, 0};

bool check(int x, int y) {
    return !(y < 0 || y > 21 || vis[x][y]);
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; ++i)
        if (!edge[x][y][i] && check((x + dx[i]) % 360, y + dy[i]))
            dfs((x + dx[i]) % 360, y + dy[i]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(vis, 0, sizeof vis);
        memset(edge, 0, sizeof edge);
        while (n--) {
            char c;
            cin >> c;
            if (c == 'C') {
                int r, t1, t2;
                cin >> r >> t1 >> t2;
                for (int i = t1; i != t2; i = (i + 1) % 360) {
                    edge[i][r - 1][0] = 1;
                    edge[i][r][1] = 1;
                }
            }
            else {
                int r1, r2, t;
                cin >> r1 >> r2 >> t;
                for (int i = r1; i != r2; ++i) {
                    edge[(t + 359) % 360][i][2] = 1;
                    edge[t][i][3] = 1;
                }
            }
        }
        dfs(0, 0);
        if (vis[0][21])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}