#include <bits/stdc++.h>

using namespace std;

int a[105];

main(){
    //freopen("input.txt", "r", stdin):
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, k;
    cin >> q;
    for (int i = 1; i <= q; ++i){
        cin >> n >> k;
        for (int j = 1; j <= n; ++j) cin >> a[j];
        int imin = 1e9, imax = -1;
        for (int j = 1; j <= n; ++j){
            imin = min(imin, a[j]);
            imax = max(imax, a[j]);
        }
        if (imin + k < imax - k) cout << -1 << '\n';
        else cout << imin + k << '\n';
    }
    return 0;
}