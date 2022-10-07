#include <bits/stdc++.h>

std::pair<std::string, std::vector<std::pair<int, int>>>
cano(std::string a, int k) {
    int n = a.size();
    int lst = -1;
    int m = 0;
    std::vector<int> c;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            c.push_back(i - lst - 1);
            lst = i;
            ++m;
        }
    }
    c.push_back(n - lst - 1);
    if (k == 0 || k > m) {
        return {a, {}};
    }
    if (k == m) {
        std::string ta(a), tb(a);
        std::reverse(ta.begin() + c.front(), ta.end());
        std::reverse(tb.begin(), tb.end() - c.back());
        std::reverse(tb.begin(), tb.end());
        if (ta < tb) {
            return {ta, {{c.front(), n}}};
        } else {
            return {tb, {{0, n - c.back()}, {0, n}}};
        }
    }
    std::vector<std::pair<int, int>> op;
    auto rev = [&](int l, int x) {
        int r = l + k;
        int sl = l, sr = r;
        for (int i = 0; i <= l; ++i) {
            sl += c[i];
        }
        for (int i = 0; i < r; ++i) {
            sr += c[i];
        }
        std::reverse(c.begin() + l + 1, c.begin() + r);
        c[l] += x, c[r] -= x;
        sr += std::max(x, 0);
        sl += std::min(x, 0);
        op.emplace_back(sl, sr);
        std::reverse(a.begin() + sl, a.begin() + sr);
    };
    for (int i = m; i > k + 1; --i) {
        rev(i - k, c[i]);
    }
    for (int i = 0; i <= k; ++i) {
        rev(0, c[k]);
        rev(1, k & 1 ? c[k + 1] - c[1] : -c[1]);
    }
    return {a, op};
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string a, b;
    std::cin >> a >> b;
    auto [sa, ta] = cano(a, k);
    auto [sb, tb] = cano(b, k);
    if (sa != sb) {
        std::cout << -1 << "\n";
    } else {
        std::cout << ta.size() + tb.size() << "\n";
        for (auto [l, r] : ta) {
            std::cout << l + 1 << " " << r << "\n";
        }
        std::reverse(tb.begin(), tb.end());
        for (auto [l, r] : tb) {
            std::cout << l + 1 << " " << r << "\n";
        }
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