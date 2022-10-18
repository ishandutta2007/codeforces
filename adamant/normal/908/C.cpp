#include <bits/stdc++.h>
 
using namespace std;

#define double long double
#define int int64_t
#define all(x) begin(x), end(x)

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    int x[n];
    double y[n];
    cout << fixed << setprecision(9);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        double mxy = r;
        for(int j = 0; j < i; j++) {
            if(abs(x[i] - x[j]) <= 2 * r) {
                int dx = abs(x[i] - x[j]);
                int dd = 2 * r;
                mxy = max(mxy, y[j] + (double)sqrt(dd * dd - dx * dx));
            }
        }
        cout << (y[i] = mxy) << endl;
    }
    return 0;
}