#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 200009;
int b[MAX_N];
int mod = 998244353;

int fast_pow(int a, int t)
{
    if (t == 0)
        return 1;
    if (t == 1)
        return a;
    int b = fast_pow(a, t / 2);
    b = (b * b) % mod;
    if (t % 2 == 0)
        return b;
    return (a * b) % mod;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a;
    cin >> n >> m >> a;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    a %= mod;
    int ans = 1;
    for (int i = 0; i < m; i++)
    {
        int len = b[i];
        if (i >= 1)
            len -= b[i - 1];
        int u = fast_pow(a, len);
        int cur = (u * (u + 1)) % mod;
        if (cur % 2 == 0)
            cur /= 2;
        else
            cur = (cur + mod) / 2;
        ans = (ans * cur) % mod;
    }
    int len = n - 2 * b[m - 1];
    int u = fast_pow(a, len);
    ans = (ans * u) % mod;
    cout << ans;
}