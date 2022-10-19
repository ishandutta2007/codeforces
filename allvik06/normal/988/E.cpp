#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
signed main() {
    string s;
    cin >> s;
    string s1 = s, s2 = s, s3 = s;
    int nol = -1, nol1 = -1, ans = INF;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '0') {
            if (nol == -1) {
                nol = i;
            }
            else {
                nol1 = i;
                break;
            }
        }
    }
    if (nol1 != -1) {
        int tmp = 0;
        for (int i = nol; i < s.size() - 1; ++i) {
            swap(s[i], s[i + 1]);
            ++tmp;
        }
        for (int i = nol1; i < s.size() - 2; ++i) {
            swap(s[i], s[i + 1]);
            ++tmp;
        }
        int now = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '0') {
                break;
            }
            ++now;
        }
        if (now == s.size()) {
            cout << -1;
            return 0;
        }
        tmp += now;
        ans = min(ans, tmp);
    }
    int two = -1, five = -1;
    for (int i = s1.size(); i >= 0; --i) {
        if (s1[i] == '2' && two == -1) {
            two = i;
        }
        if (s1[i] == '5' && five == -1) {
            five = i;
        }
    }
    if (two != -1 && five != -1) {
        int tmp = 0;
        if (two > five) {
            for (int i = two; i < s1.size() - 1; ++i) {
                swap(s1[i], s1[i + 1]);
                ++tmp;
            }
            for (int i = five; i < s1.size() - 2; ++i) {
                swap(s1[i], s1[i + 1]);
                ++tmp;
            }
            swap(s[s.size() - 1], s[s.size() - 2]);
            ++tmp;
            int now = 0;
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] != '0') {
                    break;
                }
                ++now;
            }
            if (now != s1.size() - 2  || s.size() == 2) {
                ans = min(ans, tmp + now);
            }
        }
        else {
            int tmp = 0;
            for (int i = five; i < s1.size() - 1; ++i) {
                ++tmp;
                swap(s1[i], s1[i + 1]);
            }
            for (int i = two; i < s1.size() - 2; ++i) {
                ++tmp;
                swap(s1[i], s1[i + 1]);
            }
            int now = 0;
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] != '0') {
                    break;
                }
                ++now;
            }
            if (now != s1.size() - 2  || s.size() == 2) {
                ans = min(ans, tmp + now);
            }
        }
    }
    if (five != -1 && nol != -1) {
        int tmp = 0, now = 0;
        if (five > nol) {
            for (int i = five; i < s2.size() - 1; ++i) {
                swap(s2[i], s2[i + 1]);
                ++tmp;
            }
            for (int i = nol; i < s2.size() - 2; ++i) {
                swap(s2[i], s2[i + 1]);
                ++tmp;
            }
            swap(s2[s2.size() - 1], s2[s2.size() - 2]);
            ++tmp;
            for (int i = 0; i < s1.size(); ++i) {
                if (s2[i] != '0') {
                    break;
                }
                ++now;
            }
            if (now != s1.size() - 2 || s.size() == 2) {
                ans = min(ans, tmp + now);
            }
        }
        else {
            for (int i = nol; i < s2.size() - 1; ++i) {
                swap(s2[i], s2[i + 1]);
                ++tmp;
            }
            for (int i = five; i < s2.size() - 2; ++i) {
                swap(s2[i], s2[i + 1]);
                ++tmp;
            }
            for (int i = 0; i < s1.size(); ++i) {
                if (s2[i] != '0') {
                    break;
                }
                ++now;
            }
            if (now != s1.size() - 2 || s.size() == 2) {
                ans = min(ans, tmp + now);
            }
        }
    }
    int seven = -1;
    for (int i = s3.size() - 1; i >= 0; --i) {
        if (s3[i] == '7') {
            seven = i;
            break;
        }
    }
    if (seven != -1 && five != -1) {
        int tmp = 0, now = 0;
        if (seven > five) {
            for (int i = seven; i < s3.size() - 1; ++i) {
                swap(s3[i], s3[i + 1]);
                ++tmp;
            }
            for (int i = five; i < s3.size() - 2; ++i) {
                swap(s3[i], s3[i + 1]);
                ++tmp;
            }
            swap(s3[s3.size() - 1], s3[s3.size() - 2]);
            ++tmp;
            for (int i = 0; i < s1.size(); ++i) {
                if (s3[i] != '0') {
                    break;
                }
                ++now;
            }
            if (now != s1.size() - 2  || s.size() == 2) {
                ans = min(ans, tmp + now);
            }
        }
        else {
            for (int i = five; i < s3.size() - 1; ++i) {
                swap(s3[i], s3[i + 1]);
                ++tmp;
            }
            for (int i = seven; i < s3.size() - 2; ++i) {
                swap(s3[i], s3[i + 1]);
                ++tmp;
            }
            for (int i = 0; i < s1.size(); ++i) {
                if (s3[i] != '0') {
                    break;
                }
                ++now;
            }
            if (now != s1.size() - 2  || s.size() == 2) {
                ans = min(ans, tmp + now);
            }
        }
    }
    if (ans == INF) {
        cout << -1;
    }
    else {
        cout << ans;
    }
}