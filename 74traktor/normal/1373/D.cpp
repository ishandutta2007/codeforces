#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5;
int a[maxn];
int pref[2][maxn];

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
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ans = 0, sum = 0;
        for (int i = 1; i <= n; i += 2) {
            ans += a[i], sum += a[i];
        }
        multiset < int > Q1, Q2;
        for (int i = 1; i <= n; ++i) {
            pref[0][i] = pref[0][i - 1], pref[1][i] = pref[1][i - 1];
            if (i % 2 == 1) {
                pref[0][i] -= a[i], pref[1][i] -= a[i];
            }
            else {
                pref[0][i] += a[i], pref[1][i] += a[i];
            }
            if (i % 2 == 0) Q2.insert(pref[1][i]);
            else Q1.insert(pref[0][i]);
        }
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 1) {
                if ((int)Q2.size() > 0) ans = max(ans, sum + (*Q2.rbegin()) - pref[1][i - 1]);
            }
            else {
                if ((int)Q1.size() > 0) ans = max(ans, sum + (*Q1.rbegin()) - pref[0][i - 1]);
            }
            if (i % 2 == 0) Q2.erase(Q2.find(pref[1][i]));
            else Q1.erase(Q1.find(pref[0][i]));
        }
        cout << ans << '\n';
    }
    return 0;
}