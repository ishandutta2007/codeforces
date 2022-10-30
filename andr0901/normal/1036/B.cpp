#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long x, y, k;
        cin >> x >> y >> k;
        if (k < max(x, y)) {
            cout << -1 << "\n";
            continue;
        }
        if ((x + y) % 2) {
            k--;
            if (max(x - 1, y) % 2 != k % 2 && max(x, y - 1) % 2 != k % 2) k -= 2;
        }
        else {
            if (max(x, y) % 2 != k % 2) k -= 2;
        }
        if (k >= 0) cout << k << "\n";
        else cout << 0;
    }
    return 0;
}