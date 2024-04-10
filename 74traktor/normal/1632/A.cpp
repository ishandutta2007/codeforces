#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        string s;
        cin >> n >> s;
        int cnt0 = 0, cnt1 = 0;
        for (auto c : s) {
            if (c == '0') cnt0++;
            else cnt1++;
        }
        if ((int)s.size() == 1 || ((int)s.size() == 2 && cnt0 == cnt1)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}