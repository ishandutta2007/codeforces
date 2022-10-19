#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (abs(a - b) > 1 || a + b > n - 2) {
            cout << -1 << '\n';
            continue;
        }
        bool sw = 0;
        if (a > b) sw = 1, swap(a, b);
        int l = 0, r = 0;
        vector<int> res;
        res.push_back(0);
        bool down = true;
        for (int i = 1; i < n; i++) {
            if (down) {
                res.push_back(l - 1);
                l--;
            } else {
                res.push_back(r + 1);
                r++;
            }
            if (a + b > 0) {
                if (down) b--;
                else a--;
                down ^= 1;
            }
        }
        for (int i = 0; i < n; i++) res[i] += (-l) + 1;
        if (sw) {
            for (int i = 0; i < n; i++) res[i] = n + 1 - res[i];
        }
        for (int i = 0; i < n; i++) cout << res[i] << ' ';
        cout << '\n';
    }
    return 0;
}