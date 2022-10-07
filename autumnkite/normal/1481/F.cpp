#include <bits/stdc++.h>

typedef std::bitset<100001> state;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> E(n);
    for (int i = 1; i < n; ++i) {
        int u;
        std::cin >> u;
        --u;
        E[u].push_back(i);
    }

    std::vector<int> dep(n);

    auto dfs = [&](auto &self, int u) -> void {
        for (int v : E[u]) {
            dep[v] = dep[u] + 1;
            self(self, v);
        }
    };

    dfs(dfs, 0);

    int d = *std::max_element(dep.begin(), dep.end()) + 1;
    std::vector<std::vector<int>> p(d);
    for (int i = 0; i < n; ++i) {
        p[dep[i]].push_back(i);
    }
    std::vector<std::vector<int>> t(n + 1);
    for (int i = 0; i < d; ++i) {
        t[p[i].size()].push_back(i);
    }

    std::vector<std::vector<int>> id;
    std::vector<int> w;

    for (int i = 1; i <= n; ++i) {
        if (!t[i].empty()) {
            int pw = 1, now = 0;
            while (now + pw <= (int)t[i].size()) {
                id.emplace_back(t[i].begin() + now, t[i].begin() + now + pw);
                w.emplace_back(pw * i);
                now += pw;
                pw *= 2;
            }
            if (now < (int)t[i].size()) {
                id.emplace_back(t[i].begin() + now, t[i].end());
                w.emplace_back(((int)t[i].size() - now) * i);
            }
        }
    }

    std::vector<state> f(id.size() + 1);
    f[0][0] = 1;
    for (int i = 0; i < (int)id.size(); ++i) {
        f[i + 1] = f[i] | (f[i] << w[i]);
    }

    if (!f[id.size()][m]) {
        std::vector<char> ans(n);
        int cnt[2] = {m, n - m};
        for (int i = 0; i < d; ++i) {
            int t = std::max_element(cnt, cnt + 2) - cnt;
            for (int x : p[i]) {
                if (!E[x].empty()) {
                    ans[x] = t + 'a';
                    --cnt[t];
                }
            }
            for (int x : p[i]) {
                if (E[x].empty()) {
                    if (cnt[t]) {
                        ans[x] = t + 'a';
                        --cnt[t];
                    } else {
                        ans[x] = !t + 'a';
                        --cnt[!t];
                    }
                }
            }
        }
        std::cout << d + 1 << "\n";
        std::cout << std::string(ans.begin(), ans.end()) << "\n";
    } else {
        std::vector<char> ans(n);
        int now = m;
        for (int i = (int)id.size() - 1; i >= 0; --i) {
            int t;
            if (now >= w[i] && f[i][now - w[i]]) {
                t = 0;
                now -= w[i];
            } else {
                t = 1;
            }
            for (int j : id[i]) {
                for (int x : p[j]) {
                    ans[x] = t + 'a';
                }
            }
        }
        std::cout << d << "\n";
        std::cout << std::string(ans.begin(), ans.end()) << "\n";
    }
}