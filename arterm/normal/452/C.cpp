#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 1010

int n, m;
double p[M];

void kill() {
    cin >> n >> m;
    if (m == 1) {
        cout << 1.0 / n << "\n";
        return;
    }

    if (n == 1) {
        cout << 1.0 << "\n";
        return;
    }

    int t = m * n - m;

    p[0] = 1.0;
    for (int k = 0; k < n; ++k)
        p[0] *= 1.0 * (t - k) / (m * n - k);



    for (int k = 0; k < n && k < m; ++k)
        p[k + 1] = p[k] * (m - k) / (k + 1) * (n - k) / (t - (n - k) + 1);

    double ans = 0;
    for (int k = 0; k <= n && k <= m; ++k)
        ans = ans + k * k * p[k];

    cout << ans / n << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    cout.precision(10);
    cout << fixed;

    kill();

    return 0;
}