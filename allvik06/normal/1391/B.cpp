#include <bits/stdc++.h>

using namespace std;
#define ll long long
inline int min(const int &a, const int &b) {
    if (a < b) return a;
    else return b;
}

inline int solve1(int n, int m, vector <vector <char>> &a) {
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i][m - 1] == 'R') ++ans;
    }
    for (int i = 0; i < m - 1; ++i) {
        if (a[n - 1][i] == 'D') ++ans;
    }
    return ans;
}

inline int solve2() {

}

signed main() {
    srand(time(0));
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t;
        cin >> t;
        while (t--) {
            int n, m;
            cin >> n >> m;
            vector <vector <char>> a(n, vector <char> (m));
            string s;
            for (int i = 0; i < n; ++i) {
                cin >> s;
                for (int j = 0; j < m; ++j) {
                    a[i][j] = s[j];
                }
            }
            cout << solve1(n, m, a) << "\n";
        }
    }
    else {

    }
}