#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;
        vector<int> cnt(26);
        for (char ch : s) cnt[ch - 'a']++;
        vector<int> chs;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) chs.push_back(i);
        }
        if (chs.size() == 1) {
            cout << s << '\n';
            continue;
        }
        bool ok = false;
        for (int e : chs) {
            if (cnt[e] == 1) {
                ok = true;
                cout << (char) ('a' + e);
                for (int i = 0; i < chs.size(); i++) {
                    if (chs[i] != e) {
                        while (cnt[chs[i]]--) cout << (char) (chs[i] + 'a');
                    }
                }
                cout << '\n';
                break;
            }
        }
        if (ok) continue;
        if (cnt[chs[0]] <= 2) {
            sort(s.begin(), s.end());
            cout << s << '\n';
            continue;
        }
        if ((cnt[chs[0]] - 3) * 2 <= s.size() - 4) {
            char ch = chs[0] + 'a';
            char ch2 = chs[1] + 'a';
            cnt[chs[0]] -= 2;
            cnt[chs[1]] -= 1;
            string res = {ch, ch, ch2};
            vector<char> foo;
            for (int i = 1; i < chs.size(); i++) {
                while (cnt[chs[i]] > 0) {
                    foo.push_back(chs[i] + 'a');
                    cnt[chs[i]]--;
                }
            }
            reverse(foo.begin(), foo.end());
            while (res.size() < s.size()) {
                if (cnt[chs[0]]) res.push_back(ch), cnt[chs[0]]--;
                if (foo.size() > 0) {
                    res.push_back(foo.back());
                    foo.pop_back();
                }
            }
            cout << res << '\n';
            assert(res.size() == s.size());
        } else {
            if (chs.size() >= 3) {
                char ch = chs[0] + 'a';
                char ch1 = chs[1] + 'a';
                char ch2 = chs[2] + 'a';
                string res = {ch, ch1};
                cnt[chs[0]]--;
                cnt[chs[1]]--;
                for (int i = 0; i < cnt[chs[0]]; i++) {
                    res.push_back(ch);
                }
                cnt[chs[0]] = 0;
                res.push_back(ch2);
                cnt[chs[2]]--;
                for (int e : chs) {
                    while (cnt[e]--) {
                        res.push_back(e + 'a');
                    }
                }
                cout << res << '\n';
                assert(res.size() == s.size());
            } else {
                char ch = chs[0] + 'a';
                char ch1 = chs[1] + 'a';
                string res;
                res.push_back(ch);
                for (int i = 0; i < cnt[chs[1]]; i++) {
                    res.push_back(ch1);
                }
                for (int i = 1; i < cnt[chs[0]]; i++) {
                    res.push_back(ch);
                }
                cout << res << '\n';
                assert(res.size() == s.size());
            }
        }
    }

    return 0;
}