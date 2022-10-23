#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n + 1);
    for (int i = 0; i < n; ++i) cin >> x[i];
    x[n] = 1LL << 50;
    sort(x.begin(), x.end());
    int p = -1, q = -1;
    for (int d = 0; d < 32; ++d) {
        for (int m = 0; m < n; ++m) {
            long long mx = x[m];
            long long lx = mx - (1LL << d);
            long long rx = mx + (1LL << d);
            int l = lower_bound(x.begin(), x.end(), lx) - x.begin();
            int r = lower_bound(x.begin(), x.end(), rx) - x.begin();
            if (x[l] == lx and x[r] == rx) {
                cout << 3 << '\n';
                cout << lx << ' ' << mx << ' ' << rx << '\n';
                return 0;
            } else if (x[l] == lx) {
                p = l, q = m;
            } else if (x[r] == rx) {
                p = m, q = r;
            }
        }
    }
    if (p >= 0) {
        cout << 2 << '\n';
        cout << x[p] << ' ' << x[q] << '\n';
    } else {
        cout << 1 << '\n';
        cout << x[0] << '\n';
    }
    return 0;
}