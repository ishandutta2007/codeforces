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
#define lSon (node << 1)
#define rSon (lSon | 1)

struct aint {
    int dim;
    int cnt[maxN * 4 + 11];
    int lazy[maxN * 4 + 11];

    void init(int _dim) {
        dim = _dim;
    }

    void combine(int tp, int node, int l, int r) {
        if (tp == 0) return;

        if (tp == 1) {
            cnt[node] = r - l + 1;
            lazy[node] = 1;
        }

        if (tp == 2) {
            cnt[node] = 0;
            lazy[node] = 2;
        }

        if (tp == 3) {
            cnt[node] = r - l + 1 - cnt[node];
            if (lazy[node] == 0) {
                lazy[node] = 3;
            } else {
                if (lazy[node] == 3)
                    lazy[node] = 0;
                else
                    lazy[node] ^= 3;
            }
        }
    }

    void upd(int node, int l, int r, int qL, int qR, int tp) {
        if (qL <= l && r <= qR) {
            combine(tp, node, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        combine(lazy[node], lSon, l, mid);
        combine(lazy[node], rSon, mid + 1, r);
        lazy[node] = 0;

        if (qL <= mid) upd(lSon, l, mid, qL, qR, tp);
        if (qR > mid) upd(rSon, mid + 1, r, qL, qR, tp);
        cnt[node] = cnt[lSon] + cnt[rSon];
    }

    int que(int node, int l, int r) {
        if (l == r) return l;

        int mid = (l + r) >> 1;
        combine(lazy[node], lSon, l, mid);
        combine(lazy[node], rSon, mid + 1, r);
        lazy[node] = 0;

        if (cnt[lSon] != mid - l + 1)
            return que(lSon, l, mid);
        else
            return que(rSon, mid + 1, r);
    }
};

int n, i;
int q_tp[maxN];
pair<ll, ll> Q[maxN];
vector<ll> xx;
aint work;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    xx = {1};
    for (i = 1; i <= n; i++) {
        scanf("%d%lld%lld", &q_tp[i], &Q[i].first, &Q[i].second);
        xx.pb(Q[i].first);
        xx.pb(Q[i].second + 1);
    }

    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());

    int dim = xx.size();
    work.init(dim);

    for (i = 1; i <= n; i++) {
        int p1 = lower_bound(xx.begin(), xx.end(), Q[i].first) - xx.begin() + 1;
        int p2 = lower_bound(xx.begin(), xx.end(), Q[i].second + 1) - xx.begin();
        work.upd(1, 1, dim, p1, p2, q_tp[i]);
        int ans = work.que(1, 1, dim);
        printf("%lld\n", xx[ans - 1]);
    }

    return 0;
}