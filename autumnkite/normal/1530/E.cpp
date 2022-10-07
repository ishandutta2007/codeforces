#include <bits/stdc++.h>

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> tcnt(26);
    for (char c : s) {
        ++tcnt[c - 'a'];
    }
    std::vector<char> ch;
    std::vector<int> cnt;
    for (int i = 0; i < 26; ++i) {
        if (tcnt[i] > 0) {
            ch.push_back('a' + i);
            cnt.push_back(tcnt[i]);
        }
    }
    int m = ch.size();
    if (m == 1) {
        std::cout << std::string(cnt[0], ch[0]) << "\n";
        return;
    }
    for (int c = 0; c < m; ++c) {
        if (cnt[c] == 1) {
            std::string ans;
            ans += ch[c];
            for (int i = 0; i < m; ++i) {
                if (i != c) {
                    for (int j = 0; j < cnt[i]; ++j) {
                        ans += ch[i];
                    }
                }
            }
            std::cout << ans << "\n";
            return;
        }
    }
    if (2 * cnt[0] - 2 <= n) {
        std::string ans;
        ans += ch[0];
        ans += ch[0];
        cnt[0] -= 2;
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += ch[i];
                if (cnt[0] >= 1) {
                    ans += ch[0];
                    --cnt[0];
                }
            }
        }
        std::cout << ans << "\n";
    } else if (m == 2) {
        std::string ans;
        ans += ch[0];
        --cnt[0];
        for (int i = 1; i >= 0; --i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += ch[i];
            }
        }
        std::cout << ans << "\n";
    } else {
        std::string ans;
        ans += ch[0];
        ans += ch[1];
        --cnt[0], --cnt[1];
        for (int j = 0; j < cnt[0]; ++j) {
            ans += ch[0];
        }
        ans += ch[2];
        --cnt[2];
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += ch[i];
            }
        }
        std::cout << ans << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}