#include<bits/stdc++.h>

using namespace std;

set < int > go[2];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, cnt0 = 0, cnt1 = 0, ans = 0;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string S = s, T = t;
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());
    if (S != T) {
        cout << -1;
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            go[s[i] - '0'].insert(i);
        }
    }
    while ((int)go[0].size() > 0 || (int)go[1].size() > 0) {
        int start = n + 1, f;
        if ((int)go[0].size() > 0) {
            int d = (*go[0].begin());
            if (d < start) start = d, f = 0;
        }
        if ((int)go[1].size() > 0) {
            int d = (*go[1].begin());
            if (d < start) start = d, f = 1;
        }
        ans++;
        while (1) {
            go[f].erase(start);
            f = (f^1);
            auto p = go[f].lower_bound(start);
            if (p == go[f].end()) break;
            start = (*p);
        }
    }
    cout << ans << '\n';
    return 0;
}