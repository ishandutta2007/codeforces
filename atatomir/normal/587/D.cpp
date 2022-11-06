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

#define maxN 400011

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

        void set_false(int a, int st) {
            int b = n;
            if (a == b) b = 1;

            add_or(-a, -b);
            add_or(-a, b);
        }


        bool check() {
            int i;

            for (i = 1; i <= 2 * n; i++)
                for (auto to : list[i])
                    if (state[i] == 1 && state[to] == 0)
                        return false;
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

struct edge {
    int x, y, c, t;
};

int n, m, i, cnt;
edge E[maxN];
vector< pair<int, int> > list[maxN];
SAT2 work;
vector<int> sol;

void no_sol() {
    printf("No");
    exit(0);
}

void build(int node) {
    int i, j;
    bool any = false;

    sort(list[node].begin(), list[node].end(), [](pair<int, int> a, pair<int, int> b)->bool const {
        return E[a.second].c < E[b.second].c;
    });

    for (i = 0; i < list[node].size(); i = j) {
        for (j = i; j < list[node].size(); j++)
            if (E[list[node][i].second].c != E[list[node][j].second].c)
                break;

        if (j - i > 2) no_sol();
        if (j - i == 2 && any) no_sol();

        if (j - i == 2) {
            any = true;
            work.add_or(list[node][i].second, list[node][i + 1].second);
        }
    }

    if (list[node].size() <= 1) return;

    ++cnt;
    work.add_or(-list[node][0].second, cnt);
    work.add_or(-list[node][1].second, cnt);
    work.add_or(-list[node][0].second, -list[node][1].second);

    for (i = 2; i < list[node].size(); i++) {
        work.add_or(-cnt, cnt + 1);
        work.add_or(-list[node][i].second, cnt + 1);
        work.add_or(-list[node][i].second, -cnt);
        cnt++;
    }
}

bool check(int val) {
    int i;

    //work.reset();

    work.init(4 * m); cnt = m;
    for (i = 1; i <= n; i++) build(i);

    for (i = 1; i <= m; i++)
        if (E[i].t > val)
            work.set_false(i, 0);

    return work.run();
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &E[i].x, &E[i].y, &E[i].c, &E[i].t);
        list[E[i].x].pb(mp(E[i].y, i));
        list[E[i].y].pb(mp(E[i].x, i));
    }

    work.init(4 * m);
    cnt = m;

    for (i = 1; i <= n; i++)
        build(i);

    if (cnt > work.n) return 14;

    if (work.run() == false)
        no_sol();


    int ans = -1;
    for (int step = 1 << 30; step > 0; step >>= 1)
        if (!check(ans + step))
            ans += step;

    ans++;
    if (!check(ans)) return 13;
    if (!work.check()) return cnt;

    for (i = 1; i <= m; i++)
        if (work.state[i] == 1)
            sol.pb(i);

    printf("Yes\n%d %d\n", ans, sol.size());
    for (auto e : sol)
        printf("%d ", e);




    return 0;
}