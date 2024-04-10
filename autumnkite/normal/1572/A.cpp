#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> deg(n);
    std::vector<std::vector<int>> E(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> deg[i];
        for (int j = 0; j < deg[i]; ++j) {
            int u;
            std::cin >> u;
            --u;
            E[u].push_back(i);
        }
    }
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> Q;
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) {
            Q.push(i);
        }
    }
    int ans = 0, now = 0;
    while (!Q.empty()) {
        ++ans;
        std::priority_queue<int, std::vector<int>, std::greater<int>> R;
        while (!Q.empty()) {
            int u = Q.top();
            ++now;
            Q.pop();
            for (int v : E[u]) {
                --deg[v];
                if (!deg[v]) {
                    if (v < u) {
                        R.push(v);
                    } else {
                        Q.push(v);
                    }
                }
            }
        }
        Q.swap(R);
    }
    if (now < n) {
        std::cout << -1 << "\n";
    } else {
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