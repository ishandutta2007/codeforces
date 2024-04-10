#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;
        int res = 1;
        while (2 * res <= n) res = res * 2;
        cout << res - 1 << endl;
    }

    return 0;
}