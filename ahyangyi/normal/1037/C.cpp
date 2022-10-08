#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    string a, b;

    cin >> n >> a >> b;

    vector<int> dp(n + 1);

    for (int i = 0; i < n; ++i)
    {
        // flip
        dp[i + 1] = dp[i] + (a[i] != b[i]);

        // swap
        if (i >= 1 && a[i - 1] != b[i - 1] && a[i] != b[i] && a[i] != a[i - 1])
        {
            dp[i + 1] = std::min(dp[i + 1], dp[i - 1] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}