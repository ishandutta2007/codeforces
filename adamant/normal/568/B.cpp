#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

int bpow(int x, int n)
{
    if(n == 0)
        return 1;
    int t = bpow(x, n / 2);
    if(n % 2 == 0)
        return t * t % mod;
    else
        return t * t % mod * x % mod;
}

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    int fact[n + 1];
    int rfact[n + 1];
    fact[0] = rfact[0] = 1;
    int pows[n + 1], revs[n + 1];
    for(int i = 0; i <= n; i++)
        pows[i] = bpow(i, n),
        revs[i] = bpow(i, mod - 2);
    for(int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod,
        rfact[i] = rfact[i - 1] * revs[i] % mod;
    int cnt[n + 1];
    for(int i = 1; i <= n; i++)
    {
        int t = pows[i];
        for(int j = 1; j < i; j++)
            t = (t - cnt[i - j] * fact[i] % mod * rfact[j] % mod * rfact[i - j] % mod) % mod;
        t = (t + mod) % mod;
        cnt[i] = t;
        t = t * rfact[i - 1] % mod;
        ans = (ans + t) % mod;
    }
    cout << ans << "\n";
    return 0;
}