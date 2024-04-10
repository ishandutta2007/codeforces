#include<bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (min(n, m) == 1 || n + m <= 4) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}