#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s[3];
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
    }

    vector <tuple <char, int, int> > M;
    string left[3];

    for (char cur_c = 'A'; cur_c <= 'Z'; ++cur_c) {
        vector <int> cnt(3);
        for (int t = 0; t < 3; ++t) {
            for (auto c: s[t]) {
                cnt[t] += c == cur_c;
            }
        }

        while (true) {
            int l = 0, p = -1;
            for (int t = 1; t < 3; ++t) {
                if (cnt[t] > cnt[l]) {
                    p = l;
                    l = t;
                } else if (p == -1 || cnt[t] > cnt[p]) {
                    p = t;
                }
            }

            if (cnt[p] == 0) {
                break;
            }

            M.push_back({cur_c, l, p});
            cnt[l]--, cnt[p]--;
        }

        for (int t = 0; t < 3; ++t) {
            while (cnt[t]--) {
                left[t].push_back(cur_c);
            }
        }
    }

    vector <string> ans;
    for (auto &[c, l, r]: M) {
        int other = 3 ^ l ^ r;
        if (left[other].size() == 0) {
            left[l].push_back(c);
            left[r].push_back(c);
            continue;
        }

        string cur(1, c);
        cur.push_back(left[other].back());
        left[other].pop_back();

        ans.push_back(cur);
    }

    while (left[0].size() + left[1].size() + left[2].size()) {
        int l = 0, p = -1;
        for (int t = 1; t < 3; ++t) {
            if (left[t].size() > left[l].size()) {
                p = l;
                l = t;
            } else if (p == -1 || left[t] > left[p]) {
                p = t;
            }
        }

        if (left[p].size()) {
            ans.push_back({left[l].back(), left[p].back()});
            left[p].pop_back();
        } else {
            ans.push_back({left[l].back(), left[l].back()});
        }

        left[l].pop_back();
    }

    cout << ans.size() << endl;
    for (auto s: ans) {
        cout << s << endl;
    }

    return 0;
}