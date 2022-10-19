#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> ans(n, vector<int>(m)), a(n, vector<int>(m)), b(m, vector<int>(n));
        vector<pair<int, int>> used(n*m+1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j], used[a[i][j]].f = j;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> b[i][j], used[b[i][j]].s = j;
        for (int i = 1; i <= n*m; ++i)
            ans[used[i].s][used[i].f] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}