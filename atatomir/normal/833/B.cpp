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

#define lSon (node << 1)
#define rSon (lSon | 1)

const int maxN = 35011;
const int inf = 1000000000;

struct aint {
    int data[maxN * 4 + 11];
    int add[maxN * 4 + 11];

    void init(int node, int l, int r, int *from) {
        add[node] = 0;

        if (l == r) {
            data[node] = from[l];
            return;
        }

        int mid = (l + r) >> 1;
        init(lSon, l, mid, from);
        init(rSon, mid + 1, r, from);
        data[node] = max(data[lSon], data[rSon]);
    }

    void upd(int node, int l, int r, int qL, int qR, int v) {
        if (qL > qR) return;

        if (qL <= l && r <= qR) {
            data[node] += v;
            add[node] += v;
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) upd(lSon, l, mid, qL, qR, v);
        if (qR > mid) upd(rSon, mid + 1, r, qL, qR, v);
        data[node] = max(data[lSon], data[rSon]) + add[node];
    }

    int que(int node, int l, int r, int qL, int qR) {
        if (qL > qR) return -inf;

        if (qL <= l && r <= qR) return data[node];
        int mid = (l + r) >> 1;
        int ans = -inf;
        if (qL <= mid) ans = que(lSon, l, mid, qL, qR);
        if (qR > mid) ans = max(ans, que(rSon, mid + 1, r, qL, qR));
        return ans + add[node];
    }
};

int n, k, i, j, ss, dd;
int data[2][maxN], a[maxN];
aint work;

int last[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    ss = 0; dd = 1;
    for (i = 1; i <= n; i++) {
        if (last[a[i]] == 0) {
            last[a[i]] = i;
            data[ss][i] = data[ss][i - 1] + 1;
        } else {
            data[ss][i] = data[ss][i - 1];
        }
    }

    for (int step = 2; step <= k; step++) {
        for (i = 0; i <= n; i++) {
            data[dd][i] = -inf;
            last[i] = 0;
        }
        work.init(1, 1, n, data[ss]);



        for (i = 1; i <= n; i++) {
            if (last[a[i]] == 0) {
                work.upd(1, 1, n, 1, i - 1, +1);
                last[a[i]] = i;
            } else {
                work.upd(1, 1, n, last[a[i]], i - 1, +1);
                last[a[i]] = i;
            }

            /*for (j = 1; j <= n; j++)
                cerr << work.que(1, 1, n, j, j) << ' ';
            cerr << '\n';*/



            if (i >= step) data[dd][i] = work.que(1, 1, n, 1, i - 1);
        }


        swap(ss, dd);
    }

    printf("%d", data[ss][n]);


    return 0;
}