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

#define maxN 2055
#define eps 1e-6

const int dim = 2048;
const double PI = acos(-1);

struct cc {
    double a, b;

    double imag() {
        return b;
    }

    double imag(double x) {
        return b = x;
    }

    void operator=(double x) {
        a = x;
        b = 0;
    }

    cc operator*(cc who) {
        return {a * who.a - b * who.b, a * who.b + b * who.a};
    }

    cc operator+(cc who) {
        return {a + who.a, b + who.b};
    }

    cc operator-(cc who) {
        return {a - who.a, b - who.b};
    }

    void operator/=(double x) {
        a /= x;
        b /= x;
    }
};

int n, m, i, j, nn, mm, need;
char s[maxN][maxN], p[maxN][maxN];
cc aux[dim + 11], act[dim + 11];

cc cs[dim + 11][dim + 11], cp[dim + 11][dim + 11];

void rev(cc *data, int l, int r) {
    int i, pos;

    for (i = l; i <= r; i++) aux[i] = data[i];

    pos = l;
    for (i = l; i <= r; i += 2) data[pos++] = aux[i];
    for (i = l + 1; i <= r; i += 2) data[pos++] = aux[i];

    if (l == r) return;
    int mid = (l + r) >> 1;
    rev(data, l, mid);
    rev(data, mid + 1, r);
}

void conv(int n, cc *data, bool inv) {
    int len, i, j;
    cc w, rat, u, v;

    rev(data, 0, n - 1);

    for (len = 1; 2 * len <= n; len <<= 1) {
        for (i = 0; i < n; i += 2 * len) {
            rat = {cos(PI / len), sin(PI / len)};
            if (inv) rat.imag(-rat.imag());
            w = 1.00;

            for (j = 0; j < len; j++) {
                u = data[i + j];
                v = data[i + len + j];

                data[i + j] = u + w * v;
                data[i + len + j] = u - w * v;

                w = w * rat;
            }
        }
    }

    if (inv)
        for (i = 0; i < n; i++) data[i] /= n;

}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", s[i]);

    for (i = 0; i <= 800; i++)
        for (j = 0; j <= 800; j++)
            s[i][j] = s[i % n][j % m];

    scanf("%d%d", &nn, &mm);
    for (i = 0; i < nn; i++) {
        scanf("%s", p[i]);

        for (j = 0; j < mm; j++)
            if (p[i][j] != '?')
                need++;
    }


    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            if ('a' <= s[i][j] && s[i][j] <= 'z') {
                int id = s[i][j] - 'a' + 1;
                cs[i][j] = {cos(2.00 * PI * id / 26.00), sin(2.00 * PI * id / 26.00)};
            }

            if ('a' <= p[i][j] && p[i][j] <= 'z') {
                int id = p[i][j] - 'a' + 1;
                cp[nn - i][mm - j] = {cos(-2.00 * PI * id / 26.00), sin(-2.00 * PI * id / 26.00)};
            }
        }
    }
    for (i = 0; i < dim; i++) {
        conv(dim, cs[i], false);
        conv(dim, cp[i], false);
    }


    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) act[j] = cs[j][i];
        conv(dim, act, false);
        for (j = 0; j < dim; j++) cs[j][i] = act[j];

        for (j = 0; j < dim; j++) act[j] = cp[j][i];
        conv(dim, act, false);
        for (j = 0; j < dim; j++) cp[j][i] = act[j];
    }

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            cs[i][j] = cs[i][j] * cp[i][j];

    for (i = 0; i < dim; i++)
        conv(dim, cs[i], true);

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) act[j] = cs[j][i];
        conv(dim, act, true);
        for (j = 0; j < dim; j++) cs[j][i] = act[j];
    }



    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            double dif = cs[i + nn][j + mm].a - need;
            if (-eps <= dif && dif <= eps)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }

    return 0;
}