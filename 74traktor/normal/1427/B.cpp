#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k, ans = 0;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        string s;
        cin >> s;
        ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'W') {
                ans++;
                if (i > 0 && s[i - 1] == 'W') ans++;
            }
        }
        vector < pair < int, int > > ok;
        int pref = 0, suff = 0;
        while (pref < n && s[pref] == 'L') pref++;
        while (suff < n && s[n - suff - 1] == 'L') suff++;
        if (pref == n) {
            if (k == 0) cout << 0 << '\n';
            else cout << 1 + 2 * (k - 1) << '\n';
            continue;
        }
        int l = pref, cnt = 0;
        for (auto c : s) if (c == 'L') cnt++;
        while (l < n - suff) {
            if (s[l] == 'W') {
                l++;
                continue;
            }
            int r = l;
            while (r < n && s[r] == 'L') ++r;
            r--;
            ok.push_back({r - l + 1, 2 * (r - l + 1) + 1});
            l = r + 1;
        }
        sort(ok.begin(), ok.end());
        for (auto key : ok) {
            if (k >= key.first) {
                k -= key.first, ans += key.second;
                cnt -= key.first;
            }
        }
        cout << ans + 2 * min(k, cnt) << '\n';
    }
    return 0;
}