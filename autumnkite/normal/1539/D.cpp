#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<std::pair<long long, long long>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].second >> a[i].first;
    }
    std::sort(a.begin(), a.end());

    long long ans = 0;
    long long now = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        while (i <= j && now < a[i].first) {
            if (a[i].first - now < a[j].second) {
                long long t = a[i].first - now;
                now += t;
                ans += t * 2;
                a[j].second -= t;
            } else {
                long long t = a[j].second;
                now += t;
                ans += t * 2;
                a[j].second -= t;
                --j;
            }
        }
        if (i <= j) {
            long long t = a[i].second;
            now += t;
            ans += t;
            a[i].second -= t;
            ++i;
        }
    }
    std::cout << ans << "\n";
}