#include <bits/stdc++.h>

using namespace std;

#define long long long

const int M = 200200;

const double B = 100000;
const double eps = 1e-9;

int n, a[M];
double b[M], pref[M];

void read() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

double get(double x) {
    for (int i = 1; i <= n; ++i)
        b[i] = a[i] - x;
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + b[i];
    double mn = 0, mx = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, max(fabs(pref[i] - mn), fabs(pref[i] - mx)));
        mn = min(mn, pref[i]);
        mx = max(mx, pref[i]);
    }
    return ans;
}

void kill() {
    double l = -B, r = B;
    for (int i = 0; i < 160; ++i) {
        double m1 = (2 * l + r) / 3;
        double m2 = (l + 2 * r) / 3;
        if (get(m1) + eps < get(m2))
            r = m2;
        else
            l = m1;
    }
    cout << get(l) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(9);
    cout << fixed;
    read();
    kill();
    return 0;
}