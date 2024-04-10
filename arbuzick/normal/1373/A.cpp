#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a < c)
            cout << 1 << ' ';
        else
            cout << -1 << ' ';
        if (a * b > c)
            cout << b << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}