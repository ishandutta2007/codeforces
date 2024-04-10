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
    int t, n, x, X;
    cin >> t;
    while (t--) {
        cin >> n >> X;
        multiset < int > Q;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            Q.insert(x);
        }
        int ans = 0;
        while ((int)Q.size()) {
            auto p = (*Q.begin());
            Q.erase(Q.begin());
            if (Q.find(p * X) != Q.end()) {
                Q.erase(Q.find(p * X));
            } else ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}