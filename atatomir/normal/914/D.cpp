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

#define maxN 500011
#define lSon (node << 1)
#define rSon (lSon | 1)

int gcd(int a, int b) {
    if (a < b) swap(a, b);

    while (b > 0) {
        a %= b;
        swap(a, b);
    }

    return a;
}

struct segm_tree {
    int data[maxN * 4 + 11];
    int *from;
    int n;

    void build(int node, int l, int r) {
        if (l == r) {
            data[node] = from[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);
        data[node] = gcd(data[lSon], data[rSon]);
    }

    void init(int _n, int *_from) {
        n = _n;
        from = _from;
        build(1, 1, n);
    }

    void upd(int node, int l, int r, int pos, int v) {
        if (l == r) {
            data[node] = v;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid)
            upd(lSon, l, mid, pos, v);
        else
            upd(rSon, mid + 1, r, pos, v);
        data[node] = gcd(data[lSon], data[rSon]);
    }

    int que(int node, int l, int r, int qL, int qR, int guess) {
        if (data[node] % guess == 0) return 0;

        if (l == r) return l;

        int mid = (l + r) >> 1;
        int ans = 0;

        if (qL <= mid) ans = que(lSon, l, mid, qL, qR, guess);
        if (ans != 0) return ans;
        if (qR > mid) ans = que(rSon, mid + 1, r, qL, qR, guess);
        return ans;
    }
};

int n, q, i, l, r, x, op;
int a[maxN];
segm_tree work;

bool check() {
    int id = work.que(1, 1, n, l, r, x);

    if (id == 0) return true;

    if (id != l)
        if (work.que(1, 1, n, l, id - 1, x) != 0)
            return false;

    if (id != r)
        if (work.que(1, 1, n, id + 1, r, x) != 0)
            return false;

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    work.init(n, a);

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d%d%d", &l, &r, &x);

            if (check())
                printf("YES\n");
            else
                printf("NO\n");

        } else {
            scanf("%d%d", &l, &x);
            work.upd(1, 1, n, l, x);
        }
    }


    return 0;
}