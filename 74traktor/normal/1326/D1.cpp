#include<bits/stdc++.h>

using namespace std;

int const maxn = 1e6 + 5;
int z[2 * maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s, s1;
        cin >> s;
        int start = -1;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] != s[(int)s.size() - i - 1] || 2 * (i + 1) > (int)s.size()) {
                for (int j = i; j < (int)s.size() - i; ++j) s1 += s[j];
                break;
            }
            start = i;
        }
        for (int i = 0; i <= start; ++i) cout << s[i];
        string T = s1;
        reverse(s1.begin(), s1.end());
        T += s1;
        int L = 0, R = 0, pref = 0, suff = 0;
        for (int i = 1; i < (int)T.size(); ++i) {
            z[i] = 0;
            if (i <= R) z[i] = min(z[i - L], R - i + 1);
            while (i + z[i] < (int)T.size() && T[i + z[i]] == T[z[i]]) z[i]++;
            if (i + z[i] - 1 > R) {
                R = i + z[i] - 1;
                L = i;
            }
        }
        for (int i = (int)s1.size(); i < (int)T.size(); ++i) {
            if (i + z[i] == (int)T.size()) {
                pref = z[i];
                break;
            }
        }
        T = s1;
        reverse(s1.begin(), s1.end());
        T += s1;
        L = 0, R = 0;
        for (int i = 1; i < (int)T.size(); ++i) {
            z[i] = 0;
            if (i <= R) z[i] = min(z[i - L], R - i + 1);
            while (i + z[i] < (int)T.size() && T[i + z[i]] == T[z[i]]) z[i]++;
            if (i + z[i] - 1 > R) {
                R = i + z[i] - 1;
                L = i;
            }
        }
        for (int i = (int)s1.size(); i < (int)T.size(); ++i) {
            if (i + z[i] == (int)T.size()) {
                suff = z[i];
                break;
            }
        }
        if (pref >= suff) {
            for (int i = 0; i < pref; ++i) cout << s1[i];
        }
        else {
            for (int i = 0; i < suff; ++i) cout << s1[(int)s1.size() - i - 1];
        }
        for (int i = start; i >= 0; --i) cout << s[i];
        cout << '\n';
    }
    return 0;
}