#include<bits/stdc++.h>

using namespace std;

int a, b;

main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, a, b, x = 1, flag = 0;
        cin >> n >> a >> b;
        for (int i = 1; i <= 30 && x <= n; ++i) {
            if ((n - x) % b == 0) {
                flag = 1;
            }
            x *= a;
        }
        if (flag) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}