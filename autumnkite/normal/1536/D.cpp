#include <bits/stdc++.h>

const int INF = std::numeric_limits<int>::max() / 2;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::set<int> S;
    S.insert(-INF);
    S.insert(INF);
    S.insert(a[0]);
    for (int i = 1; i < n; ++i) {
        int x = a[i - 1];
        int l = *(--S.lower_bound(x));
        int r = *S.upper_bound(x);
        if (a[i] == x || a[i] == l || a[i] == r) {
            continue;
        }
        if (a[i] < l || a[i] > r) {
            std::cout << "NO\n";
            return;
        }
        S.insert(a[i]);
    }
    std::cout << "YES\n";
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