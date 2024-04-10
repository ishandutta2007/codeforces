#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

#define int li

void answer(int p, int q, int b) {
    if (p == 0) {
        cout << "Finite\n";
        return;
    }

    int a = __gcd(p, q);
    p /= a;
    q /= a;

    int x = __gcd(q, b);
    while (x != 1) {
        while (q % x == 0) {
            q /= x;
        }

        x = __gcd(q, x);
    }

    if (q != 1) {
        cout << "Infinite\n";
    }
    else {
        cout << "Finite\n";
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int p, q, b;
        cin >> p >> q >> b;

        answer(p, q, b);
    }

    return 0;
}