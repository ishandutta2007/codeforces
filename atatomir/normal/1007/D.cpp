#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define maxM 10011
#define maxLog 20
#define lSon (node << 1)
#define rSon (lSon | 1)
#define maxNodes 3000011

class SAT2 {
    public:
        int n;
        vector< vector<int> > list, rev;
        vector<int> state;
        bool accepted;

        void init(int _n) {
            n = _n;
            list = rev = vector< vector<int> >(2 * n + 10, vector<int>(0));
            state = vector<int>(2 * n + 10, -1);
            accepted = false;
        }

        void add_or(int a, int b) {
            //cerr << a << ' ' << b << '\n';

            add_rel(-a, b);
            add_rel(-b, a);
        }

        bool run() {
            int i;

            state = vector<int>(2 * n + 10, -1);
            accepted = true;

            us = vector<bool>(2 * n + 10, false);
            while (!S.empty()) S.pop();

            for (i = 1; i <= 2 * n; i++)
                if (!us[i])
                    dfs(i);

            us = vector<bool>(2 * n + 10, false);

            while (!S.empty()) {
                int node = S.top(); S.pop();
                if (us[node]) continue;

                aux.clear();
                dfs2(node);

                int c = get_color();
                if (!set_color(c)) {
                    accepted = false;
                    return false;
                }
            }

            return true;
        }

    private:
        vector<bool> us;
        stack<int> S;
        vector<int> aux;

        void add_rel(int a, int b) {
            a = get_id(a);
            b = get_id(b);

            list[a].pb(b);
            rev[b].pb(a);
        }

        int get_id(int x) {
            if (x > 0) return x;
            return n - x;
        }

        int get_inv(int x) {
            if (x <= n) return x + n;
            return x - n;
        }

        void dfs(int node) {
            us[node] = true;

            for (auto to : list[node])
                if (!us[to])
                    dfs(to);

            S.push(node);
        }

        void dfs2(int node) {
            us[node] = true;

            for (auto to : rev[node])
                if (!us[to])
                    dfs2(to);

            aux.pb(node);
        }

        int get_color() {
            int ans = 0;

            for (auto e : aux)
                ans = max(ans, state[e]);

            return ans;
        }

        bool set_color(int c) {
            for (auto e : aux) {
                if (state[e] == c) continue;
                if (state[e] != -1) return false;

                state[e] = c;
                state[get_inv(e)] = c ^ 1;

                if (c) {
                    for (auto to : list[e]) {
                        if (state[to] == 0) return false;
                        if (state[to] == 1) continue;
                        state[to] = 1;
                        state[get_inv(to)] = 0;
                    }
                }
            }

            return true;
        }
};

struct node {
    int son[2];
};

int n, m, i, x, y, cnt, head[maxN];
vector<int> list[maxN];
int dad[maxLog][maxN], lvl[maxN];
SAT2 work;
vector<int> to_add[maxN], to_rm[maxN];
node data[maxNodes];
bool dead[maxN];

void dfs(int node, int root) {
    for (auto to : list[node]) {
        if (to == root) continue;
        dad[0][to] = node;
        lvl[to] = lvl[node] + 1;
        dfs(to, node);
    }
}

void pre() {
    int i, j;

    for (i = 1; i < maxLog; i++) {
        for (j = 1; j <= n; j++)
            dad[i][j] = dad[i - 1][dad[i - 1][j]];
    }
}

void go_up(int &x, int cnt) {
    for (int i = 0; cnt > 0; i++, cnt >>= 1)
        if (cnt & 1) x = dad[i][x];
}

int lca(int x, int y) {
    if (lvl[x] > lvl[y]) swap(x, y);
    go_up(y, lvl[y] - lvl[x]);
    if (x == y) return x;
    for (int i = maxLog - 1; i >= 0; i--)
        if (dad[i][x] != dad[i][y])
            x = dad[i][x], y = dad[i][y];
    return dad[0][x];
}

void add_interv(int x, int y, int id) {
    int lc = lca(x, y);
    int xx = x, yy = y;

    if (lvl[x] > lvl[lc]) to_add[x].pb(id);
    if (lvl[y] > lvl[lc]) to_add[y].pb(id);


    go_up(xx, lvl[x] - lvl[lc] - 1);
    go_up(yy, lvl[y] - lvl[lc] - 1);
    to_rm[xx].pb(id);
    to_rm[yy].pb(id);
}

int merge_trees(int n1, int n2) {
    if (n1 == 0) return n2;
    if (n2 == 0) return n1;

    int id = ++cnt;
    data[id].son[0] = merge_trees(data[n1].son[0], data[n2].son[0]);
    data[id].son[1] = merge_trees(data[n1].son[1], data[n2].son[1]);
    return id;
}

int add(int act, int l, int r, int pos, bool rm = false) {
    if (l == r) {
        if (rm) pos = 0;
        return pos;
    }
    int mid = (l + r) >> 1;
    int id = ++cnt;

    data[id] = data[act];

    if (pos <= mid)
        data[id].son[0] = add(data[act].son[0], l, mid, pos, rm);
    else
        data[id].son[1] = add(data[act].son[1], mid + 1, r, pos, rm);

    return id;
}

void mv(int act) {

    cerr << act << ' ';
    cerr << "{";
    if (data[act].son[0] != 0)
        mv(data[act].son[0]);
    cerr << "/";
    if (data[act].son[1] != 0)
        mv(data[act].son[1]);
    cerr << "}";
    //if (data[act].son[0] == 0 && data[act].son[1] == 0)
    //    cerr << act << ' ';
}

void solve(int node, int root) {
    int R = ++cnt;

    for (auto to : list[node]) {
        if (to == root) continue;
        solve(to, node);
        R = merge_trees(R, head[to]);
    }

    for (auto e : to_add[node])
        if (dead[e] == false)
            R = add(R, 1, 2 * m, e);

    /*cerr << node << ": ";
    mv(R);
    cerr << '\n';
    */

    for (auto e : to_rm[node])
        R = add(R, 1, 2 * m, e, true)/*, dead[e] = true*/;

    /*cerr << node << ": ";
    mv(R);
    cerr << '\n';
    */

    head[node] = R;


}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }


    dfs(1, 0);
    pre();


    work.init(maxNodes);
    scanf("%d", &m);
    cnt = 2 * m + 1;

    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add_interv(x, y, i);
        scanf("%d%d", &x, &y);
        add_interv(x, y, i + m);

        work.add_or(i, i + m);
        work.add_or(-i, -(i + m));
    }


    solve(1, 0);
    for (i = 1; i <= cnt; i++) {
        if (data[i].son[0] != 0)
            work.add_or(-data[i].son[0], i);
        if (data[i].son[1] != 0)
            work.add_or(-data[i].son[1], i);
        if (data[i].son[0] * data[i].son[1] != 0)
            work.add_or(-data[i].son[0], -data[i].son[1]);
    }


    work.run();
    if (!work.accepted) {
        printf("NO");
        return 0;
    }

    printf("YES\n");
    for (i = 1; i <= m; i++) {
        if (work.state[i])
            printf("1\n");
        else
            printf("2\n");
    }


    return 0;
}