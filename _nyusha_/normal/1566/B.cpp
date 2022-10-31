#include<bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string t = s;
        sort(t.begin(), t.end());
        if (t[0] == t.back() && t[0] == '1') cout << 0 << '\n';
        else {
            char lst = 'a';
            int block0 = 0, block1 = 0;
            for (auto c : s) {
                if (c != lst) {
                    if (c == '0') block0++;
                    else block1++;
                }
                lst = c;
            }
            cout << min(2, block0) << '\n';
        }
    }
    return 0;
}