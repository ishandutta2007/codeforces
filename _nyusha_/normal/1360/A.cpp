#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        for (int ans = max(a, b); ans <= 200; ++ans) {
            if (2 * a <= ans || 2 * b <= ans) {
                cout << ans * ans << '\n';
                break;
            }
        }
    }
    return 0;
}