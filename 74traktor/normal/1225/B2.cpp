#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    int ans = n + 7;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    set < int > T;
    map < int, int > cnt;
    for (int i = 1; i <= n; ++i) {
        T.insert(a[i]);
        cnt[a[i]]++;
        if (i >= d) {
            ans = min(ans, (int)T.size());
            cnt[a[i - d + 1]]--;
            if (cnt[a[i - d + 1]] == 0) T.erase(a[i - d + 1]);
        }
    }
    cout << ans << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}