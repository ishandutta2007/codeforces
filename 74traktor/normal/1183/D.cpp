#include <bits/stdc++.h>

using namespace std;

#define int long long
int cnt[200005];
int cur[200005];

main(){
    //freopen("input.txt", "r", stdin):
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n, x;
    cin >> q;
    for (int i = 1; i <= q; ++i){
        cin >> n;
        for (int j = 1; j <= n; ++j) cnt[j] = 0, cur[j] = 0;
        for (int j = 1; j <= n; ++j){
            cin >> x;
            cnt[x]++;
        }
        for (int j = 1; j <= n; ++j) cur[cnt[j]]++;
        int ans = 0;
        for (int j = n; j >= 1; --j){
            if (cur[j] > 0){
                ans += j;
                cur[j - 1] += (cur[j] - 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}