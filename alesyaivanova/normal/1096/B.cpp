#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    bool u = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
            u = false;
    }
    if (u)
    {
        int ans = (n + 1) * n / 2;
        ans -= n + 1;
        cout << ans % mod;
        return 0;
    }
    if (s[0] == s[n - 1])
    {
        int i = 0;
        while (s[i + 1] == s[0])
            i++;
        int e = n - 1;
        while (s[e - 1] == s[0])
            e--;
        e = n - e;
        i++;
        int ans = (i + 1) * (e + 1);
        cout << ans % mod;
    }
    else
    {
        int i = 0;
        while (s[i + 1] == s[0])
            i++;
        int e = n - 1;
        while (s[e - 1] == s[n - 1])
            e--;
        e = n - e;
        i++;
        int ans = i + e + 1;
        cout << ans % mod;
    }
}