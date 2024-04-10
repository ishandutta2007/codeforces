#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int x;
        cin >> x;
        int res = 0;
        while (x) {
            res = max(res, x % 10);
            x /= 10;
        }
        cout << res << '\n';
    }

    return 0;
}