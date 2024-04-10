#include<bits/stdc++.h>

using namespace std;

int a[105], b[105];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    int l = 0, r = 1000;
    while (r - l > 1) {
        int mid = (r + l) / 2, ok = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == b[i]) continue;
            if (a[i]) ok += mid;
            else ok -= 1;
        }
        if (ok > 0) r = mid;
        else l = mid;
    }
    if (r == 1000) cout << -1;
    else cout << r;
    return 0;
}