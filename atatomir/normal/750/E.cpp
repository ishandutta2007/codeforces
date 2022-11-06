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
#define inf 10000000
#define lSon (node << 1)
#define rSon (lSon | 1)
#define ch s[l]

struct mat {
    int data[5][5];

    mat() {
        static int i, j;

        for (i = 0; i < 5; i++) {
            data[i][i] = 0;
            for (j = i + 1; j < 5; j++)
                data[i][j] = inf;
        }
    }

    void operator*=(mat who) {
        static int aux[5][5];
        static int i, j, k;

        memcpy(aux, data, sizeof(data));
        for (i = 0; i < 5; i++) {
            for (j = i; j < 5; j++) {
                data[i][j] = inf;
                for (k = i; k <= j; k++)
                    data[i][j] = min(data[i][j], aux[i][k] + who.data[k][j]);
            }
        }
    }
};

struct aint {
    vector<mat> data;
    int n;
    char* s;

    void build(int node, int l, int r) {
        if (l == r) {

            if (ch != '2' && ch != '0' && ch != '1' && ch != '6' && ch != '7')
                return;

            if (ch == '2') {
                data[node].data[0][1] = 0;
                data[node].data[0][0] = 1;
                return;
            }

            if (ch == '0') {
                data[node].data[1][2] = 0;
                data[node].data[1][1] = 1;
                return;
            }

            if (ch == '1') {
                data[node].data[2][3] = 0;
                data[node].data[2][2] = 1;
                return;
            }

            if (ch == '6') {
                data[node].data[3][3] = 1;
                data[node].data[4][4] = 1;
                return;
            }

            if (ch == '7') {
                data[node].data[3][4] = 0;
                data[node].data[3][3] = 1;
                return;
            }

            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        data[node] = data[lSon];
        data[node] *= data[rSon];
    }

    void init(int _n, char *_s) {
        n = _n;
        s = _s;
        data = vector<mat>(4 * n + 3);

        build(1, 1, n);
    }

    mat query(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return data[node];

        int mid = (l + r) >> 1;

        if (qL <= mid) {
            if (qR > mid) {
                auto ans = query(lSon, l, mid, qL, qR);
                ans *= query(rSon, mid + 1, r, qL, qR);
                return ans;
            } else {
                return query(lSon, l, mid, qL, qR);
            }
        } else {
            return query(rSon, mid + 1, r, qL, qR);
        }
    }
};

int n, i, q, l, r;
char s[maxN];
aint work;
mat ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n%s", &n, &q, s + 1);
    work.init(n, s);

    for (i = 1; i <= q; i++) {
        scanf("%d%d", &l, &r);
        ans = work.query(1, 1, n, l, r);

        if (ans.data[0][4] >= inf)
            printf("-1\n");
        else
            printf("%d\n", ans.data[0][4]);
    }



    return 0;
}