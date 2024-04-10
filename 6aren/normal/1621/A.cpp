#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        if ((n + 1) / 2 < k) cout << -1 << '\n';
        else {
            vector<string> res(n, string(n, '.'));
            for (int i = 0; i <= 2 * k - 2; i += 2) {
                res[i][i] = 'R';
            }
            for (int i = 0; i < n; i++) cout << res[i] << '\n';
        }
    }
    return 0;
}