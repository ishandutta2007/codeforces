#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[305];
int inf = 1e9;

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, x;
    bool flag;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> n;
        int imin = inf, imax = -inf;
        for (int j = 1; j <= n; ++j){
            cin >> a[j];
            imin = min(imin, a[j]);
            imax = max(imax, a[j]);
        }
        int ans = imin * imax;
        flag = true;
        for (int j = 1; j <= n; ++j){
            if (ans % a[j] != 0) flag = false;
        }
        int cnt = 0, ans1 = ans;
        int d = 1;
        int j = 2;
        while (j * j <= ans1){
            cnt = 0;
            while (ans1 % j == 0){
                cnt++;
                ans1 /= j;
            }
            ++j;
            d *= (cnt + 1);
        }
        if (ans1 != 1) d *= 2;
        if (d == n + 2 && flag) cout << ans << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}