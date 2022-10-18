#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
pair < int, int > a[maxn];
int suff[maxn];

inline int get_s(int l, int r, int i, int f) {
    if (i < max(l, r - f + 1)) {
        return suff[max(l, r - f + 1)];
    }
    else {
        return suff[max(l, r - f)] - a[i].first;
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, ans = 0, mx = 0, s = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) cin >> a[i].first >> a[i].second;
        sort(a + 1, a + m + 1);
        suff[m + 1] = 0;
        for (int i = m; i >= 1; --i) suff[i] = suff[i + 1] + a[i].first;
        for (int i = 1; i <= m; ++i) {
            pair < int, int > cur = {a[i].second + 1, -1};
            int pos = upper_bound(a + 1, a + m + 1, cur) - a;
            int cnt = n - 1 - (m - pos + 1);
            if (pos <= i) cnt++;
            cnt = max(0ll, cnt);
            ans = max(ans, a[i].first + get_s(pos, m, i, n - 1) + cnt * a[i].second);
        }
        cout << ans << '\n';
    }
    return 0;
}