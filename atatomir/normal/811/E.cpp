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
#define lSon (node << 1)
#define rSon (lSon | 1)

int n, m, q, i, j, st, vv;
int mat[13][maxN];
int val[maxN], last[maxN];

struct le_ri_data {
    int cnt;
    int le[11], ri[11];
} aux;

struct aint {
    int dim;
    le_ri_data data[maxN * 4 + 11];
    int dad[111];

    int Find(int x) {
        if (dad[x] == x) return x;
        dad[x] = Find(dad[x]);
        return dad[x];
    }

    bool Merge(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x == y) return false;
        dad[x] = y;
        return true;
    }

    void combine(le_ri_data& dest, le_ri_data f1, le_ri_data f2, int mid) {
        static int i;

        memcpy(dest.le, f1.le, sizeof(dest.le));
        memcpy(dest.ri, f2.ri, sizeof(dest.ri));
        dest.cnt = f1.cnt + f2.cnt;

        for (i = 1; i <= 4 * n; i++) dad[i] = i;
        for (i = 1; i <= n; i++) {
            if (mat[i][mid] != mat[i][mid + 1]) continue;
            if (Merge(f1.ri[i], f2.le[i] + 2 * n)) dest.cnt--;
        }

        st++; vv = 0;
        for (i = 1; i <= n; i++) {
            int x = Find(dest.le[i]);
            if (last[x] != st) {
                last[x] = st;
                val[x] = ++vv;
            }
            dest.le[i] = val[x];
        }
        for (i = 1; i <= n; i++) {
            int x = Find(dest.ri[i] + 2 * n);
            if (last[x] != st) {
                last[x] = st;
                val[x] = ++vv;
            }
            dest.ri[i] = val[x];
        }
    }

    void build(int node, int l, int r) {
        if (l == r) {
            int i, j;

            for (i = 1; i <= n; i = j) {
                data[node].cnt++;
                for (j = i; j <= n; j++) {
                    if (mat[j][l] != mat[i][l]) break;
                    data[node].le[j] = data[node].ri[j] = data[node].cnt;
                }
            }

            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        combine(data[node], data[lSon], data[rSon], mid);
    }

    void init(int _dim) {
        dim = _dim;
        build(1, 1, dim);
    }

    void que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) {
            if (aux.cnt == 0)
                aux = data[node];
            else
                combine(aux, aux, data[node], l - 1);
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) que(lSon, l, mid, qL, qR);
        if (qR > mid) que(rSon, mid + 1, r, qL, qR);
    }
};

aint work;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    work.init(m);

    for (i = 1; i <= q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        aux.cnt = 0;
        work.que(1, 1, m, l, r);
        printf("%d\n", aux.cnt);
    }



    return 0;
}