#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int getCoord(int x, int l, int n) {
    int c = x - (l + 1) / 2;
    if (c < 0) c = 0;
    if (c + l > n) c = n - l;
    return c;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y >> a >> b;

    int g = __gcd(a, b);
    a /= g;
    b /= g;
    int d = min(n / a, m / b);
    int lx = d * a, ly = d * b;

    int cx = getCoord(x, lx, n);
    int cy = getCoord(y, ly, m);

    cout << cx << ' ' << cy << ' ' << cx + lx << ' ' << cy + ly << '\n';
}