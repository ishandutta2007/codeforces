#include<bits/stdc++.h>

using namespace std;

pair < int, int > b[55];
char ans[55];
int cnt[26];
int used[55];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int m, R = 25;
        cin >> m;
        for (int j = 0; j < 26; ++j) cnt[j] = 0;
        for (auto c : s) cnt[c - 'a']++;
        for (int i = 1; i <= m; ++i) {
            cin >> b[i].first;
            used[i] = 0;
            b[i].second = i;
        }
        sort(b + 1, b + m + 1);
        while (1) {
            vector < int > go;
            for (int i = 1; i <= m; ++i) {
                if (used[i] == 0 && b[i].first == 0) {
                    used[i] = 1;
                    go.push_back(i);
                }
            }
            if ((int)go.size() == 0) break;
            for (auto key : go) {
                for (int i = 1; i <= m; ++i) {
                    b[i].first -= abs(b[i].second - b[key].second);
                }
            }
            while (R >= 0 && cnt[R] < (int)go.size()) R--;
            assert(R >= 0);
            for (auto key : go) ans[b[key].second] = char('a' + R);
            R--;
        }
        for (int i = 1; i <= m; ++i) cout << ans[i];
        cout << '\n';
    }
    return 0;
}