#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 404;
int mod;
int fact[N], d0[N], d[N], d2[N][N];

int main()
{
#ifdef ONPC
    freopen("i.in", "r", stdin);
#endif

    int qq;
    cin >> qq >> mod;
    
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = (1LL * fact[i-1] * i) % mod;

    d[1] = 1;
    d0[1] = 1;

    for (int n = 2; n < N; ++n) {
        d0[n] = fact[n];
        for (int k = 1; k < n; ++k)
            d0[n] = (d0[n] - 1LL * d0[k] * fact[n - k]) % mod;
        if (d0[n] < 0)
            d0[n] += mod;
    }

    d2[0][0] = 1;
    for (int n = 1; n < N; ++n) {
        d2[n][1] = fact[n];
        for (int k = 2; k <= n; ++k)
            for (int x = 1; x < n; ++x)
                d2[n][k] = (d2[n][k] + 1LL * fact[x] * d2[n-x][k-1]) % mod;
    }

    for (int n = 2; n < N; ++n) {
        int dz = 0;
        for (int x = 1; x < n - 1; ++x)
            for (int y = x; y < n - 1; ++y) {
                int c = fact[y - x + 1];
                c = (1LL * c * d0[x]) % mod;
                c = (1LL * c * d0[n - y - 1]) % mod;
                dz += c;
                if (dz >= mod)
                    dz -= mod;
            }
        dz = (dz * 2) % mod;
        int cd = fact[n];
        cd = (cd - dz + mod) % mod;
        for (int k = 3; k < n; ++k) {
            cd = (cd - 1LL * d2[n][k] * d[k]) % mod;
        }
        if (n != 2) {
            for (int x = 1; x < n; ++x)
                cd = (cd - 1LL * d0[x] * d0[n-x]) % mod;
            for (int x = 1; x < n; ++x)
                cd = (cd - 1LL * d0[x] * d0[n-x]) % mod;
        }
        cd = (cd + mod) % mod;
        d[n] = cd;
    }

    while (qq--) {
        int x;
        cin >> x;
        cout << d[x] << "\n";
    }
}