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

const int sz = 131072 * 2;
const int maxN = sz + 11;
const double PI = acos(-1.00);

struct comx {
    double a, b;

    comx() {a = b = 0;}

    comx(double _a, double _b) {a = _a; b = _b;}

    bool operator=(double x) {
        a = x; b = 0;
    }

    comx operator+(comx who) {
        return {a + who.a, b + who.b};
    }

    comx operator-(comx who) {
        return {a - who.a, b - who.b};
    }

    comx operator*(comx who) {
        return {a * who.a - b * who.b, a * who.b + b * who.a};
    }

    comx operator/(double x) {
        return {a / x, b / x};
    }
};

int n, k, x, i, j;
comx aux[maxN];
comx data[maxN];
bool ini[maxN];


void rev(int l, int r, comx* data) {
    if (l == r) return;

    int i, p = l;
    for (i = l; i <= r; i++) aux[i] = data[i];
    for (i = l; i <= r; i += 2) data[p++] = aux[i];
    for (i = l + 1; i <= r; i += 2) data[p++] = aux[i];

    int mid = (l + r) >> 1;
    rev(l, mid, data);
    rev(mid + 1, r, data);
}

void fft(int dim, comx* data, double sgn) {
    int i, j, len;
    comx w, r, u, v;

    rev(0, dim - 1, data);

    for (len = 1; 2 * len <= dim; len <<= 1) {
        r = {cos(PI / len), sin(sgn * PI / len)};

        for (i = 0; i < dim; i += 2 * len) {
            w = 1;

            for (j = 0; j < len; j++) {
                u = data[i + j];
                v = data[i + len + j];

                data[i + j] = u + w * v;
                data[i + len + j] = u - w * v;
                w = w * r;
            }
        }
    }

    if (sgn < 0.00) {
        for (i = 0; i < dim; i++)
            data[i] = data[i] / dim;
    }
}

int gcd(int x, int y) {
    if (x < y) swap(x, y);
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}


int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    ini[0] = true;

    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        x %= k;
        x = gcd(x, k);

        if (x == 0) continue;

        if (!ini[x]) {
            ini[x] = true;
            for (j = 0; j < k; j += x) data[j] = 1.00;
        }
    }

    for (i = 0; i < k; i++)
        if (data[i].a > 0.50)
            ini[i] = true;

    bool any = true;
    while (any) {
        any = false;

        fft(sz, data, +1);
        for (i = 0; i < sz; i++) data[i] = data[i] * data[i];
        fft(sz, data, -1);
        for (i = k; i < 2 * k; i++) data[i - k] = data[i - k] + data[i];

        for (i = 0; i < k; i++) {
            if (data[i].a > 0.50) {
                if (ini[i] == false) any = true;
                ini[i] = true;
                data[i] = 1.00;
            } else {
                data[i] = 0.00;
            }
        }
    }

    int ans = 0;
    for (i = 0; i < k; i++)
        if (ini[i])
            ans++;

    printf("%d\n", ans);
    for (i = 0; i < k; i++)
        if (ini[i])
            printf("%d ", i);


    return 0;
}