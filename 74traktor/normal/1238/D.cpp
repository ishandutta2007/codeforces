#include <bits/stdc++.h>

using namespace std;

#define int long long
vector < int > t[2];
int pref_ab[300005];
int pref_ba[300005];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = n * (n - 1) / 2;
    string s;
    cin >> s;
    int xa = -1, xb = -1;
    for (int i = 0; i < n; ++i) {
        t[s[i] - 'A'].push_back(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        pref_ab[i] = pref_ab[i + 1], pref_ba[i] = pref_ba[i + 1];
        if (s[i] == 'A' && s[i + 1] == 'B') pref_ab[i]++;
        if (s[i] == 'B' && s[i + 1] == 'A') pref_ba[i]++;
    }
    for (int l = 0; l < n; ++l) {
        if (s[l] == 'A') {
            int it = upper_bound(t[0].begin(), t[0].end(), l) - t[0].begin();
            if (it == (int)t[0].size()) ans -= (n - l - 1);
            else {
                int x;
                if (t[0][it] - 1 != l) x = 0;
                else x = 1;
                ans -= ((t[0][it] - l - 1) + min(x, pref_ab[t[0][it]]));
            }
        }
        else {
            int it = upper_bound(t[1].begin(), t[1].end(), l) - t[1].begin();
            if (it == (int)t[1].size()) ans -= (n - l - 1);
            else {
                int x;
                if (t[1][it] - 1 != l) x = 0;
                else x = 1;
                ans -= ((t[1][it] - l - 1) + min(x, pref_ba[t[1][it]]));
            }
        }
        //cout << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}