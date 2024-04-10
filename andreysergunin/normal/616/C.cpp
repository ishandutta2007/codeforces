#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int MAXN = 1010;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int c[MAXN][MAXN];
int vis[MAXN][MAXN];

int dfs(int x, int y, int col) {
    int ans = 1;
    vis[x][y] = col;
    for (int i = 0; i < 4; i++)
        if (c[x + dx[i]][y + dy[i]] == 0 && vis[x + dx[i]][y + dy[i]] == 0)
            ans += dfs(x + dx[i], y + dy[i], col);
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
                vis[i][j] = 1;
                c[i][j] = 1;
            }
            else
                vis[i][j] = 0;
        }
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == '.')
                c[i][j] = 0;
            else
                c[i][j] = 1;
        }
    }
    
    int col = 1;
    vector<int> v;
    v.push_back(0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (vis[i][j] == 0 && c[i][j] == 0)
                v.push_back(dfs(i, j, col++));
    
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (c[x][y] == 0)
                cout << '.';
            else {
                int ans = 1;
                for (int i = 0; i < 4; i++) {
                    if (c[x + dx[i]][y + dy[i]] == 0) {
                        bool f = true;
                        for (int j = 0; j < i; j++)
                            if (vis[x + dx[i]][y + dy[i]] == vis[x + dx[j]][y + dy[j]] &&
                                c[x + dx[j]][y + dy[j]] == 0)
                                f = false;
                        if (f)
                            ans += v[vis[x + dx[i]][y + dy[i]]];
                    }
                }
                cout << ans % 10;
            }
        }
        cout << endl;
    }
    
    return 0;
}