#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, tmp = 1;
    cin >> k;
    for (int i = 20; i >= 0; --i) {
        if ((k >> i) & 1) {
            tmp = (1 << (i + 1));
            break;
        }
    }
    cout << 3 << " " << 3 << "\n";
    cout << k + tmp << " " << k + tmp << " " << tmp << "\n";
    cout << k + tmp << " " << k << " " << k + tmp << "\n";
    cout << tmp << " " << k + tmp << " " << k;
    return 0;
}