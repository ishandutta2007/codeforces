#include <iostream>

using namespace std;

int n;
unsigned int v[1000005];
unsigned int _v[1000005];

unsigned int dp[1 << 22];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i <= n; i++) {
        _v[i] = ((~v[i]) & ((1 << 22) - 1));
        dp[_v[i]] = v[i];
    }

    int j;
    for (int i = ((1 << 22) - 1) - 1; i; i--)
        if (dp[i])
            for (j = 0; j < 22; j++)
                if (i & (1 << j))
                    dp[i ^ (1 << j)] = dp[i];

    for (int i = 1; i <= n; i++)
        if (!dp[v[i]])
            cout << "-1 ";
        else
            cout << dp[v[i]] << ' ';

    cout << '\n';
    return 0;
}