#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<char>> a;
vector<vector<int>> used;
int n, m;
void dfs(int i, int j) {
    used[i][j] = 1;
    if (i > 0 && a[i - 1][j] != '#' && !used[i - 1][j])
        dfs(i - 1, j);
    if (i + 1 < n && a[i + 1][j] != '#' && !used[i + 1][j])
        dfs(i + 1, j);
    if (j > 0 && a[i][j - 1] != '#' && !used[i][j - 1])
        dfs(i, j - 1);
    if (j + 1 < m && a[i][j + 1] != '#' && !used[i][j + 1])
        dfs(i, j + 1);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a = vector<vector<char>>(n, vector<char>(m));
        used = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        bool f = false;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == 'B') {
                    if (i > 0 && a[i - 1][j] == 'G')
                        f = true;
                    if (i > 0 && a[i - 1][j] != 'B')
                        a[i - 1][j] = '#';
                    if (i + 1 < n && a[i + 1][j] == 'G')
                        f = true;
                    if (i + 1 < n && a[i + 1][j] != 'B')
                        a[i + 1][j] = '#';
                    if (j > 0 && a[i][j - 1] == 'G')
                        f = true;
                    if (j > 0 && a[i][j - 1] != 'B')
                        a[i][j - 1] = '#';
                    if (j + 1 < m && a[i][j + 1] == 'G')
                        f = true;
                    if (j + 1 < m && a[i][j + 1] != 'B')
                        a[i][j + 1] = '#';
                }
        if (f) {
            cout << "No\n";
            continue;
        }
        if (a[n - 1][m - 1] != '#')
            dfs(n - 1, m - 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == 'G' && !used[i][j])
                    f = true;
        if (f)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}