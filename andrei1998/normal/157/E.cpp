#include <iostream>
#include <string>

using namespace std;

const int mod = 1000000007;

int dp[105][105 * 26];

int main()
{
    ios_base :: sync_with_stdio(false);

    dp[0][0] = 1;

    for (int i = 0; i < 100; ++ i)
        for (int j = 0; j < 105 * 26; ++ j)
            if (dp[i][j])
                for (int k = 0; k < 26; ++ k)
                    dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j]) % mod;

    int t = 0;
    cin >> t;

    string str;
    while (t --) {
        cin >> str;

        int sum = 0;
        for (auto it: str)
            sum += it - 'a';
        cout << (dp[str.size()][sum] - 1) % mod << '\n';
    }

    return 0;
}