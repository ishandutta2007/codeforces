#include <iostream>
#include <cmath>

using namespace std;

long double dist(int x0, int y0, int x1, int y1) {
    return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    if(n == 0) {
        cout << n << ' ' << 1 << '\n'
             << n << ' ' << m << '\n'
             << n << ' ' << 0 << '\n'
             << n << ' ' << m - 1 << '\n';
        return 0;
    }
    if(m == 0) {
        cout << 1 << ' ' << m << '\n'
             << n << ' ' << m << '\n'
             << 0 << ' ' << m << '\n'
             << n - 1 << ' ' << m << '\n';
        return 0;
    }
    long double d = 2 * dist(0, 0, n, m) + max(n, m),
        d0 = 2 * dist(1, 0, n, m) + dist(0, 0, n, m),
        d1 = 2 * dist(0, 1, n, m) + dist(0, 0, n, m);
    if(d > d0 && d > d1) {
        cout << 0 << ' ' << 0 << '\n'
             << n << ' ' << m << '\n';
        if(n > m)
            cout << 0 << ' ' << m << '\n'
                 << n << ' ' << 0 << '\n';
        else
            cout << n << ' ' << 0 << '\n'
                 << 0 << ' ' << m << '\n';
    }
    else if(d0 > d1)
        cout << 1 << ' ' << 0 << '\n'
             << n << ' ' << m << '\n'
             << 0 << ' ' << 0 << '\n'
             << n - 1 << ' ' << m << '\n';
    else
        cout << 0 << ' ' << 1 << '\n'
             << n << ' ' << m << '\n'
             << 0 << ' ' << 0 << '\n'
             << n << ' ' << m - 1 << '\n';
    return 0;
}