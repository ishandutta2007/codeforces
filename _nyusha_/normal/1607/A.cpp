#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string al, s;
        cin >> al >> s;
        map < char, int > pos;
        for (int i = 0; i < (int)al.size(); ++i) pos[al[i]] = i;
        int ans = 0;
        for (int i = 1; i < (int)s.size(); ++i) {
            ans += abs(pos[s[i - 1]] - pos[s[i]]);
        }
        cout << ans << '\n';
    }
    return 0;
}