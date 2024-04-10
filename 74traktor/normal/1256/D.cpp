#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') cnt1++;
        else {
            int go = cnt1;
            if (go <= k) {
                cnt0++;
                k -= go;
            }
            else {
                for (int j = 0; j < cnt0; ++j) cout << "0";
                for (int j = 0; j < cnt1 - k; ++j) cout << "1";
                cout << "0";
                for (int j = 0; j < k; ++j) cout << "1";
                for (int j = i + 1; j < n; ++j) cout << s[j];
                cout << '\n';
                return;
            }
        }
    }
    cnt0 = 0, cnt1 = 0;
    for (auto c : s) {
        if (c == '0') cnt0++;
        else cnt1++;
    }
    for (int i = 0; i < cnt0; ++i) {
        cout << "0";
    }
    for (int i = 0; i < cnt1; ++i) {
        cout << "1";
    }
    cout << '\n';
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}