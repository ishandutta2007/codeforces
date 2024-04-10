#include<bits/stdc++.h>

using namespace std;

constexpr int dx[3] = {0, -1, +1};
constexpr int INF = 1000000000;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (n <= 2) {
        cout << 0 << '\n';
    } else {
        int mn = INF;
        for (int d0 : dx) {
            for (int d1 : dx) {
                int change = (d0 != 0) + (d1 != 0);
                int d = (b[1] + d1) - (b[0] + d0);
                int v = b[1] + d1;
                bool ok = true;
                for (int j = 2; j < n; ++j) {
                    v += d;
                    int k = abs(v - b[j]);
                    if (k <= 1) {
                        change += k;
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    mn = min(mn, change);
                }
            }
        }
        if (mn == INF) cout << -1 << '\n';
        else cout << mn << '\n';
    }
    return 0;
}