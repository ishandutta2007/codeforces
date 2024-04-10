#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    
    while (tt--) {
        int n;
        cin >> n;
        auto isBetter = [](vector<int> x, vector<int> y) {
            int cnt = 0;
            for (int i = 0; i < 5; i++) {
                if (x[i] < y[i]) cnt++;
            }
            return cnt >= 3;
        };
        vector<vector<int>> a(n, vector<int>(5));
        int id = -1;
        vector<int> best = {INF, INF, INF, INF, INF};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) cin >> a[i][j];
            if (isBetter(a[i], best)) {
                best = a[i];
                id = i;
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (i == id) continue;
            if (isBetter(a[i], best)) ok = false;
        }
        cout << (ok ? id + 1 : -1) << '\n';
        
    }

    return 0;
}