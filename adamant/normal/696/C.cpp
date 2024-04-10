#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int mod = 1e9 + 7;
int bpow(int x, int n)
{
    if(n == 0)
        return 1;
    int t = bpow(x, n / 2);
    if(n % 2 == 1)
        return x * t % mod * t % mod;
    return t * t % mod;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    int a[k];
    int n2 = 2, n1 = mod - 1;
    for(auto &it: a)
    {
        cin >> it;
        n2 = bpow(n2, it) % mod;
        n1 = bpow(n1, it) % mod;
    }
    n2 = n2 * bpow(2, mod - 2) % mod;
    int P = (n2 + n1) * bpow(3, mod - 2) % mod, Q = n2;
    cout << P << '/' << Q << "\n";
	return 0;
}