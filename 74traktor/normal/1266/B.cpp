#include<bits/stdc++.h>

using namespace std;

#define int long long

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x <= 21) {
            if (x >= 15 && x != 21) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else {
            int cnt = x / 14, ok = 0;
            for (int j = cnt - 25; j <= cnt + 25; ++j) {
                if (j <= 1) continue;
                if (x - 14 * j > 0 && x - 14 * j < 7) ok = 1;
            }
            if (ok) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}