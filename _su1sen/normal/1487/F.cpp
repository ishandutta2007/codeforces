#include <iostream>
#include <string>
#include <vector>

constexpr int inf = std::numeric_limits<int>::max() / 2;
constexpr int S = 400;

int solve(std::string m) {
    std::vector<int> d { 0 };
    for (char c : m) d.push_back(c - '0');
    const int n = d.size();

    std::vector<std::vector<std::vector<int>>> dp(n + 1);
    std::vector<int> bias(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        bias[i] = i <= n - 5 ? 1 : S;
        dp[i].resize(bias[i] * 2 + 1, std::vector<int>(2 * S + 1, -1));
    }

    dp[0][bias[0]][S] = 0;
    for (int i = 0; i < n; ++i) {
        const int jmax = dp[i].size();
        for (int j = 0; j < jmax; ++j) {
            const int diff = j - bias[i];
            const int kmax = dp[i][j].size();
            for (int k = 0; k < kmax; ++k) {
                if (dp[i][j][k] < 0) continue;
                for (int num = -7; num <= 7; ++num) {
                    int nj = bias[i + 1] + diff * 10 + d[i] - num;
                    if (nj < 0 or nj >= int(dp[i + 1].size())) continue;
                    int nk = k + num;
                    int cost = (n - i - 1) * abs(num) + dp[i][j][k];
                    dp[i + 1][nj][nk] = std::min(dp[i + 1][nj][nk] == -1 ? inf : dp[i + 1][nj][nk], cost);
                }
            }
        }
    }
    int ans = inf;
    for (int j = 0; j < int(dp[n].size()); ++j) {
        int diff = j - bias[n];
        if (dp[n][j][S - diff] >= 0) ans = std::min(ans, dp[n][j][S - diff]);
    }
    return ans;
}

int main() {
    std::string n;
    std::cin >> n;

    int c = 0;
    for (int i = n.size() - 1; i >= 0; --i) {
        const int m = 9 * (n[i] - '0') + c;
        n[i] = '0' + (m % 10);
        c = m / 10;
    }
    if (c) n = char('0' + c) + n;

    std::cout << solve(n) << std::endl;
    return 0;
}