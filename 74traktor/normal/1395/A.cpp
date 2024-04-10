#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, r, g, b, w;
    cin >> t;
    while (t--) {
        cin >> r >> g >> b >> w;
        vector < int > a = {r, g, b, w};
        int cnt = 0;
        for (auto key : a) if (key % 2 == 1) cnt++;
        if (cnt <= 1) {
            cout << "YES" << '\n';
            continue;
        }
        if (min({r, g, b}) >= 1) {
            for (int j = 0; j < 3; ++j) a[j]--;
            a[3]++;
        }
        cnt = 0;
        for (auto key : a) {
            if (key % 2 == 1) cnt++;
        }
        if (cnt <= 1) {
            cout << "YES" << '\n';
            continue;
        }
        cout << "NO" << '\n';
    }
    return 0;
}