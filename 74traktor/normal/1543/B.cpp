#include<bits/stdc++.h>

using namespace std;

main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, sum = 0, x;
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            cin >> x;
            sum = (sum + x) % n;
        }
        cout << (long long)sum * (long long)(n - sum) << '\n';
    }
}