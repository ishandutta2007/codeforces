#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << fixed << setprecision(30);
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    vector <int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) cin >> b[i + 1];
    cin >> b[0];
    double l = 0, r = 10E9;
    bool f = 1;
    while (r - l > 10E-7) {
        double mid = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            mid -= (m + mid) / a[i];
            mid -= (m + mid) / b[i];
        }
        if (mid >= 0) {
            r = (l + r) / 2;
            f = 0;
        }
        else l = (l +  r) / 2;
    }
    if (f) cout << -1;
    else cout << r;
    return 0;
}