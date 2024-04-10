#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn], pref[maxn], inf = 1e9;

int check(int n, int m, int k) {
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];
        if (a[i] >= m) pref[i]++;
        else pref[i]--;
    }
    int imin = inf;
    for (int i = 1; i <= n; ++i) {
        if (i >= k) imin = min(imin, pref[i - k]);
        if (i >= k) {
            if (pref[i] > imin) return 1;
        }
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
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (check(n, m, k)) l = m;
        else r = m;
    }
    cout << l;
    return 0;
}