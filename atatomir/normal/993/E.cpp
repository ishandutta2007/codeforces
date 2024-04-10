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

const int sz = 262144 * 2;
const int maxN = sz + 11;
const double PI = acos(-1.00);
const double eps = 1e-6;

struct comx {
    double a, b;

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

int n, x, i, pos, u;
int v[maxN];
comx aux[maxN];
comx data[maxN], data2[maxN];
ll base;

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

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &x);

    data[0] = u = 1;
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        if (v[i] < x) {
            pos++;
            data[pos] = 1;
            u = 1;
        } else {
            data[pos].a += 1;
            base += 1LL * u;
            u++;
        }
    }

    memcpy(data2, data, sizeof(data));
    reverse(data2, data2 + pos + 1);

    fft(sz, data, +1);
    fft(sz, data2, +1);
    for (i = 0; i < sz; i++) data[i] = data[i] * data2[i];
    fft(sz, data, -1);

    printf("%lld ", base);
    for (i = 1; i <= n; i++) {
        ll act;

        if (pos - i >= 0)
            act = llround(data[pos - i].a);
        else
            act = 0;

        printf("%lld ", act);
    }



    return 0;
}