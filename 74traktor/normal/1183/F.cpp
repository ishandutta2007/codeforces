#include <bits/stdc++.h>

using namespace std;

int a[200005];
int b[200005];
int lef[200005];

main(){
    //freopen("input.txt", "r", stdin):
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, k;
    cin >> q;
    for (int i = 1; i <= q; ++i){
        cin >> n;
        for (int j = 1; j <= n; ++j){
            cin >> b[j];
        }
        sort(b + 1, b + n + 1);
        k = 1;
        int ans = b[n];
        for (int j = 1; j <= n; ++j){
            if (b[j] != b[j - 1]) a[k++] = b[j];
        }
        k--;
        lef[1] = 0;
        for (int j = 2; j <= k; ++j){
            int uk = j - 1;
            while (uk > 0 && a[j] % a[uk] == 0) uk = lef[uk];
            lef[j] = uk;
            if (lef[uk] != 0 && a[j] % a[lef[uk]] != 0) ans = max(ans, a[j] + a[uk] + a[lef[uk]]);
            else{
                int xx = a[uk];
                uk = lef[uk];
                while (uk > 0 && (a[j] % a[uk] == 0 || xx % a[uk] == 0)) uk = lef[uk];
                ans = max(ans, a[j] + xx + a[uk]);
            }
        }
        k--;
        cout << ans << '\n';
    }
    return 0;
}