#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = 1e18;
    for (int i = 1; i <= n; ++i){
        if (n % i != 0) continue;
        int x = i, y = n / i;
        if (y >= k) continue;
        ans = min(ans, k * x + y);
    }
    cout << ans << endl;
    return 0;
}