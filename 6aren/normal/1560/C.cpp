#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int sum = 0;
        int k;
        cin >> k;
        int cur = 1;
        int y = 1;
        while (sum < k) {
            sum += cur;
            cur += 2;
            y++;
        }
        cur -= 2;
        y--;
        if (k + y - 1 >= sum) {
            int x = y;
            y = 0 + sum - k + 1; 
            cout << x << ' ' << y << '\n';
        } else {
            sum -= cur;
            cout << k - sum << ' ' << y << '\n';
        }
    }

    return 0;
}