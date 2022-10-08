#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int ct;
    cin >> ct;
    for (int t = 0; t < ct; ++t)
    {
        int n, x;
        cin >> n >> x;

        vector<int> dp(n+1), prev(n+1), best(n+1);

        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;

            for (int j = 0; j <= n; ++j)
            {
                dp[j] = std::max(0, prev[j] + a);
                if (j > 0)
                {
                    dp[j] = std::max(dp[j], prev[j - 1] + a + x);
                }
                if (dp[j] > best[j])
                {
                    best[j] = dp[j];
                }
            }
            std::swap(dp, prev);
        }

        for (int x : best)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}