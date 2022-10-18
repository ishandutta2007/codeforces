#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int cnt[maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, x, ans = 0;
    cin >> n >> m;
    vector < vector < int > > a;
    for (int i = 1; i <= n; ++i) {
        a.emplace_back();
        for (int j = 1; j <= m; ++j) {
            cin >> x;
            a.back().push_back(x);
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) cnt[i] = n;
        for (int i = 0; i < n; ++i) {
            int s = a[i][j] % m, go = (j + 1) % m;
            if (s == go && a[i][j] <= n * m) {
                int pos = (a[i][j] - 1) / m;
                if (pos <= i) cnt[i - pos]--;
                else cnt[n + i - pos]--;
            }
        }
        int imin = n;
        for (int i = 0; i < n; ++i) imin = min(imin, cnt[i] + i);
        ans += imin;
        //cout << imin << '\n';
    }
    cout << ans << '\n';
    return 0;
}