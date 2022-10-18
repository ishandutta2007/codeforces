#include <bits/stdc++.h>

using namespace std;

const int mod = 1e6 + 3;
int fact[mod], rfact[mod];
int bpow(int x, int n)
{
    if(n == 0)
        return 1;
    int t = bpow(x, n / 2);
    if(n % 2 == 1)
        return 1LL * t * t % mod * x % mod;
    else
        return 1LL * t * t % mod;
}

int nCr(int n, int k)
{
    return 1LL * fact[n] * rfact[k] % mod * rfact[n - k] % mod;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    fact[0] = rfact[0] = 1;
    for(int i = 1; i < mod; i++)
    {
        fact[i] = 1LL * fact[i - 1] * i % mod;
        rfact[i] = bpow(fact[i], mod - 2);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += nCr(i + c - 1, c - 1);
        if(ans > mod)
            ans -= mod;
    }
    cout << ans << "\n";
	return 0;
}