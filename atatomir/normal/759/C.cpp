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
#define maxN 100011

struct aint {
    int n;
    vector<int> data, add;

    void init(int _n) {
        n = _n;
        data = add = vector<int>(4 * n + 11, 0);
    }

    void update(int node, int l, int r, int qL, int qR, int v) {
        if (qL <= l && r <= qR) {
            add[node] += v;
            data[node] += v;
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid)
            update(lSon, l, mid, qL, qR, v);
        if (qR > mid)
            update(rSon, mid + 1, r, qL, qR, v);

        data[node] = max(data[lSon], data[rSon]) + add[node];
    }

    int query(int node, int l, int r, int ss) {
        // no solution
        if (data[node] + ss <= 0)
            return -1;

        if (l == r) return l;

        int mid = (l + r) >> 1;
        if (data[rSon] + ss + add[node] >= 1)
            return query(rSon, mid + 1, r, ss + add[node]);
        return query(lSon, l, mid, ss + add[node]);
    }

};

int n, i, op, x;
int p[maxN], v[maxN];
aint work;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    work.init(n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        scanf("%d", &op);

        if (op == 0) {
            work.update(1, 1, n, 1, p[i], -1);
        } else {
            scanf("%d", &x);
            v[p[i]] = x;
            work.update(1, 1, n, 1, p[i], +1);
        }

        int ans = work.query(1, 1, n, 0);
        if (ans == -1)
            printf("-1\n");
        else
            printf("%d\n", v[ans]);
    }



    return 0;
}