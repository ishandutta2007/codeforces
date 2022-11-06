#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f( int offset,  int n,  ll l,  ll r) {
    for(int offset = 1;;) {
        if (l > r || n == 1)
            break;

        const int c = 2 * (n - 1);

        if (r >= 1 && l <= c) {
            for (int i = 1; i <= c; ++i)
                if (l <= i && i <= r)
                    cout << (i & 1 ? offset : i / 2 + offset) << ' ';
        }

        offset++;
        n--;
        l -= c;
        r -= c;
    }
}

void f() {
    ll n, l, r;
    cin >> n >> l >> r;
    f(1, (int) n, l, r);
    if (r == n * (n - 1LL) + 1LL)
        cout << 1;
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        f();
    return 0;
}