#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        while (n % 2 == 0) n /= 2;
        if (n == 1) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}