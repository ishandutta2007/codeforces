#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include<cp/debugger.hpp>
#else 
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> check(2, vector<int>(2));
        set<pair<int, int>> s;
        for (int i = 0; i < 3; i++) {
            int x, y;
            cin >> x >> y;
            s.insert({x, y});
            check[x % 2][y % 2] = 1;
        }
        int X, Y;
        cin >> X >> Y;
        if (s.count({1, 1}) && s.count({1, 2}) && s.count({2, 1})) {
            cout << (X == 1 || Y == 1 ? "YES\n" : "NO\n");
            continue;
        }
        if (s.count({n, n}) && s.count({n - 1, n}) && s.count({n, n - 1})) {
            cout << (X == n || Y == n ? "YES\n" : "NO\n");
            continue;
        }
        if (s.count({n, 1}) && s.count({n, 2}) && s.count({n - 1, 1})) {
            cout << (X == n || Y == 1 ? "YES\n" : "NO\n");
            continue;
        }
        if (s.count({1, n}) && s.count({2, n}) && s.count({1, n - 1})) {
            cout << (X == 1 || Y == n ? "YES\n" : "NO\n");
            continue;
        }
        cout << (check[X % 2][Y % 2] ? "YES\n" : "NO\n");
    }
    return 0;
}