#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        if (n % 2050) {
            cout << -1 << '\n';
            continue;
        }
        n /= 2050;
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        cout << res << '\n';
    }

    return 0;
}