#include<bits/stdc++.h>

using namespace std;

int a[1005][1005], b[1005][1005];
char ans[1005][1005];
int used[1005][1005], ok[1005][1005];
int n, sz;
vector < pair < int, int > > go = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector < char > f = {'D', 'U', 'R', 'L'}, to = {'U', 'D', 'L', 'R'};

void dfs(int i, int j, int x, int y) {
    ok[i][j] = 1;
    int cur = -1;
    for (auto key : go) {
        cur++;
        int nxt_i = i + key.first, nxt_j = j + key.second;
        if (a[nxt_i][nxt_j] == x && b[nxt_i][nxt_j] == y && ok[nxt_i][nxt_j] == 0) {
            ans[nxt_i][nxt_j] = f[cur];
            dfs(nxt_i, nxt_j, x, y);
        }
    }
}

void dfs1(int i, int j, int x, int y) {
    ok[i][j] = 1;
    sz++;
    int cur = -1;
    for (auto key : go) {
        cur++;
        int nxt_i = i + key.first, nxt_j = j + key.second;
        //cout << nxt_i << " " << nxt_j << " " << ok[nxt_i][nxt_j] << endl;
        if (a[nxt_i][nxt_j] == -1 && ok[nxt_i][nxt_j] == 0) {
            ans[nxt_i][nxt_j] = f[cur];
            if (i == x && j == y && ans[i][j] == '0') {
                ans[i][j] = to[cur];
            }
            dfs1(nxt_i, nxt_j, x, y);
        }
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j] >> b[i][j];
            ans[i][j] = '0';
            if (a[i][j] == i && b[i][j] == j) ans[i][j] = 'X';
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == i && b[i][j] == j) dfs(a[i][j], b[i][j], a[i][j], b[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] == -1 && ok[i][j] == 0) {
                sz = 0;
                dfs1(i, j, i, j);
                if (sz == 1) {
                    cout << "INVALID" << '\n';
                    exit(0);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (ans[i][j] == '0') {
                cout << "INVALID" << '\n';
                exit(0);
            }
        }
    }
    cout << "VALID" << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout << ans[i][j];
        cout << '\n';
    }
    return 0;
}