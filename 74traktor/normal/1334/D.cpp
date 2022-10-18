#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, l, r, cur;
    cin >> t;
    while (t--) {
        cur = 0;
        cin >> n >> l >> r;
        for (int i = 1; i < n; ++i) {
            int L = cur, R = cur + 2 * (n - i - 1) + 1;
            for (int j = max(L, l); j <= min(R, r); ++j) {
                if (j == L) cout << n << ' ';
                else if ((j - L) % 2 == 1) cout << i << ' ';
                else cout << i + (j - L) / 2 << " ";
            }
            cur = R + 1;
        }
        vector < pair < int, int > > Q = {{n, n * (n - 1)}, {1, n * (n - 1) + 1}};
        for (auto key : Q) {
            if (l <= key.second && key.second <= r) cout << key.first << " ";
        }
        cout << '\n';
    }
    return 0;
}