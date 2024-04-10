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
        if (x < 9) cout << 0 << '\n';
        else cout << (x - 9) / 10 + 1 << '\n';
    }

    return 0;
}