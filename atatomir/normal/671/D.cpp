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

#define maxN 300011
#define lSon (node << 1)
#define rSon (lSon | 1)
#define inf (1LL << 55)

class aint {
    public:
        void init(ll *_data, ll * _addon) {
            data = _data;
            addon = _addon;
        }

        void update(int node, int l, int r, int pos, ll val) {
            if (l == r) {
                data[node] = min(inf, val);
                return;
            }

            int mid = (l + r) >> 1;
            if (pos <= mid)
                update(lSon, l, mid, pos, val);
            else
                update(rSon, mid + 1, r, pos, val);

            data[node] = min(inf, min(data[lSon], data[rSon]) + addon[node]);
        }

        void add_sum(int node, int l, int r, int qL, int qR, ll val) {
            if (qL <= l && r <= qR) {
                addon[node] = min(inf, addon[node] + val);
                data[node] = min(inf, data[node] + val);

                return;
            }

            int mid = (l + r) >> 1;
            if (qL <= mid)
                add_sum(lSon, l, mid, qL, qR, val);
            if (qR >  mid)
                add_sum(rSon, mid + 1, r, qL, qR, val);

            data[node] = min(inf, min(data[lSon], data[rSon]) + addon[node]);
        }

        ll query(int node, int l, int r, int qL, int qR) {
            if (qL <= l && r <= qR) return data[node];

            int mid = (l + r) >> 1;
            ll ans = inf;

            if (qL <= mid)
                ans = min(ans, query(lSon, l, mid, qL, qR));
            if (qR >  mid)
                ans = min(ans, query(rSon, mid + 1, r, qL, qR));

            return min(inf, ans + addon[node]);
        }

    private:
        ll *data;
        ll *addon;
};


int n, m, i, x, y, cnt;
vector<int> list[maxN];
vector<int> add[maxN], rm[maxN];
int pos_l[maxN], pos_r[maxN];
int wh[maxN];
ll cost[maxN];
bool us[maxN];

ll aint_data[maxN << 2];
ll aint_addon[maxN << 2];

ll dp[maxN];
aint work;

ll final_answer;



void dfs(int node) {
    us[node] = true;

    pos_l[node] = cnt + 1;
    for (int act : add[node]) wh[act] = ++cnt;
    for (int to : list[node])
        if (!us[to])
            dfs(to);
    pos_r[node] = cnt;
}

void solve(int node) {
    ll all = 0;
    int root = -1;

    //! compute sons
    us[node] = true;
    for (int to : list[node]) {
        if (us[to]) {root = to; continue;}

        solve(to);
        all += dp[to];
        all = min(all, inf);
    }

    if (all >= inf) all = 2 * inf;


    //! add new workers
    for (int act : add[node]) work.update(1, 1, m, wh[act], cost[act] + all);
    //! rm old workers
    for (int act : rm[node]) work.update(1, 1, m, wh[act], inf);
    //! add new sons
    for (int to : list[node])
        if (to != root)
            if (pos_l[to] <= pos_r[to])
                work.add_sum(1, 1, m, pos_l[to], pos_r[to], all - dp[to]);

    //! compute actual dp
    dp[node] = (pos_l[node] <= pos_r[node] ? work.query(1, 1, m, pos_l[node], pos_r[node]) : inf);

    final_answer = all;
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &cost[i]);
        add[x].pb(i);
        rm[y].pb(i);
    }

    dfs(1);
    work.init(aint_data, aint_addon);

    memset(us, 0, sizeof(us));
    solve(1);

    if (final_answer >= inf) final_answer = -1;
    printf("%lld", final_answer);

    return 0;
}