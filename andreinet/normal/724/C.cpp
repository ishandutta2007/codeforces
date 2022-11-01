#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

const int64_t INF = 1LL << 62;

int64_t gcd(int64_t a, int64_t b) {
    while (b) {
        int64_t c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int64_t extGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        int64_t x0, y0;
        int64_t d = extGcd(b, a % b, x0, y0);
 
        x = y0;
        y = x0 - (a / b) * y0;
 
        return d;
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int64_t n, m, q;
    cin >> n >> m >> q;

    while (q-- > 0) {
        int64_t x, y;
        cin >> x >> y;

        if (n == m) {
            if (x == y) {
                cout << x << '\n';
            } else {
                cout << "-1\n";
            }
        } else if (x == y) {
            cout << x << '\n';
        } else {
            int64_t l = n / gcd(n, m) * m;
            int64_t ans = INF;
            for (int s1: {1, -1}) {
                for (int s2: {1, -1}) {
                    int64_t c = y * s2 - x * s1;
                    int64_t j, k, d;
                    if (c % 2 != 0) {
                        continue;
                    }
                    d = extGcd(n, m, j, k);
                    if (c % d == 0) {
                        j *= c / d;
                        k *= -c / d;
                        int64_t t = j * n + x * s1;
                        t %= l;
                        while (t < 0) {
                            t += l;
                        }
                        j = (t - x * s1) / n;
                        k = (t - y * s2) / m;
                        if (j % 2 == 0 && k % 2 == 0) {
                            ans = min(ans, t);
                        }
                    }
                }
            }
            if (ans == INF) {
                ans = -1;
            }
            cout << ans << '\n';
        }
    }
}