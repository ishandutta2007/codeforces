#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) {
        std::cin >> x;
    }

    std::deque<int> ans;
    for (int i = 0; i < n; ++i) {
        if (a[i] < *ans.begin()) {
            ans.push_front(a[i]);
        } else {
            ans.push_back(a[i]);
        }
    }
    for (int x : ans) {
        std::cout << x << " ";
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