#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e5 + 5;
vector < int > g[maxn];
int dp[maxn], a[maxn];

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
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            g[i] = {};
        }
        for (int i = 1; i <= n; i++) g[a[i]].push_back(i);
        for (int i = 1; i <= n; i++) {
            int x0 = 0, x1 = 0;
            for (auto key : g[i]) {
                if (key % 2 == 0) {
                    x0 = max(x0, x1 + 1);
                } else x1 = max(x1, x0 + 1);
            }
            cout << max(x0, x1) << " ";
        }
        cout << '\n';
    }
    return 0;
}