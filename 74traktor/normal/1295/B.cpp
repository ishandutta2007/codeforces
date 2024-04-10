#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, x, ans = 0, cnt = 0, n;
    cin >> t;
    while (t--) {
        string s;
        cin >> n >> x;
        cin >> s;
        //cin >> x;
        ans = 0, cnt = 0;
        for (auto c : s) {
            if (c == '0') cnt++;
            else cnt--;
        }
        if (cnt == 0) {
            int R = 0, L = 0;
            for (auto c : s) {
                if (c == '0') cnt++;
                else cnt--;
                R = max(R, cnt);
                L = min(L, cnt);
            }
            if (L <= x && x <= R) cout << -1 << '\n';
            else {
                cout << 0 << '\n';
            }
            continue;
        }
        int was = cnt;
        cnt = 0;
        for (auto c : s) {
            if (c == '0') cnt++;
            else cnt--;
            int k = x - cnt;
            if (k * was >= 0 && abs(k) % abs(was) == 0) ans++;
        }
        if (x == 0) ans++;
        cout << ans << '\n';
    }
    return 0;
}