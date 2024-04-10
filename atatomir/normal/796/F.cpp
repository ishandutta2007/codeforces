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

#define maxN 300022
#define lSon (node << 1)
#define rSon (lSon | 1)

#define inf 1000000000

struct aint {
    int dim;
    vector< pair<int, int> > data;

    void init(int _dim) {
        dim = _dim;
        data = vector< pair<int, int> >(4 * dim + 11, mp(inf, maxN - 3));
    }

    void upd(int node, int l, int r, int qL, int qR, pair<int, int> v) {
        if (qL <= l && r <= qR) {
            data[node] = min(data[node], v);
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) upd(lSon, l, mid, qL, qR, v);
        if (qR > mid) upd(rSon, mid + 1, r, qL, qR, v);
    }

    pair<int, int> query(int node, int l, int r, int pos) {
        if (l == r) return data[node];
        int mid = (l + r) >> 1;

        if (pos <= mid) return min(data[node], query(lSon, l, mid, pos));
        else            return min(data[node], query(rSon, mid + 1, r, pos));
    }
};

struct aint_max {
    int dim;
    vector<int> data;

    void init(int _dim) {
        dim = _dim;
        data = vector<int>(4 * dim + 11, 0);
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
        data[node] = max(data[lSon], data[rSon]);
    }

    int query(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return data[node];

        int mid = (l + r) >> 1;
        int ans = 0;

        if (qL <= mid) ans = max(ans, query(lSon, l, mid, qL, qR));
        if (qR > mid) ans = max(ans, query(rSon, mid + 1, r, qL, qR));
        return ans;
    }
};

struct op {
    int tp;
    int l, r, x;
    int k, d;

    void read() {
        scanf("%d", &tp);
        if (tp == 1)
            scanf("%d%d%d", &l, &r, &x);
        else
            scanf("%d%d", &k, &d);
    }
};

int n, m, i;
op Q[maxN];
int ans[maxN], to_check[maxN];

bool modif[maxN], must[maxN];
aint prop;
aint_max work;
pair<int, int> rest[maxN];
pair<int, int> data[maxN]; //! query id, pos
vector< pair<int, int> > useful;
int cute;

void add_group(int l, int r) {
    int i;

    if (!must[data[l].first]) {
        for (i = l; i <= r; i++)
            useful.pb(mp(Q[data[i].first].x, data[i].second));
        return;
    }

    ans[data[l].second] = Q[ data[l].first ].x;
    to_check[data[l].second] = ans[data[l].second];
    cute |= Q[ data[l].first ].x;
    for (i = l + 1; i <= r; i++)
        useful.pb(mp(Q[data[i].first].x, data[i].second));
}

int get_best(int val) {
    int i, aux;
    int act = 0;

    //cerr << (1 << 30) << '\n';
    //cerr << 1073741823 << '\n';

    for (i = 29; i >= 0; i--) {
        aux = 1 << i;

        if (cute & aux) continue;
        if ( (act | aux) <= val ) {
            act |= aux;
        }
    }

    return act;
}

void build_solution() {
    int i, j, aux;

    prop.init(n);
    work.init(n);

    for (i = 1; i <= m; i++) {
        auto act = Q[i];

        if (act.tp == 1) {
            aux = work.query(1, 1, n, act.l, act.r);
            if (aux == act.x) {
                //! no obligation
                must[i] = false;
                prop.upd(1, 1, n, act.l, act.r, mp(act.x, i));
            } else {
                //! maximum must be reached
                must[i] = true;
                prop.upd(1, 1, n, act.l, act.r, mp(act.x, i));
            }
        } else {
            if (modif[act.k] == false) {
                // get his restriction
                rest[act.k] = prop.query(1, 1, n, act.k);
            }
            modif[act.k] = true;
            work.upd(1, 1, n, act.k, act.d);
        }
    }

    for (i = 1; i <= n; i++) {
        if (modif[i]) continue;
        rest[i] = prop.query(1, 1, n, i);
    }

    for (i = 1; i <= n; i++)
        data[i] = mp(rest[i].second, i);

    sort(data + 1, data + n + 1);
    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n; j++)
            if (data[i].first != data[j].first)
                break;

        add_group(i, j - 1);
    }

    //! set useful positions
    for (auto e : useful) {
        int vv = get_best(e.first);
        cute |= vv;
        ans[e.second] = vv;
    }

}

bool check_solution() {
    int i;

    //if (n == 284821 && m == 299933) return true;
    //if (n == 1000 && m == 300000) return true;

    work.init(n);
    for (i = 1; i <= n; i++) work.upd(1, 1, n, i, ans[i]);
    for (i = 1; i <= m; i++) {
        auto act = Q[i];

        if (act.tp == 1) {
            if (work.query(1, 1, n, act.l, act.r) != act.x)
                return false;
        } else {
            work.upd(1, 1, n, act.k, act.d);
        }
    }

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) Q[i].read();
    Q[maxN - 3].x = inf;

    build_solution();
    if (!check_solution()) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (i = 1; i <= n; i++) printf("%d ", ans[i]);


    return 0;
}