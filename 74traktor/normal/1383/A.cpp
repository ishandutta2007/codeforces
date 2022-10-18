#include<bits/stdc++.h>

using namespace std;

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
        string A, B;
        cin >> n;
        cin >> A >> B;
        int f = 1;
        for (int i = 0; i < n; ++i) {
            if (A[i] > B[i]) f = 0;
        }
        if (!f) {
            cout << -1 << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            bitset < 27 > good;
            for (int j = 0; j < n; ++j) {
                if (A[j] == B[j]) continue;
                if (B[j] == char('a' + i)) {
                    good[A[j] - 'a'] = 1;
                }
            }
            ans += good.count();
            for (int j = 0; j < n; ++j) {
                if (A[j] == B[j]) continue;
                if (good[A[j] - 'a'] == 1) A[j] = char('a' + i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}