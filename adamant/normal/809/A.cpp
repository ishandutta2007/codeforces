#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int mod = 1e9 + 7;

int bpow(int x, int n)
{
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return bpow(x * x % mod, n / 2);
    else
        return x * bpow(x, n - 1) % mod;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x[n];
    for(auto &it: x)
        cin >> it;
    sort(x, x + n);
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        ans += x[i] * (mod - 1 + bpow(2, i)) % mod + sum * bpow(2, i) % mod;
        sum += (mod - x[i]) * bpow(2, mod - 1 - i - 1) % mod;
        ans %= mod;
        sum %= mod;
    }
    cout << ans << endl;
 }