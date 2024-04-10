#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[200005];

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) a[i] = abs(a[i]);
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int lef = 0, righ = n + 1;
        while (righ - lef > 1){
            int mid = (righ + lef) / 2;
            if (a[mid] <= 2 * a[i]) lef = mid;
            else righ = mid;
        }
        ans += (lef - i);
    }
    cout << ans << '\n';
    return 0;
}