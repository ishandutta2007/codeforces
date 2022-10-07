#include <bits/stdc++.h>

const long long INF = std::numeric_limits<long long>::max() / 2;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end(), std::greater<int>());

    std::vector<int> c(n + 1);
    std::vector<long long> s(n + 1);
    for (int i = 0; i <= n; ++i) {
        if (a[i] <= i) {
            if (a[i]) {
                ++c[0];
                --c[a[i] - 1];
                s[a[i] - 1] += a[i];
                s[i] -= a[i];
            }
        } else {
            ++c[0];
            --c[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        c[i] += c[i - 1];
        s[i] += s[i - 1];
    }

    std::vector<long long> v1(n + 1), v2(n + 1), v3(n + 1);
    long long sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += a[i];
        v1[i] = 1ll * (i + c[i] + 1) * (i + 1) + s[i] - sum;
        v2[i] = 1ll * (i + c[i]) * (i + 1) + s[i] - sum;
        v3[i] = 1ll * (i + c[i] + 1) * (i + 2) + s[i] - sum;
    }

    std::vector<long long> pre(n + 1);
    pre[0] = INF;
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = std::min(pre[i], v1[i]);
    }
    std::vector<long long> suf(n + 1);
    suf[n] = INF;
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = std::min(suf[i + 1], v3[i]);
    }
    long long now = INF;
    std::vector<int> ans;
    for (int x = n, p = 0; x >= 0; --x) {
        while (p < n && a[p] > x) {
            if (p >= x) {
                now = std::min(now, v2[p]);
            }
            ++p;
        }
        if (!((x + sum) & 1) && v2[p] + a[p] + std::min(a[p], p + 1) - x >= 0) {
            if (x < p) {
                if (pre[x] >= 0 && now + x >= 0 && suf[p] - x >= 0) {
                    ans.push_back(x);
                }
            } else {
                if (pre[p] >= 0 && suf[p] - x >= 0) {
                    ans.push_back(x);
                }
            }
        }
        if (x) {
            now = std::min(now, v2[x - 1]);
        }
    }
    if (ans.empty()) {
        std::cout << -1 << "\n";
    } else {
        std::reverse(ans.begin(), ans.end());
        for (int x : ans) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}