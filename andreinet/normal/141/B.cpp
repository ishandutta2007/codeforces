#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int a, x, y;
    cin >> a >> x >> y;

    if (y == 0) {
        cout << "-1\n";
        return 0;
    }

    int i;
    for (i = 1; a * i < y; ++i);

    if (a * i == y) {
        cout << "-1\n";
    } else {
        if (i == 1) cout << (abs(x) * 2 < a ? "1\n": "-1\n");
        else {
            --i;
            if (i % 2 == 1) {
                int k = i + i / 2;
                if (abs(x) * 2 < a) cout << k + 1 << '\n';
                else cout << "-1\n";
            } else {
                int k = i + i / 2;
                if (x == 0 || abs(x) >= a) cout << "-1\n";
                else if (x < 0) cout << k << '\n';
                else cout << k + 1 << '\n';
            }
        }
    }
}