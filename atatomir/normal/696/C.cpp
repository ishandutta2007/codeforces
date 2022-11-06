#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define mod 1000000007

ll d1[2][2], d2[2][2];

struct matrix {
    int i, j, k;
    ll data[2][2];

    void init() {
        data[0][0] = 1;
        data[0][1] = 2;
        data[1][0] = 1;
        data[1][1] = 0;
    }

    void operator*=(matrix &who) {
        memcpy(d1, data, sizeof(d1));
        memcpy(d2, who.data, sizeof(d2));

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                data[i][j] = 0;
                for (k = 0; k < 2; k++)
                    data[i][j] = (data[i][j] + d1[i][k] * d2[k][j]) % mod;
            }
        }
    }
};

matrix poww(matrix a, ll b) {
    matrix ans = a;
    b--;

    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }

    return ans;
}

ll val_pow(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

int n, i;
ll x;
matrix ini;
ll sup, sub, inv2;

int main()
{
    //freopen("test.in","r",stdin);

    ini.init();
    sub = 2;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &x);

        ini = poww(ini, x);
        sub = val_pow(sub, x);
    }

    sup = ini.data[1][1];
    inv2 = val_pow(2, mod - 2);

    sup = (sup * inv2) % mod;
    sub = (sub * inv2) % mod;

    printf("%lld/%lld", sup, sub);

    return 0;
}