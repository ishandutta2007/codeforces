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
    int t;
    cin >> t;
    while (t--) {
        map < int, int > start;
        string s;
        cin >> s;
        int bal = 0, pos = 0;
        for (auto c : s) {
            pos++;
            if (c == '+') bal++;
            else bal--;
            if (start.find(bal) == start.end()) start[bal] = pos;
        }
        int ans = 0;
        for (int i = 0; i <= (int)s.size(); ++i) {
            ans += start[-i - 1];
        }
        cout << ans + (int)s.size() << '\n';
    }
    return 0;
}