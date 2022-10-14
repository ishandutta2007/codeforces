#include <bits/stdc++.h>
int main () {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector <int> a(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        int ans = 0;
        while (!std::is_sorted(a.begin(), a.end())) {
            ans++;
            for (int i = 0; i + 1 < n; i += 2) {
                if (a[i] > a[i + 1])
                    std::swap(a[i], a[i + 1]);
            }
            if (std::is_sorted(a.begin(), a.end()))
                break;
            ans++;
            for (int i = 1; i + 1 < n; i += 2) {
                if (a[i] > a[i + 1])
                    std::swap(a[i], a[i + 1]);
            }
        }
        std::cout << ans << std::endl;
    }
}