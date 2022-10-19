#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int x[5], y[5];

int sqr(int x) {
    return x * x;
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
#endif

    int n, m;

    cin >> n >> m;


    int x1, x2, y1, y2;
    bool s = false;

    if (n < m) {
        swap(n, m);
        s = !s;
    }

    if (m == 0) {
        swap(n, m);
        s = !s;
    }

    x1 = 0;
    x2 = n;
    y1 = 1;
    y2 = m - 1;


    if (s) {
        swap(x1, y1);
        swap(x2, y2);
        swap(n, m);
    }

    x[0] = x1;
    y[0] = y1;

    x[1] = n;
    y[1] = m;

    x[2] = 0;
    y[2] = 0;

    x[3] = x2;
    y[3] = y2;

    double sum1 = 2 * sqrt(n * n + m * m) + max(n, m);
    double sum2 = 0;

    for (int i = 0; i < 3; ++i)
        sum2 = sum2 + sqrt(sqr(x[i + 1] - x[i]) + sqr(y[i + 1] - y[i]));

    if (n * m == 0 || sum2 > sum1 - (1e-7)) {
        for (int i = 0; i < 4; ++i)
            cout << x[i] << " " << y[i] << "\n";
    }
    else {
        cout << "0 0\n";
        cout << n << " " << m << "\n";
        if (n > m) {
            cout << 0 << " " << m << "\n";
            cout << n << " " << 0 << "\n";
        }
        else {
            cout << n << " " << 0 << "\n";
            cout << 0 << " " << m << "\n";
        }
    }

    return 0;
}