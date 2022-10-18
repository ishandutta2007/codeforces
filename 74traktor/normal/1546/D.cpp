#include<bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e5 + 5;
int f[maxn], rf[maxn];
int mod = 998244353;

int st(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 0) {
        int c = st(x, y / 2);
        return c * c % mod;
    }
    return x * st(x, y - 1) % mod;
}

main() {
    int t, n;
    cin >> t;
    f[0] = 1, rf[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = f[i - 1] * i % mod;
        rf[i] = st(f[i], mod - 2);
    }
    while (t--) {
        string s;
        cin >> n >> s;
        int z = 0, go = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') z++;
            else if (i < n - 1 && s[i + 1] == '1') go++, i++;
        }
        cout << f[z + go] * rf[z] % mod * rf[go] % mod << '\n';
    }
}