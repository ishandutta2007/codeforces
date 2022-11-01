#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

int get(int i1, int j1, int i2, int j2, vector<vector<int>> &t) {
    if(i1 > i2 || j1 > j2) return 0;
    return t[i2][j2] - (i1 ? t[i1 - 1][j2] : 0) - (j1 ? t[i2][j1 - 1] : 0) + (i1 && j1 ? t[i1 - 1][j1 - 1] : 0);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<int>> b(n, vector<int>(m, 0));
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++) {
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            if(a[i][j] == '.') b[i][j] += (a[i - 1][j] == '.') + (a[i][j - 1] == '.');
        }
    vector<vector<int>> c(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++) {
            c[i][j] = c[i][j - 1] + (a[i][j - 1] == '.' && a[i][j] == '.');
        }
    vector<vector<int>> d(n, vector<int>(m, 0));
    for(int j = 0; j < m; j++)
        for(int i = 1; i < n; i++) {
            d[i][j] = d[i - 1][j] + (a[i - 1][j] == '.' && a[i][j] == '.');
        }
    int q; cin >> q;
    while(q--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        i1--; j1--; i2--; j2--;
        int ans = get(i1 + 1, j1 + 1, i2, j2, b);
        if(j1 < j2) ans += c[i1][j2] - c[i1][j1];
        if(i1 < i2) ans += d[i2][j1] - d[i1][j1];
        cout << ans << '\n';
    }
}