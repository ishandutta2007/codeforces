#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[200005];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, k;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> n >> k;
        for (int j = 1; j <= n; ++j) cin >> a[j];
        vector < int > out;
        int sum = 0;
        for (int j = 1; j <= n; ++j) {
            sum += a[j];
            if (k > 1 && sum % 2 == 1) {
                out.push_back(j);
                k--;
                sum = 0;
            }
        }
        if (k == 1 && sum % 2 == 1) {
            out.push_back(n);
            cout << "YES" << '\n';
            for (auto key : out) cout << key << " ";
            cout << '\n';
        }
        else cout << "NO" << '\n';
    }
    return 0;
}