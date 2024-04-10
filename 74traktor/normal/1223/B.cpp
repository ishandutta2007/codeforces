#include <bits/stdc++.h>

using namespace std;

int cnt1[26];
int cnt2[26];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        for (int j = 0; j < 26; ++j) cnt1[j] = 0, cnt2[j] = 0;
        for (auto c : s1) cnt1[c - 'a']++;
        for (auto c : s2) cnt2[c - 'a']++;
        int ok = 0;
        for (int j = 0; j < 26; ++j) {
            if (cnt1[j] > 0 && cnt2[j] > 0) ok = 1;
        }
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}