#include <iostream>

using namespace std;

const int INF = 1000 * 1000 * 1000 + 5;

int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;
    int g = gcd(a, b);
    a /= g;
    b /= g;
    int l = 1, r = INF;
    while(l < r - 1) {
        int mid = (l + r) / 2;
        long long w = (long long)mid * a, h = (long long)mid * b;
        if(w > n || h > m)
            r = mid;
        else
            l = mid;
    }
    int x2 = x + (l * a) / 2, y2 = y + (l * b) / 2,
        x1 = x2 - l * a, y1 = y2 - l * b;
    if(x2 > n) {
        x1 -= x2 - n;
        x2 = n;
    }
    if(x1 < 0) {
        x2 -= x1;
        x1 = 0;
    }
    if(y2 > m) {
        y1 -= y2 - m;
        y2 = m;
    }
    if(y1 < 0) {
        y2 -= y1;
        y1 = 0;
    }
    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    return 0;
}