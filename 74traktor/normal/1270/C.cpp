#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int cnt[65];
int a[maxn];
int s = 5000, maxc = 1e17;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int sum = 0, t = 0;
        for (int i = 1; i <= n; ++i) {
            sum += a[i];
            t = (t^a[i]);
        }
        if (sum == 2 * t) {
            cout << 0 << '\n';
            cout << '\n';
            continue;
        }
        for (int big = maxc - s; big <= maxc + s; ++big) {
            if ((t^big) * 2 > sum + big && (2 * (t^big) - sum - big) % 2 == 0) {
                cout << 3 << '\n';
                cout << big << " " << (2 * (t^big) - sum - big) / 2 << " " << (2 * (t^big) - sum - big) / 2 << '\n';
                break;
            }
        }
    }
    return 0;
}