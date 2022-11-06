#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 300011;
const int inf = 100000000;


struct Fenwick {
    vector<int> data;
    int n;

    void init(int _n) {
        n = _n;
        data = vector<int>(n + 1, inf);
    }

    int zrs(int x) {
        return (x ^ (x - 1)) & x;
    }

    void add(int x, int v) {
        while (x <= n) {
            data[x] = min(data[x], v);
            x += zrs(x);
        }
    }

    int que(int x) {
        int ans = inf;
        while (x > 0) {
            ans = min(ans, data[x]);
            x -= zrs(x);
        }
        return ans;
    }
};

struct strip {
    int x, y1, y2;
    Fenwick from_left, from_right;
    vector< vector< pair<int, int> > > dist;
};

int n, q, i, j, x, y, cnt, tp;
vector< pair<int, int> > P;
strip S[maxN];
vector<int> list[maxN];
int last[maxN];
map< pair<int, int>, int> M;

int lvl[maxN], dad[maxN];
bool done[maxN];
int down[maxN];
bool any;

vector<int> xx, yy;
bool rev;

void refr(vector<int>& data) {
    for (int i = 0; i < data.size(); i++) {
        if (done[data[i]]) {
            data[i] = data.back();
            data.pop_back();
            i--;
            continue;
        }
    }
}

void dfs1(int node, int root) {
    down[node] = S[node].y2 - S[node].y1 + 1;
    refr(list[node]);
    for (auto to : list[node])
        if (to != root)
            dfs1(to, node), down[node] += down[to];
}

int dfs2(int node, int root, int target) {
    bool ok = (target - down[node] <= target / 2);

    for (auto to : list[node]) {
        if (to == root) continue;
        int ans = dfs2(to, node, target);
        if (ans != 0) return ans;
        ok &= (down[to] <= target / 2);
    }

    if (ok) return node;
    return 0;
}

pair<int, int> get_dist(int prov, int y) {
    int p = max(min(y, S[prov].y2), S[prov].y1);
    auto aux = S[prov].dist.back()[p - S[prov].y1 + 1];
    return mp(aux.first + abs(p - y) + 1, aux.second);
}

void dfs3(int node, int root) {
    int i;

    for (auto to : list[node]) {
        if (to == root) continue;

        S[to].dist.emplace_back();
        S[to].dist.back().pb(mp(0, 0));
        for (i = S[to].y1; i <= S[to].y2; i++)
            S[to].dist.back().pb(get_dist(node, i));

        dfs3(to, node);
    }
}

void solve(int R, int _lvl, int _dad) {
    int i;

    dfs1(R, 0);
    R = dfs2(R, 0, down[R]);
    lvl[R] = _lvl;
    dad[R] = _dad;

    S[R].dist.emplace_back();
    S[R].dist.back().pb(mp(0, 0));
    for (i = S[R].y1; i <= S[R].y2; i++)
        S[R].dist.back().pb(mp(0, i));

    dfs3(R, 0);

    done[R] = true;
    for (auto to : list[R]) solve(to, _lvl + 1, R);
}

void upd() {
    int id = M[mp(x, y)];
    int act;

    for (act = id; act != 0; act = dad[act]) {
        int c = S[id].dist[lvl[act]][y - S[id].y1 + 1].first;
        int p = S[id].dist[lvl[act]][y - S[id].y1 + 1].second;

        S[act].from_left.add(p - S[act].y1 + 1, c - p);
        S[act].from_right.add(S[act].y2 - p + 1, c + p);
    }

    any = true;
};

int que() {
    int id = M[mp(x, y)];
    int act, ans = inf;

    if (!any) return -1;

    for (act = id; act != 0; act = dad[act]) {
        int c = S[id].dist[lvl[act]][y - S[id].y1 + 1].first;
        int p = S[id].dist[lvl[act]][y - S[id].y1 + 1].second;

        ans = min(ans, S[act].from_left.que(p - S[act].y1 + 1) + p + c);
        ans = min(ans, S[act].from_right.que(S[act].y2 - p + 1) - p + c);
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        P.pb(mp(x, y));
        xx.pb(x);
        yy.pb(y);
    }

    sort(xx.begin(), xx.end());
    xx.resize(unique(xx.begin(), xx.end()) - xx.begin());

    sort(yy.begin(), yy.end());
    yy.resize(unique(yy.begin(), yy.end()) - yy.begin());

    if (xx.size() > yy.size()) {
        rev = true;
        for (auto& e : P) swap(e.first, e.second);
    }

    sort(P.begin(), P.end());
    for (i = 0; i < P.size(); i = j) {
        for (j = i + 1; j < P.size(); j++) {
            if (P[j - 1].first != P[j].first) break;
            if (P[j - 1].second + 1 != P[j].second) break;
        }

        S[++cnt] = {P[i].first, P[i].second, P[j - 1].second};
        S[cnt].from_left.init(S[cnt].y2 - S[cnt].y1 + 1);
        S[cnt].from_right.init(S[cnt].y2 - S[cnt].y1 + 1);

        for (y = S[cnt].y1; y <= S[cnt].y2; y++) {
            if (last[y] != 0 && S[last[y]].x + 1 == S[cnt].x) {
                list[last[y]].pb(cnt);
                list[cnt].pb(last[y]);
            }
            last[y] = cnt;
            M[mp(S[cnt].x, y)] = cnt;
        }
    }

    for (i = 1; i <= cnt; i++) {
        sort(list[i].begin(), list[i].end());
        list[i].resize(unique(list[i].begin(), list[i].end()) - list[i].begin());
    }

    solve(1, 0, 0);

    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
        scanf("%d%d%d", &tp, &x, &y);
        if (rev) swap(x, y);

        if (tp == 1)
            upd();
        else
            printf("%d\n", que());
    }



    return 0;
}