#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef karpovich
    freopen("input.txt", "r", stdin);
#endif // karpovich
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, s, n;
    cin >> t;
    while (t--) {
        cin >> s >> n;
        if (n == 1) {
            cout << s << '\n';
            continue;
        }
        vector < int > ans(n, 1);
        s -= n;
        for (int pw = 8; pw >= 0; --pw) {
            vector < pair < int, pair < int, int > > > need;
            int val = pow(10, pw);
            for (int i = 0; i < n; ++i) {
                if (ans[i] == 1) {
                    need.push_back({val - 1, {i, 0}});
                    for (int cnt = 1; cnt <= 8; ++cnt) need.push_back({val, {i, 1}});
                }
                else {
                    for (int cnt = 1; cnt <= 9; ++cnt) need.push_back({val, {i, 1}});
                }
            }
            sort(need.begin(), need.end());
            for (auto key : need) {
                if (s >= key.first) {
                    s -= key.first;
                    if (key.second.second == 0) ans[key.second.first] = 0;
                    ans[key.second.first] += val;
                }
            }
        }
        for (auto key : ans) cout << key << " ";
        cout << '\n';
    }
    return 0;
}