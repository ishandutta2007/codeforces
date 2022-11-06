#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define sz (1024 * 1024)
#define maxN (sz + 11)

const ll mod = 469762049;
const ll root = 3;


int n, k, i, x;
ll data[maxN], aux[maxN];
int big_dim;

ll poww(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void bottom(int l, int r, ll* data) {
    int i, pos;

    if (l == r) {data[l] %= mod; return;}
    for (i = l; i <= r; i++) aux[i] = data[i];

    pos = l;
    for (i = l; i <= r; i += 2) data[pos++] = aux[i];
    for (i = l + 1; i <= r; i += 2) data[pos++] = aux[i];

    bottom(l, (l + r) >> 1, data);
    bottom(((l + r) >> 1) + 1, r, data);
}

void fft(int dim, ll* data, ll sign) {
    int len, i, j;
    ll u, v, w, step;

    bottom(0, dim - 1, data);
    for (len = 1; 2 * len <= dim; len <<= 1) {
        step = poww(root, (mod - 1) / (2 * len));
        if (sign == -1)
            step = poww(step, mod - 2);

        for (i = 0; i < dim; i += 2 * len) {
            w = 1;

            for (j = 0; j < len; j++) {
                u = data[i + j];
                v = data[i + len + j];

                ll ss = (w * v) % mod;
                data[i + j] = (u + ss) % mod;
                data[i + len + j] = (mod + u - ss) % mod;

                w *= step;
                w %= mod;
            }
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        data[x - 1] += 1;
    }


    for (big_dim = 1024; data[big_dim] == 0; big_dim--);
    big_dim = (big_dim + 1) * k;
    for (; (big_dim & (big_dim - 1)) != 0; big_dim++);

    big_dim = max(big_dim, 2 * 2);
    big_dim = min(big_dim, sz);


    fft(big_dim, data, +1);
    for (i = 0; i < big_dim; i++) data[i] = poww(data[i], k);
    fft(big_dim, data, -1);


    ll inv = poww(big_dim, mod - 2);
    for (i = 0; i < big_dim; i++) {
        data[i] = (data[i] * inv) % mod;

        if (data[i])
            printf("%d ", i + k);
    }

    return 0;
}