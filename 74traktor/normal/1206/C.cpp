#include <bits/stdc++.h>

using namespace std;

int ans[200005];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    //int sum = n * (2 * n + 1);
    if (n % 2 == 0) {
        cout << "NO" << '\n';
    }
    else {
        set < int > Q;
        for (int i = 1; i <= 2 * n; ++i) Q.insert(i);
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                auto p = (*Q.begin());
                Q.erase(p);
                auto t = (*Q.begin());
                Q.erase(t);
                ans[i] = p;
                ans[n + i] = t;
            }
            else {
                auto p = (*Q.rbegin());
                Q.erase(p);
                auto t = (*Q.rbegin());
                Q.erase(t);
                ans[i] = p;
                ans[n + i] = t;
            }
        }
        cout << "YES" << '\n';
        for (int i = 1; i <= 2 * n; ++i) cout << ans[i] << " ";
    }
    return 0;
}