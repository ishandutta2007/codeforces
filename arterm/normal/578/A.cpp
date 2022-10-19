#include <bits/stdc++.h>

using namespace std;

#define long long long

long a, b;

double pos(long a, long b) {
    long k = (a - b) / (2 * b);
    if (k == 0)
        return -1.0;
    return (a - b) * 1.0 / (2.0 * k);
}

double neg(long a, long b) {
    long k = (a + b) / (2 * b);
    if (k <= 0)
        return -1.0;
    return (a + b) * 1.0 / (2 * k);
}

int main() {
    cout.precision(9);
    cout << fixed;

    cin >> a >> b;
    if (a < b) {
        cout << "-1\n";
        return 0;
    }

    if (a == b) {
        cout << 1.0 * a << "\n";
        return 0;
    }

    double ans = 1e10;
    if (pos(a, b) > 0)
        ans = min(ans, pos(a, b));
    if (neg(a, b) > 0)
        ans = min(ans, neg(a, b));

    if (ans < 0.5e10)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}