#include<bits/stdc++.h>

using namespace std;

main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long c = abs(a - b);
        if (c == 0) {
            cout << 0 << " " << 0 << '\n';
        }
        else {
            cout << c << " " << min(a % c, c - a % c) << '\n';
        }
    }
}