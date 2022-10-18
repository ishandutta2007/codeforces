#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int a[maxn], pref[maxn], suff[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, l, r;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        pref[i] = pref[i - 1] + max(0ll, a[i - 1] - a[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        suff[i] = suff[i + 1] + max(0ll, a[i + 1] - a[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        if (l <= r) cout << pref[r] - pref[l] << '\n';
        else cout << suff[r] - suff[l] << '\n';
    }
    return 0;
}