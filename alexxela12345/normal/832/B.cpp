//#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

bool is_good[26];

int main() {
    string good;
    cin >> good;
    for (char c : good) {
        is_good[c - 'a'] = 1;
    }
    string pat;
    cin >> pat;
    int q;
    cin >> q;
    bool has_star = false;
    int star_pos = -1;
    for (size_t i = 0; i < pat.size(); i++) {
        if (pat[i] == '*') {
            has_star = true;
            star_pos = i;
        }
    }
    while (q--) {
        string s;
        cin >> s;
        if (has_star) {
            if (s.size() + 1 < pat.size()) {
                cout << "NO" << endl;
            } else {
                bool good = true;
                for (int i = 0; i < star_pos; i++) {
                    if (pat[i] == '?') {
                        if (!is_good[s[i] - 'a']) {
                            good = false;
                        }
                    } else if (s[i] != pat[i]) {
                        good = false;
                    }
                }
                for (int i = star_pos; i < star_pos + (int) s.size() - (int) pat.size() + 1; i++) {
                    if (is_good[s[i] - 'a']) {
                        good = false;
                    }
                }
                for (int i = 0; i < (int) pat.size() - 1 - star_pos; i++) {
                    if (pat[pat.size() - 1 - i] == '?') {
                        if (!is_good[s[s.size() - 1 - i] - 'a']) {
                            good = false;
                        }
                    } else if (pat[pat.size() - 1 - i] != s[s.size() - 1 - i]) {
                        good = false;
                    }
                }
                if (good) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        } else {
            if (s.size() != pat.size()) {
                cout << "NO" << endl;
            } else {
                bool good = true;
                for (size_t i = 0; i < s.size(); i++) {
                    if (pat[i] == '?') {
                        if (!is_good[s[i] - 'a']) {
                            good = false;
                        }
                    } else if (s[i] != pat[i]) {
                        good = false;
                    }
                }
                if (good) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }
}