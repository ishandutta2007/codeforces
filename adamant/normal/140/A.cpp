#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, R, r;
    cin >> n >> R >> r;
    const double pi = acos(-1), eps = 1e-8;
    if(r > R) {
        cout << "NO" << endl;
    } else if(2 * r > R) {
        cout << (n == 1 ? "YES" : "NO") << endl;
    } else {
        double phi = 2 * asin(1. * r / (R - r));
        if(phi * n > 2 * pi + eps) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}