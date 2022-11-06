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
#define inf (1001000000)

struct query {
    int node, tm, id;
    int sort_val;

    bool operator<(const query& who)const {
        return mp(sort_val, node) < mp(who.sort_val, who.node);
    }
};

struct segm_tree {
    int n;
    vector<int> data;
    vector<int> upds;

    void init(int _n) {
        n = _n;
        data = vector<int>(n << 2, 0);
        upds = vector<int>(n << 2, -inf);
    }

    void update(int node, int l, int r, int qL, int qR, int bg) {
        if (qL <= l && r <= qR) {
            upds[node] = max(upds[node], bg);

            if (l < r)
                data[node] = max(data[lSon], data[rSon]);
            else
                data[node] = 0;

            data[node] = max(data[node], upds[node] + 2 * (r - l));
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) {
            update(lSon, l, mid, qL, qR, bg);
            if (qR > mid)
                update(rSon, mid + 1, r, qL, qR, bg + 2 * (mid - max(l, qL) + 1));
        } else {
            if (qR > mid)
                update(rSon, mid + 1, r, qL, qR, bg);
        }

        data[node] = max(data[lSon], data[rSon]);
        data[node] = max(data[node], upds[node] + 2 * (r - l));
    }

    int query(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return data[node];

        int el = min(r, qR);
        int ans = max(0, upds[node] + 2 * (el - l));
        int mid = (l + r) >> 1;

        if (qL <= mid)
            ans = max(ans, query(lSon, l, mid, qL, qR));
        if (qR > mid)
            ans = max(ans, query(rSon, mid + 1, r, qL, qR));

        return ans;
    }
};

int n, m, i, j, x, aux;
vector<int> list[maxN];
int cnt[maxN], lvl[maxN];

int paths;
vector<int> ways[maxN];
int from[maxN], pos[maxN];
int head[maxN];
segm_tree aint[maxN];

query Q[maxN];
int ans[maxN];


void dfs(int node, int root) {
    pair<int, int> best = mp(-1, -1);
    cnt[node] = 1;

    for (int to : list[node]) {
        if (to == root) continue;
        lvl[to] = lvl[node] + 1;
        dfs(to, node);
        cnt[node] += cnt[to];
        best = max(best, mp(cnt[to], to));
    }

    if (cnt[node] == 1) {
        ways[++paths] = {node};
        from[node] = paths;
        return;
    }

    from[node] = from[best.second];
    ways[from[node]].pb(node);

    for (int to : list[node]) {
        if (to == root || to == best.second) continue;
        head[from[to]] = node;
    }
}

int solve(query act) {
    int node = act.node;
    int tm = act.tm;
    int sval = act.sort_val;
    int prob = node;
    int ans, step;
    int receiver;
    int way_time, how_many;


    while (true) {
        aux = from[prob];
        if (aint[aux].query(1, 1, aint[aux].n, 1, pos[prob]) <= sval) {
            prob = head[aux];
            continue;
        }

        ans = -1;
        for (step = 1 << 17; step > 0; step >>= 1)
            if (pos[prob] - ans - step > 0)
                if (aint[aux].query(1, 1, aint[aux].n, pos[prob] - ans - step, pos[prob]) <= sval)
                    ans += step;

        ans++;
        receiver = ways[aux][pos[prob] - ans];

        break;
    }

    prob = node;
    way_time = sval + 2 * (-lvl[receiver] + lvl[node]);
    while (from[prob] != from[receiver]) {
        aux = from[prob];

        how_many = pos[prob];
        aint[aux].update(1, 1, aint[aux].n, 1, pos[prob], way_time - 2 * (how_many - 1));
        way_time -= 2 * how_many;

        prob = head[aux];
    }

    aux = from[prob];
    aint[aux].update(1, 1, aint[aux].n, pos[receiver], pos[prob], sval);



    //cerr << "solved " << act.id << '\n';
    return tm + 2 * (-lvl[receiver] + lvl[node]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m); n++;
    for (i = 2; i <= n; i++) {
        scanf("%d", &x); x++;
        list[i].pb(x);
        list[x].pb(i);
    }

    lvl[1] = 0;
    dfs(1, 0);
    for (i = 1; i <= paths; i++) {
        aint[i].init(ways[i].size());

        ways[i].pb(-1);
        reverse(ways[i].begin(), ways[i].end());
        for (j = 1; j < ways[i].size(); j++)
            pos[ways[i][j]] = j;
    }

    aux = from[1];
    aint[aux].update(1, 1, aint[aux].n, pos[1], pos[1], inf);

    for (i = 1; i <= m; i++) {
        scanf("%d%d", &Q[i].node, &Q[i].tm); Q[i].node++;
        Q[i].id = i;
        Q[i].sort_val = Q[i].tm + lvl[Q[i].node];
    }

    sort(Q + 1, Q + m + 1);
    for (i = 1; i <= m; i++)
        ans[Q[i].id] = solve(Q[i]);

    for (i = 1; i <= m; i++)
        printf("%d ", ans[i]);


    return 0;
}