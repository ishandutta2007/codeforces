#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
long long a[N];

long long dp[N];

map<long long, long long> mp;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = a[i] + mp[i - a[i]];
        mp[i - a[i]] = max(mp[i - a[i]], dp[i]);
        ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
    return 0;
}