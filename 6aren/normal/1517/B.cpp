#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> b(n, vector<int>(m));
        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> b[i][j];
                v.push_back(make_tuple(b[i][j], i, j));
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << b[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        sort(v.begin(), v.end());
        for (int i = 0; i < m; i++) {
            ans[get<1>(v[i])][get<2>(v[i])] = i;
        }
        
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = 0; j < m; j++) s.insert(j);
            for (int j = 0; j < m; j++) if (ans[i][j] != -1) s.erase(ans[i][j]);
            for (int j = 0; j < m; j++) {
                if (ans[i][j] != -1) continue;
                assert(!s.empty());
                int foo = *s.begin();
                ans[i][j] = foo;
                s.erase(s.begin());
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) cout << ans[i][j] + 1 << ' ';
        //     cout << '\n';
        // }
        vector<vector<int>> res(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][ans[i][j]] = b[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << res[i][j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}