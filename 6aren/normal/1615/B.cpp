#include <bits/stdc++.h>

using namespace std;

#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    const int N = 200005;
    vector<vector<int>> pref(N, vector<int>(30));
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 30; j++) {
            pref[i][j] = pref[i - 1][j] + bit(i, j);
        }
    }

    int tt;
    cin >> tt;
    while (tt--) {
        int l, r;
        cin >> l >> r;
        int best = 0;
        for (int i = 0; i < 30; i++) {
            best = max(best, pref[r][i] - pref[l - 1][i]);
        }
        cout << (r - l + 1 - best) << '\n';
    }

    return 0;
}