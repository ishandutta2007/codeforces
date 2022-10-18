#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r",  stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        int lef = (int)s.size(), righ = -1, cnt = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '1') {
                cnt++;
                righ = i;
                lef = min(lef, i);
            }
        }
        if (cnt == 0) cout << 0 << '\n';
        else {
            cout << righ - lef + 1 - cnt << '\n';
        }
    }
    return 0;
}