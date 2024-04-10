#include <bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, u;
    cin >> t;
    bool f;
    for (int i = 0; i < t; ++i){
        cin >> u;
        f = true;
        for (int n = 3; n <= 1e6; ++n){
            if (!f) break;
            if (180 * (n - 2) / n < u) continue;
            for (int k = 1; k < n; ++k){
                if (!f) break;
                if (u == 180 * k / n && (180 * k) % n == 0){
                    cout << n << '\n';
                    f = false;
                }
            }
        }
    }
    return 0;
}