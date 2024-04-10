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

#define maxN 200011

const int dim = 524288;
const int bits = 19;
const double PI = acos(-1);

struct cc {
    double a, b;

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

    cc set_ang(double ang) {
        a = cos(ang);
        b = sin(ang);
    }
};

int n, m, k, i;
char s[maxN];
char p[maxN];

cc cs[dim + 11], cp[dim + 11];
int sums[maxN];
int ans[maxN];

void fft(int n, cc *data, bool inv) {
    int len, i, j, aux;
    cc u, v, w, root;

    for (i = 0; i < n; i++) {
        aux = 0;
        for (j = 0; j < bits; j++)
            if (i & (1 << j))
                aux |= 1 << (bits - 1 - j);
        if (aux > i) swap(data[i], data[aux]);
    }

    for (len = 1; 2 * len <= n; len <<= 1) {
        root.set_ang(PI / len);
        if (inv) root.b *= -1;

        for (i = 0; i < n; i += 2 * len) {
            w = {1, 0};
            for (j = 0; j < len; j++) {
                u = data[i + j];
                v = data[i + len + j];

                data[i + j] = u + w * v;
                data[i + len + j] = u - w * v;

                w = w * root;
            }
        }
    }

    if (inv) {
        for (i = 0; i < n; i++)
            data[i] /= n;
    }
}

void solve(char c) {
    int i;

    memset(cs, 0, sizeof(cs));
    memset(cp, 0, sizeof(cp));

    for (i = 0; i < m; i++) {
        if (p[i] == c)
            cp[m - i] = {1, 0};
    }

    memset(sums, 0, sizeof(sums));
    for (i = 0; i < n; i++) {
        if (s[i] != c) continue;
        sums[max(0, i - k)]++;
        if (i + k + 1 < n)
            sums[i + k + 1]--;
    }

    for (i = 0; i < n; i++) {
        if (i != 0)
            sums[i] += sums[i - 1];

        if (sums[i] > 0)
            cs[i] = {1, 0};
    }

    fft(dim, cs, false);
    fft(dim, cp, false);
    for (i = 0; i < dim; i++) cs[i] = cs[i] * cp[i];
    fft(dim, cs, true);

    for (i = 0; i < n; i++)
        ans[i] += round(cs[i + m].a);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d\n%s\n%s", &n, &m, &k, s, p);
    solve('C');
    solve('A');
    solve('G');
    solve('T');

    int sol = 0;
    for (i = 0; i < n; i++)
        if (ans[i] == m)
            sol++;

    printf("%d", sol);


    return 0;
}