#include<bits/stdc++.h>

using namespace std;

inline int check(string s) {
    int cnt = 0;
    string t = "abacaba";
    for (int i = 0; i < (int)s.size() - (int)t.size() + 1; ++i) {
        int ok = 1;
        for (int j = i; j < i + (int)t.size(); ++j) {
            if (s[j] != t[j - i]) ok = 0;
        }
        cnt += ok;
    }
    return cnt == 1;
}

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
        string s;
        int n;
        cin >> n;
        cin >> s;
        string t = "abacaba";
        int flag = 0;
        for (int i = 0; i < (int)s.size() - (int)t.size() + 1; ++i) {
            string S = s;
            int ok = 1;
            for (int j = i; j < i + (int)t.size(); ++j) {
                if (S[j] != '?' && S[j] != t[j - i]) ok = 0;
                S[j] = t[j - i];
            }
            for (int i = 0; i < (int)S.size(); ++i) if (S[i] == '?') S[i] = 'd';
            if (ok && check(S)) {
                cout << "Yes" << '\n';
                cout << S << '\n';
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout << "No" << '\n';
        }
    }
    return 0;
}