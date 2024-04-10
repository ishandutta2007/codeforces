#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long INF = 1000000000012;

int n;
int a[N];

long long p[N];
long long dp[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    dp[n] = p[n];
    long long maxu = p[n];
    for (int i = n - 1; i >= 1; --i)
    {
        dp[i] = maxu;
        maxu = max(maxu, p[i] - maxu);
    }
    cout << dp[1] << endl;
    return 0;
}