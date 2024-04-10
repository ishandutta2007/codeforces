#include<bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        cout << s / ((n + 2) / 2) << '\n';
    }
    return 0;
}