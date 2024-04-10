#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    std::sort(a.begin(), a.end());
    std::vector<std::string> ans;
    for (int l = 0, r = 0; l < n; l = r) {
        r = l;
        while (r < n && a[r].first == a[l].first) {
            ++r;
        }
        if (a[l].first == n - l) {
            std::string s(n, '0');
            for (int j = 0; j < l; ++j) {
                if (a[j].first > 0) {
                    --a[j].first;
                    s[a[j].second] = '1';
                }
            }
            for (int j = l; j < r; ++j) {
                --a[j].first;
                s[a[j].second] = '1';
            }
            ans.emplace_back(s);
        }
        int len = std::min(r - l - 1, a[l].first);
        for (int i = l; i < r; ++i) {
            std::string s(n, '0');
            for (int j = 0; j < l; ++j) {
                if (a[j].first > 0) {
                    --a[j].first;
                    s[a[j].second] = '1';
                }
            }
            for (int j = i, p = 0; p < len; ++p, j = (j - l + 1) % (r - l) + l) {
                --a[j].first;
                s[a[j].second] = '1';
            }
            for (int j = r; j < n; ++j) {
                if (a[j].first > 1) {
                    --a[j].first;
                    s[a[j].second] = '1';
                }
            }
            ans.push_back(s);
        }
    }

    std::cout << ans.size() << "\n";
    for (auto s : ans) {
        std::cout << s << "\n";
    }
}