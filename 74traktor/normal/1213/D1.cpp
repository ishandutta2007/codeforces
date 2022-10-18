#include <bits/stdc++.h>

using namespace std;

int a[200005];
vector < int > cnt[200005];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int ok = 0;
        while (a[i] > 0) {
            cnt[a[i]].push_back(ok);
            ok++;
            a[i] /= 2;
        }
        cnt[0].push_back(ok);
    }
    int ans = 1000 * 1000 * 1000;
    for (int i = 0; i <= 200000; ++i) {
        if ((int)cnt[i].size() < k) continue;
        sort(cnt[i].begin(), cnt[i].end());
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += cnt[i][j];
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
    return 0;
}