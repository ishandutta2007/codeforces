#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int m = 1;
    int q = 1;
    for (int i = 2; i <= n; i++)
        q = (q * i) % mod;
    int ans = q;
    for (int i = n; i >= 2; i--)
    {
        m = (m * i) % mod;
        ans = ((ans - m + q) % mod + mod) % mod;
    }
    cout << ans;
}