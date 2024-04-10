#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

    int n;
    std::cin >> n;
    
    auto query = [&](int x) {
        std::cout << "? " << x + 1 << std::endl;
        std::vector<int> d(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> d[i];
        }
        return std::vector<int>(std::move(d));
    };

    std::vector<std::vector<int>> dis(n);
    dis[0] = std::move(query(0));
    int cnt[2] = {};
    for (int i = 1; i < n; ++i) {
        ++cnt[dis[0][i] & 1];
    }
    int t = std::min_element(cnt, cnt + 2) - cnt;

    for (int i = 1; i < n; ++i) {
        if ((dis[0][i] & 1) == t) {
            dis[i] = std::move(query(i));
        }
    }

    std::cout << "!\n";
    for (int i = 0; i < n; ++i) {
        if ((dis[0][i] & 1) == t) {
            for (int j = 0; j < n; ++j) {
                if (dis[i][j] == 1) {
                    std::cout << i + 1 << " " << j + 1 << "\n";
                }
            }
        }
    }
    std::cout << std::endl;
}