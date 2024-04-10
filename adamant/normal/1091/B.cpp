#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x[n], y[n];
    map<int, map<int, int>> cnt;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        cnt[x[i]][y[i]]++;
    }
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for(int p0 = 0; p0 < n; p0++) {
        int tx = x[p0] + a[0], ty = y[p0] + b[0];
        bool ok = true;
        for(int i = 1; i < n; i++) {
            // x[p[i]] + a[i] = tx, y[p[i]] + b[i] = ty
            int nx = tx - a[i], ny = ty - b[i];
            ok &= cnt[nx][ny];
        }
        if(ok) {
            cout << tx << ' ' << ty << endl;
            break;
        }
    }
    return 0;
}