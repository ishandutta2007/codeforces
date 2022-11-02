#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
i64 mul(i64 a, i64 b, i64 m) {
    return static_cast<__int128>(a) * b % m;
}
i64 power(i64 a, i64 b, i64 m) {
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1)
            res = mul(res, a, m);
    return res;
}
bool isprime(i64 n) {
    if (n < 2)
        return false;
    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int s = __builtin_ctzll(n - 1);
    i64 d = (n - 1) >> s;
    for (auto a : A) {
        if (a == n)
            return true;
        i64 x = power(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool ok = false;
        for (int i = 0; i < s - 1; ++i) {
            x = mul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}
constexpr i64 inf = 2e18;
i64 mul(i64 a, i64 b) {
    if (a <= inf / b) {
        return a * b;
    } else {
        return inf;
    }
}
i64 power(i64 a, int b) {
    i64 res = 1;
    for (; b > 0; b /= 2, a = mul(a, a)) {
        if (b % 2 == 1) {
            res = mul(res, a);
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    int cnt = 0;
    std::map<i64, int> id;
    std::vector<std::vector<int>> a;
    auto add = [&](i64 x, int j) -> int {
        for (int i = 1; i <= 60; ++i) {
            i64 v = std::pow(x, 1.0 / i) - 10;
            if (v <= 0) {
                v = 1;
            }
            while (power(v, i) < x) {
                ++v;
            }
            if (power(v, i) == x && isprime(v)) {
                if (!id.count(v)) {
                    id[v] = cnt++;
                }
                a.resize(cnt);
                if (a[id[v]].size() < 2) {
                    a[id[v]].push_back(j);
                    return id[v];
                }
            }
        }
        return -1;
    };
    std::vector<i64> x(n);
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
        p[i] = add(x[i], i);
    }
    for (int i = 0; i < cnt; ++i) {
        if (a[i].size() == 1) {
            p[a[i][0]] = -1;
        }
    }
    std::vector<std::vector<int>> comp(n);
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) {
            continue;
        }
        std::vector<int> q;
        i64 v = x[i];
        for (auto [p, j] : id) {
            if (a[j].size() == 1) {
                continue;
            }
            if (v % p == 0) {
                while (v % p == 0) {
                    v /= p;
                }
                q.push_back(j);
            }
        }
        if (v == 1) {
            comp[i] = q;
        }
    }
    std::vector<i64> ans;
    if (k % 2 == 0) {
        for (int i = 0; i < cnt; ++i) {
            if (k > 0 && a[i].size() == 2) {
                ans.push_back(x[a[i][0]]);
                ans.push_back(x[a[i][1]]);
                k -= 2;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!comp[i].empty() && k > 0) {
                k--;
                ans.push_back(x[i]);
            }
        }
        if (k > 0) {
            std::cout << 0 << "\n";
            return 0;
        }
    } else {
        int j = -1;
        for (int i = 0; i < n; ++i) {
            if (!comp[i].empty() && (j == -1 || comp[i].size() < comp[j].size())) {
                j = i;
            }
        }
        if (j == -1) {
            std::cout << 0 << "\n";
            return 0;
        }
        std::vector<bool> used(cnt);
        for (auto x : comp[j]) {
            used[x] = true;
        }
        ans.push_back(x[j]);
        k--;
        for (int i = 0; i < cnt; ++i) {
            if (used[i]) {
                assert(a[i].size() == 2);
                ans.push_back(x[a[i][0]]);
                ans.push_back(x[a[i][1]]);
                k -= 2;
            }
        }
        if (k < 0) {
            std::cout << 0 << "\n";
            return 0;
        }
        for (int i = 0; i < cnt; ++i) {
            if (!used[i] && k > 0 && a[i].size() == 2) {
                ans.push_back(x[a[i][0]]);
                ans.push_back(x[a[i][1]]);
                k -= 2;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!comp[i].empty() && k > 0 && i != j) {
                k--;
                ans.push_back(x[i]);
            }
        }
        if (k > 0) {
            std::cout << 0 << "\n";
            return 0;
        }
    }
    k = ans.size();
    for (int i = 0; i < k; ++i) {
        std::cout << ans[i] << " \n"[i == k - 1];
    }
    return 0;
}