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

struct aint {
    int dim;
    vector<int> vals[maxN * 4 + 11];
    vector<int> le[maxN * 4 + 11];
    vector<int> ri[maxN * 4 + 11];
    int *from;

    void build(int node, int l, int r) {
        if (l == r) {
            vals[node] = {from[l]};
            return;
        }

        int mid = (l + r) >> 1;
        build(lSon, l, mid);
        build(rSon, mid + 1, r);

        int p1 = 0;
        int p2 = 0;
        int from;

        while (p1 < vals[lSon].size() || p2 < vals[rSon].size()) {
            if (p1 == vals[lSon].size() || p2 == vals[rSon].size()) {
                if (p1 == vals[lSon].size())
                    from = 2;
                else
                    from = 1;
            } else {
                if (vals[lSon][p1] < vals[rSon][p2])
                    from = 1;
                else
                    from = 2;
            }

            if (from == 1)
                vals[node].pb(vals[lSon][p1++]);
            else
                vals[node].pb(vals[rSon][p2++]);

            le[node].pb(p1);
            ri[node].pb(p2);
        }

    }

    void init(int _dim, int *_from) {
        dim = _dim;
        from = _from;
        build (1, 1, dim);
    }

    int query(int node, int l, int r, int qL, int qR, int pos) {
        if (pos < 0) return 0;
        if (qL <= l && r <= qR)
            return pos + 1;

        int mid = (l + r) >> 1;
        int ans = 0;

        if (qL <= mid)
            ans += query(lSon, l, mid, qL, qR, le[node][pos] - 1);
        if (qR > mid)
            ans += query(rSon, mid + 1, r, qL, qR, ri[node][pos] - 1);

        return ans;
    }
};

int n, k, q, i;
int a[maxN];
vector<int> last[maxN];
int go[maxN];

int ans, x, y, l, r;
aint work;

void pre() {
    int i;

    for (i = n; i > 0; i--) {
        if (last[a[i]].size() >= k)
            go[i] = last[a[i]][ last[a[i]].size() - k ];
        else
            go[i] = n + 1;

        last[a[i]].pb(i);
    }

    work.init(n, go);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);

    pre();
    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d", &x, &y);
        l = (x + ans) % n; l++;
        r = (y + ans) % n; r++;
        if (l > r) swap(l, r);

        int arg = upper_bound(work.vals[1].begin(), work.vals[1].end(), r) - work.vals[1].begin() - 1;
        ans = work.query(1, 1, n, l, n, arg);

        ans = r - l + 1 - ans;
        cout << ans << '\n';
    }


    return 0;
}