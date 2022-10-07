#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<bool>> adj(n, std::vector<bool>(n));
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        adj[u][v] = adj[v][u] = true;
    }

    std::vector<long long> pw(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * n;
    }

    std::vector<long long> st;
    
    int half = n / 2;

    std::vector<std::pair<int, int>> edge(half);

    auto color = [&](auto self, int S, int x, long long now) {
        if (S == 0) {
            st.push_back(now);
            return;
        }
        int t = std::__lg(S & -S);
        S ^= 1 << t;
        now += x * (pw[edge[t].first] + pw[edge[t].second]);
        for (int T = S; ; T = (T - 1) & S) {
            long long nst = now;
            for (int i = 0; i < half; ++i) {
                if (T >> i & 1) {
                    nst += x * (pw[edge[i].first] + pw[edge[i].second]);
                }
            }
            self(self, S ^ T, x + 1, nst);
            if (T == 0) {
                break;
            }
        }
    };

    auto match = [&](auto self, int k, int S) {
        if (k == half) {
            auto tmp(edge);
            do {
                bool ok = true;
                for (int i = 0; i + 1 < half; ++i) {
                    ok &= (adj[tmp[i].first][tmp[i + 1].first]
                        && adj[tmp[i].second][tmp[i + 1].second])
                      || (adj[tmp[i].first][tmp[i + 1].second]
                        && adj[tmp[i].second][tmp[i + 1].first]);
                }
                ok &= adj[tmp.back().first][tmp.back().second];
                if (ok) {
                    color(color, (1 << half) - 1, 0, 0);
                    return;
                }
            } while (std::next_permutation(tmp.begin(), tmp.end()));
            return;
        }
        edge[k].first = std::__lg(S & -S);
        S ^= 1 << edge[k].first;
        for (int i = edge[k].first + 1; i < n; ++i) {
            if (S >> i & 1) {
                edge[k].second = i;
                self(self, k + 1, S ^ (1 << edge[k].second));
            }
        }
    };

    match(match, 0, (1 << n) - 1);

    std::sort(st.begin(), st.end());
    st.erase(std::unique(st.begin(), st.end()), st.end());

    std::vector<long long> aw(n + 1);
    aw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        aw[i] = aw[i - 1] * (k - i + 1);
    }
    long long ans = 0;
    for (long long x : st) {
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = std::max<int>(mx, (x / pw[i]) % n + 1);
        }
        ans += aw[mx];
    }
    std::cout << ans << "\n";
}