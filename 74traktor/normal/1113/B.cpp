#include <bits/stdc++.h>

using namespace std;

int a[50005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) ans += a[i];
    int bx = ans;
    for (int d = 2; d <= 100; ++d){
        int x = -1;
        int ind = 0;
        for (int i = 1; i <= n; ++i){
            if (a[i] % d != 0) continue;
            if (a[i] > x){
                x = a[i];
                ind = i;
            }
        }
        if (x == -1) continue;
        int l = 200;
        for (int i = 1; i <= n; ++i){
            if (i == ind) continue;
            else l = min(l, a[i]);
        }
        int tt = bx;
        tt -= (x + l);
        x /= d;
        l *= d;
        tt += (x + l);
        ans = min(ans, tt);
    }
    cout << ans << '\n';
    return 0;
}