#include <bits/stdc++.h>

const long long INF = 1000000000000000001ll;

long long plus(long long a, long long b) {
    return a <= INF - b ? a + b : INF;
}

long long mul(long long a, long long b) {
    return a <= INF / b ? a * b : INF;
}

void solve() {
    int n;
    long long m;
    std::cin >> n >> m;
    --m;

    std::vector<long long> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }
    std::vector<long long> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i] = plus(f[i], mul(f[i - j], j >= 2 ? fac[j - 2] : 1));
        }
    }

    if (m >= f[n]) {
        std::cout << -1 << "\n";
        return;
    }

    std::vector<int> ans(n);
    int p = 0;
    while (p < n) {
        int k = 0;
        for (int i = 1; i <= n - p; ++i) {
            long long t = mul(f[n - p - i], i >= 2 ? fac[i - 2] : 1);
            if (m < t) {
                k = i;
                break;
            }
            m -= t;
        }
        std::vector<int> hd(k);
        std::iota(hd.begin(), hd.end(), 0);
        ans[p] = p + k - 1;
        hd[k - 1] = 0;
        for (int x = 1; x < k; ++x) {
            long long t = mul(f[n - p - k], k - x >= 2 ? fac[k - x - 2] : 1);
            for (int i = 0; i < k; ++i) {
                if (hd[i] == i && (x == k - 1 || hd[x] != i)) {
                    if (m < t) {
                        ans[p + x] = p + i;
                        for (int j = 0; j < k; ++j) {
                            if (hd[j] == i) {
                                hd[j] = hd[x];
                            }
                        }
                        break;
                    }
                    m -= t;
                }
            }
        }
        p += k;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
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