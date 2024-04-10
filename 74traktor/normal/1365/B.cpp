#include<bits/stdc++.h>

using namespace std;

int a[505], b[505];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        int ok = 1;
        for (int i = 2; i <= n; ++i) {
            if (a[i - 1] > a[i]) ok = 0;
        }
        sort(b + 1, b + n + 1);
        if (ok || b[1] != b[n]) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}