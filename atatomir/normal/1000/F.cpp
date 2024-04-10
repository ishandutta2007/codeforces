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

const int maxN = 500011;

int bg[maxN], en[maxN];

struct aint {
    vector<int> data[maxN * 4 + 11];

    void add(int node, int l, int r, int qL, int qR, int v) {
        if (qL <= l && r <= qR) {
            data[node].pb(v);
            return;
        }
        int mid = (l + r) >> 1;
        if (qL <= mid) add(lSon, l, mid, qL, qR, v);
        if (qR > mid) add(rSon, mid + 1, r, qL, qR, v);
    }

    int que(int node, int l, int r, int pos) {
        while (!data[node].empty()) {
            int v = data[node].back();
            if (bg[v] < l && r <= en[v]) break;
            data[node].pop_back();
        }
        if (!data[node].empty()) return data[node].back();
        if (l == r) return 0;

        int mid = (l + r) >> 1;
        if (pos <= mid) 
            return que(lSon, l, mid, pos);
        else
            return que(rSon, mid + 1, r, pos);

        return 0;
    }
}; 

int n, i, q, x, y;
int a[maxN], ans[maxN];
vector< pair<int, int> > Q[maxN];
aint work;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y); 
        Q[y].pb(mp(x, i));
    }

    for (i = 1; i <= n; i++) {
        int v = a[i];

        bg[v] = en[v];
        en[v] = i;

        work.add(1, 1, n, bg[v] + 1, en[v], v);

        for (auto e : Q[i]) {
            ans[e.second] = work.que(1, 1, n, e.first);
        }
    }

    for (i = 1; i <= q; i++) printf("%d\n", ans[i]);

    return 0;
}