#include <bits/stdc++.h>

using namespace std;

#define int long long
int pref[300005];

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, x;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    int ans = pref[n] * k;
    sort(pref + 1, pref + n);
    for (int i = 1; i <= k - 1; ++i){
        ans -= pref[i];
    }
    cout << ans << '\n';
    return 0;
}