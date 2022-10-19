#include <bits/stdc++.h>

using namespace std;

#define int long long
const int INF = 1e18;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int lmax1 = -1, lmax2 = -1, rmin1 = INF, rmin2 = INF, rmax = INF;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x >= lmax1) {
            lmax2 = lmax1;
            lmax1 = x;
            rmax = y;
        }
        else if (x > lmax2) {
            lmax2 = x;
        }
        if (y <= rmin1) {
            rmin2 = rmin1;
            rmin1 = y;
        }
        else if (y < rmin2) {
            rmin2 = y;
        }
    }
    int maxx = 0;
    if (rmax == rmin1) {
        maxx = max(maxx, rmin2 - lmax2);
    }
    maxx = max(maxx, rmin1 - lmax2);
    maxx = max(maxx, rmin2 - lmax1);
    cout << maxx;
}