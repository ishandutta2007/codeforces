#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x),end(x)

const int maxn = 2e5 + 42;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int lx[n], ly[n], rx[n], ry[n];
    for(int i = 0; i < n; i++) {
        cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
    }
    int pxl[n], pyl[n];
    iota(pxl, pxl + n, 0);
    iota(pyl, pyl + n, 0);
    sort(pxl, pxl + n, [&](int a, int b){return lx[a] > lx[b];});
    sort(pyl, pyl + n, [&](int a, int b){return ly[a] > ly[b];});
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 1; j++) {
            int x = lx[pxl[i]];
            int y = ly[pyl[j]];
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt += lx[i] <= x && x <= rx[i] &&
                       ly[i] <= y && y <= ry[i];
            }
            if(cnt >= n - 1) {
                cout << x << ' ' << y << endl;
                return 0;
            }
        }
    }
    assert(0);
    return 0;
}