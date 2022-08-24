#include <bits/stdc++.h>

using namespace std;

vector <int> c;

int main() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int lim = (1 << n);
    int ans = 0;
    for (int mask = 0; mask < lim; mask++) {
        int t = 0;
        int mix = (int) 1e7;
        int mx = (int) -1e7;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                t += c[i];
                mix = min(mix, c[i]);
                mx = max(mx, c[i]);
            }
        }
        if (t >= l && t <= r && mx - mix >= x) {
            ans++;
        }
    }
    cout << ans << endl;
}