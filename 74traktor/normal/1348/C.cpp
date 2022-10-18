#include<bits/stdc++.h>

using namespace std;

int cnt[27];

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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int j = 0; j < 26; ++j) cnt[j] = 0;
        for (auto c : s) cnt[c - 'a']++;
        string goal = "";
        int used = k, go = 0;
        for (int j = 0; j < 26; ++j) {
            int x = min(cnt[j], used);
            if (used == x && used > 0) {
                goal += char('a' + j), go = used;
            }
            used -= x, cnt[j] -= x;
        }
        if (go != k) cout << goal << '\n';
        else {
            int imax = -1, imin = 26;
            for (int j = 0; j < 26; ++j) if (cnt[j] > 0) imax = j, imin = min(imin, j);
            if (imax == -1) cout << goal << '\n';
            else {
                if (imax == imin) {
                    for (int pos = 0; pos < (cnt[imin] + k - 1) / k; ++pos) goal += char('a' + imin);
                }
                else {
                    for (int j = 0; j < 26; ++j) {
                        for (int pos = 0; pos < cnt[j]; ++pos) goal += char('a' + j);
                    }
                }
                cout << goal << '\n';
            }
        }
    }
    return 0;
}