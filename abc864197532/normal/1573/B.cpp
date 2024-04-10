#include <bits/stdc++.h>
int main () {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector <int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i], a[i] = a[i] - 1 >> 1;
        for (int i = 0; i < n; ++i)
            std::cin >> b[i], b[i] = b[i] - 1 >> 1;
        std::vector <int> p(n), q(n);
        for (int i = 0; i < n; ++i) {
            p[a[i]] = i, q[b[i]] = i;
        }
        for (int i = 1; i < n; ++i)
            p[i] = std::min(p[i], p[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            q[i] = std::min(q[i], q[i + 1]);
        int ans = 1 << 30;
        for (int i = 0; i < n; ++i)
            ans = std::min(ans, p[i] + q[i]);
        std::cout << ans << std::endl;
    }
}