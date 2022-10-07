#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) {
            std::swap(a[i].first, a[i].second);
        }
    }
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int x, int y) {
        return a[x] < a[y];
    });

    std::vector<int> ans(n);
    int mn = -1;
    for (int i = 0, j; i < n; i = j) {
        j = i;
        while (j < n && a[id[j]].first == a[id[i]].first) {
            ans[id[j]] = mn == -1 || a[mn].second >= a[id[j]].second ? -1 : mn;
            ++j;
        }
        for (int k = i; k < j; ++k) {
            if (mn == -1 || a[id[k]].second < a[mn].second) {
                mn = id[k];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << (ans[i] == -1 ? -1 : ans[i] + 1) << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}