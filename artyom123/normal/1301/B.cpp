#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (auto &c : a) {
            cin >> c;
        }
        int m = 0, MN = INF, MX = -INF;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != -1 && a[i + 1] != -1) {
                m = max(m, abs(a[i] - a[i + 1]));
                continue;
            }
            if (a[i] == -1 && a[i + 1] == -1) {
                continue;
            }
            if (a[i] != -1) {
                MN = min(MN, a[i]);
                MX = max(MX, a[i]);
            } else {
                MN = min(MN, a[i + 1]);
                MX = max(MX, a[i + 1]);
            }
        }
        if (MN == INF) {
            cout << 0 << " " << 0 << "\n";
            continue;
        }
        cout << max(m, (MX - MN + 1) / 2) << " " << (MN + MX) / 2 << "\n";
    }
	return 0;
}