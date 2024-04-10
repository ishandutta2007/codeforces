#include<bits/stdc++.h>

using namespace std;

main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        int even = 0, odd = 0;
        for (int i = 1; i <= 2 * n; ++i) {
            cin >> x;
            if (x % 2 == 0) even++;
            else odd++;
        }
        if (even == odd) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}