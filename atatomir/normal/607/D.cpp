#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxQ 200011
#define maxN maxQ
#define mod 1000000007LL
#define ll long long
#define lSon (node << 1)
#define rSon (lSon | 1)

ll inv[maxN];
int val[maxN];
int val_fixed[maxN];
int link_lin_val[maxN];

class aint {
    public:
        void init(int _n, ll *_data, ll *_all) {
            n = _n;
            data = _data;
            all = _all;

            init_tree(1, 1, n);
        }

        void update_val(int node, int l, int r, int pos, ll val) {
            if (l == r) {
                data[node] = (val * all[node]) % mod;
                return;
            }

            int mid = (l + r) >> 1;
            if (pos <= mid)
                update_val(lSon, l, mid, pos, val);
            else
                update_val(rSon, mid + 1, r, pos, val);

            update_node(node);
        }

        void update_intr(int node, int l, int r, int qL, int qR, ll _val) {
            if (qL <= l && r <= qR) {
                all[node] = (all[node] * _val) % mod;
                if (l != r)
                    update_node(node);
                else
                    data[node] = (1LL * val_fixed[ link_lin_val[l] ] * all[node]) % mod;

                return;
            }

            int mid = (l + r) >> 1;
            if (qL <= mid)
                update_intr(lSon, l, mid, qL, qR, _val);
            if (qR >  mid)
                update_intr(rSon, mid + 1, r, qL, qR, _val);

            update_node(node);
        }

        ll query(int node, int l, int r, int qL, int qR, ll upper) {
            if (qL <= l && r <= qR)
                return (data[node] * upper) % mod;

            ll ans = 0;
            int mid = (l + r) >> 1;

            if (qL <= mid)
                ans += query(lSon, l, mid, qL, qR, (upper * all[node]) % mod);
            if (qR >  mid)
                ans += query(rSon, mid + 1, r, qL, qR, (upper * all[node]) % mod);

            while (ans >= mod) ans -= mod;
            return ans;
        }

        ll query_all(int node, int l, int r, int pos) {
            if (l == r)
                return all[node];

            int mid = (l + r) >> 1;

            if (pos <= mid)
                return (query_all(lSon, l, mid, pos) * all[node] ) % mod;
            else
                return (query_all(rSon, mid + 1, r, pos) * all[node] ) % mod;
        }


    private:
        int n;
        ll *data;
        ll *all;

        void init_tree(int node, int l, int r) {
            data[node] = 0;
            all[node] = 1;

            if (l == r)
                return;

            int mid = (l + r) >> 1;
            init_tree(lSon, l, mid);
            init_tree(rSon, mid + 1, r);
        }

        void update_node (int node) {
            data[node] = (data[lSon] + data[rSon]) * all[node];
            data[node] %= mod;
        }
};

int n, i, q, p, v, type, dad[maxN];
int sons[maxN];
pair<int, int> op[maxQ];

vector<int> list[maxN];

int dim;
int lin_l[maxN], lin_r[maxN];

//! ------------- aint vars --------------

ll aint_data[maxN << 2];
ll aint_all[maxN << 2];
aint work;

//! --------------------------------------

void dfs(int node) {
    dim++;
    lin_l[node] = dim;
    link_lin_val[ dim ] = node;

    for (auto to : list[node])
        dfs(to);

    lin_r[node] = dim;
}

ll my_pow(ll a, ll b) {
    ll ans = 1;

    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &val[1], &q);
    n = 1;

    for (i = 1; i <= q; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d", &p, &v);
            val[++n] = v;
            op[i] = mp(1, n);
            list[p].pb(n);
            dad[n] = p;
        } else {
            scanf("%d", &p);
            op[i] = mp(2, p);
        }
    }

    dfs(1);
    work.init(n, aint_data, aint_all);

    inv[1] = 1;
    for (i = 2; i <= n; i++)
        inv[i] = my_pow(i, mod - 2);

    op[0] = mp(1, 1);

    for (i = 0; i <= q; i++) {
        if (op[i].first == 1) { //! type 1
            int node = op[i].second;
            sons[node] = 1;

            work.update_val(1, 1, n, lin_l[node], val[node]);
            val_fixed[node] = val[node];
            if (dad[node] != 0) {
                work.update_intr(1, 1, n, lin_l[ dad[node] ], lin_r[ dad[node] ], inv[sons[ dad[node] ] ]);
                sons[ dad[node] ]++;
                work.update_intr(1, 1, n, lin_l[ dad[node] ], lin_r[ dad[node] ], sons[ dad[node] ]);
            }

        } else { //! type 2
            int node = op[i].second;

            ll ans = work.query(1, 1, n, lin_l[node], lin_r[node], 1);
            if (node != 1) {
                node = dad[node];
                ll aux = work.query_all(1, 1, n, lin_l[node]);
                aux = my_pow(aux, mod - 2);
                ans = (ans * aux) % mod;
            }

            printf("%I64d\n", ans);
        }
    }


    return 0;
}