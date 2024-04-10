#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int mod = 1e9 + 7;

int add(int x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int mul(ll x, ll y) {
    return x * y % mod;
}

int udd(int &x, int y) {
    return x = add(x, y);
}

int sub(int x, int y) {
    return add(x, mod - y);
}

int bin(int x, int to) {
    int y = 1;
    while (to) {
        if (to & 1)
            y = mul(x, y);
        x = mul(x, x);
        to >>= 1;
    }
    return y;
}

int inv(int x) {
    assert(x != 0);
    return bin(x, mod - 2);
}

const int M = 1000100;
const int N = 1e6;
const int A = 6;
const int B = 10;

int n, y[M];
int pw[B];

void pre() {
    pw[0] = 1;
    for (int i = 1; i < B; ++i)
        pw[i] = 10 * pw[i - 1];
}

int dig(int mask, int i) {
    return (mask / pw[i]) % 10;
}

int swp(int mask, int i, int to) {
    return mask + pw[i] * (to - dig(mask, i));
}

void conv(int *a) {
    for (int i = 0; i < A; ++i) {
        for (int mask = N - 1; mask >= 0; --mask) {
            int d = dig(mask, i);
            if (d == 0)
                continue;
            int to = swp(mask, i, d - 1);
            udd(a[to], a[mask]);
        }
    }
}

void uconv(int *a) {
    for (int i = 0; i < A; ++i) {
        for (int mask = 0; mask < N; ++mask) {
            int d = dig(mask, i);
            if (d == 9)
                continue;
            int to = swp(mask, i, d + 1);
            a[mask] = sub(a[mask], a[to]);
        }
    }
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", y + i);
    }
}

int a[M], b[M], c[M], d[M];

void kill() {
    for (int i = 0; i < n; ++i) {
        int x = y[i];
        udd(a[x], 1);
        udd(b[x], x);
        udd(c[x], mul(x, x));
    }

    conv(a);
    conv(b);
    conv(c);

    //for (int mask = 0; mask < 1000; ++mask)
        //if (a[mask]) {
            //cerr << mask << " " << a[mask] << endl;
        //}
    //cerr << "---\n";

    for (int mask = 0; mask < N; ++mask) {
        if (a[mask] == 0)
            continue;
        if (a[mask] == 1) {
            d[mask] = c[mask];
            continue;
        }
        d[mask] = mul(bin(2, a[mask] - 2), add(c[mask], mul(b[mask], b[mask])));
    }


    uconv(d);

    //for (int mask = 0; mask < 1000; ++mask)
        //if (d[mask]) {
            //cerr << mask << " " << 1ll * mask * d[mask] << endl;
        //}

    ll ans = 0;
    for (int mask = 0; mask < N; ++mask)
        ans ^= 1ll * mask * d[mask];

    cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif


  pre();
  read();
  kill();
}