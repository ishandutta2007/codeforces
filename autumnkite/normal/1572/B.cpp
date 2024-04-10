#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> ans;
    auto perf = [&](int x) {
        ans.push_back(x);
        int v = a[x] ^ a[x + 1] ^ a[x + 2];
        a[x] = a[x + 1] = a[x + 2] = v;
    };

    for (int i = 0; i < n; ++i) {
        if (!a[i]) {
            if (!(i & 1)) {
                for (int j = i - 2; j >= 0; j -= 2) {
                    perf(j);
                }
                break;
            } else if (i + 1 < n) {
                if (a[i + 1]) {
                    for (int j = i - 1; j >= 0; j -= 2) {
                        perf(j);
                    }
                    break;
                } else {
                    perf(i - 1);
                }
            }
        }
    }

    if (a[0]) {
        std::cout << "NO\n";
        return;
    }

    for (int i = 1; i + 1 < n; ++i) {
        while (a[i]) {
            if (a[i + 1]) {
                perf(i - 1);
            } else if (i + 2 < n) {
                perf(i);
            } else {
                std::cout << "NO\n";
                return;
            }
        }
    }
    if (a[n - 1]) {
        std::cout << "NO\n";
        return;
    }

    std::cout << "YES\n";
    std::cout << ans.size() << "\n";
    for (int x : ans) {
        std::cout << x + 1 << " ";
    }
    std::cout << "\n";
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