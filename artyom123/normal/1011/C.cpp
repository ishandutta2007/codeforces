#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-7;

int main() {
    int n, m;
    cin >> n >> m;
    vector <double> a(n);
    vector <double> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    double l = 0, r = 1e9 + 1;
    for (int i = 0; i < 100; i++) {
        double mid = (r + l) / 2.00;
        double now = mid + m;
        double t = mid;
        for (int i = 0; i < n; i++) {
            if (t < now / a[i] - EPS) {
                now = -1;
                break;
            }
            t -= now / a[i];
            now -= now / a[i];
            if (t < now / b[(i + 1) % n] - EPS) {
                now = -1;
                break;
            }
            t -= now / b[(i + 1) % n];
            now -= now / b[(i + 1) % n];
        }
        if (now == -1) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (r > 1e9 + EPS) {
        cout << -1;
        return 0;
    }
    cout << fixed << setprecision(10) << r;
    return 0;
}