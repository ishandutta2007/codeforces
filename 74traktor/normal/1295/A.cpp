#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2 == 1) {
            cout << "7";
            n -= 3;
        }
        for (int i = 1; i <= n / 2; ++i) cout << "1";
        cout << '\n';
    }
    return 0;
}