#include <bits/stdc++.h>

void solve() {
    std::string a;
    std::cin >> a;
    std::vector<int> cnt(26);
    std::string b;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (!cnt[a[i] - 'a']) {
            b += a[i];
        }
        ++cnt[a[i] - 'a'];
    }
    std::reverse(b.begin(), b.end());
    int tot = 0;
    for (int i = 0; i < (int)b.size(); ++i) {
        if (cnt[b[i] - 'a'] % (i + 1) != 0) {
            std::cout << -1 << "\n";
            return;
        }
        tot += cnt[b[i] - 'a'] / (i + 1);
    }
    std::string s(a.begin(), a.begin() + tot), tmp_s(s), tmp_a;
    for (int i = 0; i < (int)b.size(); ++i) {
        tmp_a += tmp_s;
        std::string nw;
        for (char c : tmp_s) {
            if (c != b[i]) {
                nw += c;
            }
        }
        tmp_s.swap(nw);
    }
    if (tmp_a == a) {
        std::cout << s << " " << b << "\n";
    } else {
        std::cout << -1 << "\n";
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