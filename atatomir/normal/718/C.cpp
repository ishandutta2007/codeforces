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

#define maxN 100011
#define mod 1000000007

#define lSon (node << 1)
#define rSon (lSon | 1)

ll d1[2][2], d2[2][2];

struct Matrix {
    int n, m;
    ll data[2][2];

    Matrix() {}
    Matrix(char tp) {
        memset(data, 0, sizeof(data));
        n = m = 2;
        if (tp == 'v') m = 1;
        if (tp == 'm') data[0][0] = data[1][1] = 1;
    }

    void operator*=(Matrix &who) {
        int i, j, k;

        if (m != who.n) cerr << "err";
        memcpy(d1, data, sizeof(data));
        memcpy(d2, who.data, sizeof(who.data));

        for (i = 0; i < n; i++) {
            for (j = 0; j < who.m; j++) {
                data[i][j] = 0;
                for (k = 0; k < m; k++)
                    data[i][j] += d1[i][k] * d2[k][j];
                data[i][j] %= mod;
            }
        }

        m = who.m;
    }

    void operator+=(const Matrix who) {
        int i, j;

        if (n != who.n) cerr << "err";
        if (m != who.m) cerr << "err";

        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                data[i][j] = (data[i][j] + who.data[i][j]) % mod;
    }
} aux;

Matrix poww(Matrix a, int how) {
    Matrix ans('m');

    while (how > 0) {
        if (how & 1) ans *= a;
        how >>= 1;
        a *= a;
    }

    return ans;
}

struct aint {
    int n;
    Matrix *down;
    Matrix *here;
    Matrix *from;

    void build(int node, int l, int r) {
        if (l == r) {
            here[node] = Matrix('m');
            down[node] = from[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        here[node] = Matrix('m');
        down[node] = down[lSon];
        down[node] += down[rSon];
    }

    void init(int _n, Matrix *_down, Matrix *_here, Matrix *_from) {
        n = _n;
        down = _down;
        here = _here;
        from = _from;

        build(1, 1, n);
    }

    void update(int node, int l, int r, int qL, int qR, Matrix& how) {
        if (qL <= l && r <= qR) {
            here[node] *= how;
            aux = how; aux *= down[node];
            down[node] = aux;
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) update(lSon, l, mid, qL, qR, how);
        if (qR > mid) update(rSon, mid + 1, r, qL, qR, how);

        down[node] = down[lSon];
        down[node] += down[rSon];

        aux = here[node]; aux *= down[node];
        down[node] = aux;
    }

    Matrix query(int node, int l, int r, int qL, int qR, Matrix up) {
        if (qL <= l && r <= qR) {
            up *= down[node];
            return up;
        }

        up *= here[node];
        Matrix ans('v');

        int mid = (l + r) >> 1;
        if (qL <= mid) ans += query(lSon, l, mid, qL, qR, up);
        if (qR > mid) ans += query(rSon, mid + 1, r, qL, qR, up);

        return ans;
    }
};

int n, q, i, x, tp, l, r;
Matrix here[maxN << 2], down[maxN << 2], from[maxN];
aint work;

Matrix Fib('m'), ini('v');

int main()
{
    //freopen("test.in","r",stdin);

    Fib.data[0][1] = Fib.data[1][0] = 1;
    Fib.data[1][1] = 0;

    ini.data[0][0] = 1;

    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);

        from[i] = poww(Fib, x - 1);
        from[i] *= ini;
    }

    work.init(n, down, here, from);

    for (i = 1; i <= q; i++) {
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d%d%d", &l, &r, &x);

            Matrix act = poww(Fib, x);
            work.update(1, 1, n, l, r, act);
        } else {
            scanf("%d%d", &l, &r);
            printf("%lld\n", work.query(1, 1, n, l, r, Matrix('m')).data[0][0]);
        }
    }


    return 0;
}