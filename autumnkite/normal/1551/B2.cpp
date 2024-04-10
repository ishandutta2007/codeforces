#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        --v;
        pos[v].push_back(i);
    }
    std::vector<int> cnt(k);
    std::vector<int> col(n, -1);
    std::priority_queue<std::pair<int, int>> Q;
    for (int i = 0; i < k; ++i) {
        Q.emplace(0, i);
    }
    for (int i = 0; i < n; ++i) {
        std::vector<int> id;
        for (int j = 0; j < (int)pos[i].size() && !Q.empty(); ++j) {
            int x = Q.top().second;
            ++cnt[x];
            col[pos[i][j]] = x;
            Q.pop();
            id.push_back(x);
        }
        for (int x : id) {
            Q.emplace(-cnt[x], x);
        }
    }
    int mn = *std::min_element(cnt.begin(), cnt.end());
    for (int i = 0; i < n; ++i) {
        if (col[i] != -1 && cnt[col[i]] > mn) {
            --cnt[col[i]];
            col[i] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << col[i] + 1 << " \n"[i == n - 1];
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