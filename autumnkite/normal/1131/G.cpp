#include <bits/stdc++.h>

const long long INF = std::numeric_limits<long long>::max() / 2;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> a(m), c(m);
    for (int i = 0; i < m; ++i) {
        int k;
        std::cin >> k;
        a[i].resize(k);
        c[i].resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> a[i][j];
        }
        for (int j = 0; j < k; ++j) {
            std::cin >> c[i][j];
        }
    }

    int now = 0;
    std::vector<int> A(n);
    std::vector<long long> C(n);
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int id, mul;
        std::cin >> id >> mul;
        --id;
        for (int j = 0; j < (int)a[id].size(); ++j) {
            A[now] = a[id][j];
            C[now++] = 1ll * c[id][j] * mul;
        }
    }

    auto solve = [&](const std::vector<int> &A) {
        int n = A.size();
        std::vector<int> L(n);
        for (int i = 0; i < n; ++i) {
            L[i] = std::max(i - A[i] + 1, 0);
            for (int j = i - 1; j >= L[i]; j = L[j] - 1) {
                L[i] = std::min(L[i], L[j]);
            }
        }
        return std::vector<int>(std::move(L));
    };

    auto &&L = solve(A);
    std::reverse(A.begin(), A.end());
    auto &&R = solve(A);
    std::reverse(R.begin(), R.end());
    for (int i = 0; i < n; ++i) {
        R[i] = n - 1 - R[i];
    }

    std::vector<int> sta;
    std::vector<long long> f(n + 1, INF);
    std::vector<long long> mn(n + 1, INF);
    f[0] = mn[0] = 0;
    for (int i = 0; i <= n; ++i) {
        if (i > 0) {
            f[i] = std::min(f[i], mn[i - 1] + C[i - 1]);
        }
        if (i < n) {
            mn[i] = f[i];
            for (int j = i - 1; j >= L[i]; j = L[j] - 1) {
                mn[i] = std::min(mn[i], mn[j]);
            }
            f[R[i] + 1] = std::min(f[R[i] + 1], f[i] + C[i]);
        }
    }
    std::cout << f[n] << "\n";
}