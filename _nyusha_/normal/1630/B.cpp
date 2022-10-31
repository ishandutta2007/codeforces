#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
int cnt[maxn], pref[maxn], b[maxn], f[maxn];

inline int check(int n, int m, int k) {
    for (int r = m + 1; r <= n; ++r) {
        if (2 * (pref[r] - pref[r - m - 1]) - n >= k) return 1;
    }
    return 0;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) cnt[i] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + cnt[i];
        int l = -1, r = n + 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (check(n, m, k)) r = m;
            else l = m;
        }
        int y = r + 1;
        while (2 * (pref[y] - pref[y - r - 1]) - n < k) y++;
        int x = y - r;
        cout << x << " " << y << '\n';
        for (int i = 1; i <= n; ++i) {
            if (x <= a[i] && a[i] <= y) b[i] = 1;
            else b[i] = -1;
            f[i] = f[i - 1] + b[i];
        }
        vector < pair < int, int > > ans;
        int now = 1;
        while ((int)ans.size() < k - 1) {
            int val = f[now - 1] + 1;
            int pos = now;
            while (f[pos] != val) pos++;
            ans.push_back({now, pos});
            now = pos + 1;
        }
        ans.push_back({now, n});
        for (auto key : ans) cout << key.first << " " << key.second << '\n';
    }
    return 0;
}