#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 1010;

struct Point {
    ld x, y;

    Point operator-(const Point &to) const {
        return Point{x - to.x, y - to.y};
    }

    ld operator%(const Point &to) const {
        return x * to.y - y * to.x;
    }

    ld abs2() const {
        return x * x + y * y;
    }

    ld abs() const {
        return sqrtl(abs2());
    }
};

int n;
Point p[M];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[i] = Point{x, y};
    }
    p[n] = p[0];
    p[n + 1] = p[1];
}

void kill() {
    ld ans = 2e9;
    for (int i = 0; i < n; ++i) {
        Point A = p[i];
        Point B = p[i + 1];
        Point C = p[i + 2];
        A = A - B;
        C = C - B;
        ld area = fabsl(A % C);
        ld h = area / (A - C).abs();
        ans = min(ans, h / 2);
    }
    cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  cout.precision(10);
  cout << fixed;

  read();
  kill();

}