#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

const int N = 100000, Q = 100000;

int n, w, q;
int a[N];
int k[Q], max[Q], min[Q], ans[Q];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> w >> q;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        std::cin >> k[i];
        k[i] = w - k[i];
        max[i] = min[i] = a[0];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            if (max[j] < a[i]) {
                max[j] = a[i];
            }
            if (min[j] > a[i]) {
                min[j] = a[i];
            }
            if (max[j] - min[j] > k[j]) {
                max[j] = min[j] = a[i];
                ++ans[j];
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        std::cout << ans[i] << "\n";
    }
}