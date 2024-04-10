#include <iostream>

using namespace std;

const int VALMAX = 1000005;

int frecv[VALMAX];

int dp[VALMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0;
    cin >> n;

    int val;
    while (n --) {
        cin >> val;
        ++ frecv[val];
    }

    int ans = 1;
    int j;
    for (int i = 1; i <= 1000000; ++ i) {
        dp[i] += frecv[i];
        if (dp[i] > ans)
            ans = dp[i];

        for (j = 2 * i; j <= 1000000; j += i)
            if (dp[i] > dp[j])
                dp[j] = dp[i];
    }

    cout << ans << '\n';
    return 0;
}