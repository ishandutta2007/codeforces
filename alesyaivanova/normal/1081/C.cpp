#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 998244353;

int fast_pow(int a, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return a % mod;
    if (p == 2)
        return (a * a) % mod;
    int b = fast_pow(a, p / 2);
    b = (b * b) % mod;
    if (p % 2 == 0)
        return b;
    return (b * a) % mod;
}

int d(int a, int b)
{
    return (fast_pow(b, mod - 2) * a) % mod;
}

int find_c(int n, int k)
{
    int a = 1;
    for (int i = n; i >= n - k + 1; i--)
        a = (a * i) % mod;
    for (int i = 2; i <= k; i++)
        a = d(a, i);
    return a;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = find_c(n - 1, k);
    ans = (ans * m) % mod;
    ans = (ans * fast_pow(m - 1, k)) % mod;
    cout << ans;
}