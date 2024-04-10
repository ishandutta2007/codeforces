#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        int n = 2 * abs(a - b);
        if (max({a, b, c}) + 1 > n) cout << -1 << '\n';
        else cout << (c + abs(a - b)) % n + 1 << '\n';
    }

    return 0;
}