#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int pref[26][maxn];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (int i = 1; i <= (int)s.size(); ++i) {
        for (int j = 0; j < 26; ++j) pref[j][i] = pref[j][i - 1];
        pref[s[i - 1] - 'a'][i]++;
    }
    int t, l, r;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> l >> r;
        if (l == r) {
            cout << "Yes" << '\n';
            continue;
        }
        if (s[l - 1] != s[r - 1]) {
            cout << "Yes" << '\n';
            continue;
        }
        int cnt = 0;
        for (int j = 0; j < 26; ++j) {
            if (pref[j][r] != pref[j][l - 1]) cnt++;
        }
        if (cnt == 1) {
            cout << "No" << '\n';
            continue;
        }
        if (cnt >= 3) {
            cout << "Yes" << '\n';
            continue;
        }
        int lef = l - 1, righ = r + 1;
        while (righ - lef > 1) {
            int mid = (righ + lef) / 2;
            if (pref[s[r - 1] - 'a'][mid] - pref[s[r - 1] - 'a'][l - 1] == mid - l + 1) lef = mid;
            else righ = mid;
        }
        cout << "No" << '\n';
    }
    return 0;
}