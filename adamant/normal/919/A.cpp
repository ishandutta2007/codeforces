#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    double c[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        c[i] = 1. * a[i] / b[i];
    }
    sort(c, c + n);
    cout << fixed << setprecision(8);
    cout << m * c[0] << endl;
    return 0;
}