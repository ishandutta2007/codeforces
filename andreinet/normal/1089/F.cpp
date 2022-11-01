#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            res /= i;
            res *= i - 1;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n >= 2) {
        res /= n;
        res *= n - 1;
    }
    return res;
}

int Pow(int x, int y, int m) {
    int res = 1;
    for (; y > 0; y /= 2) {
        if (y & 1) {
            res = (int64_t) res * x % m;
        }
        x = x * (int64_t) x % m;
    }
    return res;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if (phi(n) == n - 1) {
        cout << "NO\n";
    } else {
        int d = -1;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                d = i;
                break;
            }
        }
        int p = d, q = n / d;
        while (q % d == 0) {
            q /= d;
            p *= d;
        }
        if (q != 1) {
            cout << "YES\n";
            cout << 2 << '\n';
            int A = (p - 1) * (int64_t) Pow(q, phi(p) - 1, p) % p;
            int B = (q - 1) * (int64_t) Pow(p, phi(q) - 1, q) % q;
            cout << A << ' ' << p << '\n';
            cout << B << ' ' << q << '\n';
        } else {
            cout << "NO\n";
        }
    }
}