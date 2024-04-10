#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    cout << "YES" << '\n';
    /*for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int z = 0; z < 3; ++z) {
                for (int k = 0; k < 3; ++k) {
                    string s;
                    s += char('a' + i), s += char('a' + j);
                    string t;
                    t += char('a' + z), t += char('a' + k);
                    bool check = true;
                    for (int gg = 0; gg < 3; ++gg) {
                        for (int tt = 0; tt < 3; ++tt) {
                            for (int kk = 0; kk < 3; ++kk) {
                                if (gg == tt || gg == kk || tt == kk) continue;
                                string go = "";
                                go += char('a' + gg);
                                go += char('a' + tt);
                                go += char('a' + kk);
                                string s1, s2, s3;
                                s1 += go[0], s1 += go[1];
                                s2 += go[1], s2 += go[2];
                                s3 += go[2], s3 += go[0];
                                if (s1 != s && s2 != s && s3 != s && s1 != t && s2 != t && s3 != t) check = false;
                                if (s1 != s && s2 != s && s1 != t && s2 != t && s[0] != s[1] && t[0] != t[1]) check = false;
                            }
                        }
                    }
                    if (check) {
                        cout << s << " " << t << endl;
                    }
                }
            }
        }
    }*/
    //return 0;
    for (int gg = 0; gg < 3; ++gg) {
        for (int tt = 0; tt < 3; ++tt) {
            for (int kk = 0; kk < 3; ++kk) {
                if (gg == tt || gg == kk || tt == kk) continue;
                string go = "";
                go += char('a' + gg);
                go += char('a' + tt);
                go += char('a' + kk);
                string s1, s2, s3;
                s1 += go[0], s1 += go[1];
                s2 += go[1], s2 += go[2];
                s3 += go[2], s3 += go[0];
                if (s1 != s && s2 != s && s3 != s && s1 != t && s2 != t && s3 != t) {
                    for (int j = 0; j < n; ++j) cout << go;
                    return 0;
                }
                if (s1 != s && s2 != s && s1 != t && s2 != t && t[0] != t[1] && s[0] != s[1]) {
                    for (int j = 0; j < n; ++j) cout << go[0];
                    for (int j = 0; j < n; ++j) cout << go[1];
                    for (int j = 0; j < n; ++j) cout << go[2];
                    return 0;
                }
            }
        }
    }
    cout << 1 / 0 << endl;
    return 0;
}