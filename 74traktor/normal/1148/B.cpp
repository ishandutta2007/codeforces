#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[200005];
int b[200005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    if (k >= n || k >= m){
        cout << -1 << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 0; i <= min(n, k); ++i){
        int to = a[i + 1];
        int l = 0, r = m + 1;
        while (r - l > 1){
            int mid = (r + l) / 2;
            if (b[mid] >= to + ta) r = mid;
            else l = mid;
        }
        int can = k - i;
        if (r + can > m){
            cout << -1 << '\n';
            return 0;
        }
        ans = max(ans, b[r + can] + tb);
    }
    cout << ans << '\n';
    return 0;
}