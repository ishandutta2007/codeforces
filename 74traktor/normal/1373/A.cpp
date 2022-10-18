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
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        if (c <= a) cout << -1 << ' ';
        else cout << 1 << " ";
        if (a * b <= c) cout << -1;
        else cout << b;
        cout << '\n';
    }
    return 0;
}