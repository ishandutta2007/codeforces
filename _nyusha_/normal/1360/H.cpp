#include<bits/stdc++.h>

using namespace std;

#define int long long

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector < int > a;
        for (int i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            int x = 0;
            for (auto c : s) x = x * 2 + c - '0';
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        int go = ((1ll << m) - n + 1) / 2, last = 0;
        for (auto key : a) {
            if (key - last >= go) {
                last += (go - 1);
                for (int j = m - 1; j >= 0; --j) {
                    if ((last&(1ll << j)) > 0) cout << 1;
                    else cout << 0;
                }
                cout << '\n';
                go = 0;
                break;
            }
            else go -= (key - last);
            last = key + 1;
        }
        if (go > 0) {
            last = last + go - 1;
            for (int j = m - 1; j >= 0; --j) {
                if ((last&(1ll << j)) > 0) cout << 1;
                else cout << 0;
            }
            cout << '\n';
        }
    }
    return 0;
}