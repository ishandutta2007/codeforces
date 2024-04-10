#include <iostream>
#include <algorithm>

#define lint long long int
#define mod 1000000007
using namespace std;

int rid (int a, int b) {
    if (!b)
        return 1;
    else if (b & 1)
        return (1ll * rid(a, b - 1) * a) % mod;
    else {
        int aux = rid(a, b >> 1);
        return (1ll * aux * aux) % mod;
    }
}

int n, k;
int c[1005];
int s_part[1005];

int dp[1005][1005];

void add_sum (int &x, int val) {
    x += val;
    if (x >= mod)
        x -= mod;
}

int facts[1005];
int invfacts[1005];

int main()
{
    facts[0] = 1;
    for (int i = 1; i <= 1000; i++)
        facts[i] = (1ll * facts[i - 1] * i) % mod;
    for (int i = 0; i <= 1000; i++)
        invfacts[i] = rid(facts[i], mod - 2);

    cin >> k;
    for (int i = 1; i <= k; i++)
        cin >> c[i];
    reverse(c + 1, c + k + 1);

    for (int i = 1; i <= k; i++)
        s_part[i] = s_part[i - 1] + c[i];

    int n = s_part[k];

    dp[0][0] = 1;
    int j;
    for (int i = 0; i < n; i++)
        for (j = 0; j <= k; j++) {
            add_sum(dp[i + 1][j], (1ll * dp[i][j] * (s_part[j] - i)) % mod);
            add_sum(dp[i + 1][j + 1], (1ll * dp[i][j] * c[j + 1]) % mod);
        }

    for (int i = 1; i <= k; i++)
        dp[n][k] = (1ll * dp[n][k] * invfacts[c[i]]) % mod;

    cout << dp[n][k] << '\n';
    return 0;
}