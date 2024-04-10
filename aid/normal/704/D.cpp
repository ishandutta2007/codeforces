#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, c, f, id;

    Edge(int _to, int _c, int _id): to(_to), c(_c), f(0), id(_id) {}
};

const int MAXN = 300 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
int x[MAXN], y[MAXN], dx[MAXN], dy[MAXN], cntx[MAXN], cnty[MAXN],
    dd[MAXN], pos[MAXN];
char ans[MAXN];
map<int, int> mpx, mpy;
vector<Edge> e;
vector<int> g[MAXN];

int addx(int xx) {
    if(mpx.find(xx) == mpx.end()) {
        int id = mpx.size();
        mpx[xx] = id;
        dx[id] = INF;
    }
    return mpx[xx];
}

int addy(int yy) {
    if(mpy.find(yy) == mpy.end()) {
        int id = mpy.size();
        mpy[yy] = id;
        dy[id] = INF;
    }
    return mpy[yy];
}

void addEdge(int v, int u, int c, int id) {
    g[v].push_back(e.size());
    e.push_back(Edge(u, c, id));
    g[u].push_back(e.size());
    e.push_back(Edge(v, 0, -1));
}

bool bfs(int s, int t, int n) {
    for(int i = 0; i < n; i++)
        dd[i] = INF;
    dd[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty() && dd[t] >= INF) {
        int v = q.front();
        q.pop();
        for(size_t i = 0; i < g[v].size(); i++) {
            int u = e[g[v][i]].to, cf = e[g[v][i]].c - e[g[v][i]].f;
            if(cf && dd[u] >= INF) {
                dd[u] = dd[v] + 1;
                q.push(u);
            }
        }
    }
    return dd[t] < INF;
}

bool dfs(int v, int t) {
    if(v == t)
        return true;
    for(; pos[v] < (int)g[v].size(); pos[v]++) {
        int id = g[v][pos[v]], u = e[id].to, cf = e[id].c - e[id].f;
        if(dd[u] == dd[v] + 1 && cf && dfs(u, t)) {
            e[id].f++;
            e[id ^ 1].f--;
            return true;
        }
    }
    return false;
}

int maxFlow(int s, int t, int n) {
    for(size_t i = 0; i < e.size(); i++)
        e[i].f = 0;
    int res = 0;
    while(bfs(s, t, n)) {
        for(int i = 0; i < n; i++)
            pos[i] = 0;
        while(dfs(s, t))
            res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, red, blue;
    cin >> n >> m >> red >> blue;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < m; i++) {
        int t, l, d;
        cin >> t >> l >> d;
        if(t == 1) {
            int id = addx(l);
            dx[id] = min(dx[id], d);
        }
        else {
            int id = addy(l);
            dy[id] = min(dy[id], d);
        }
    }
    int xs = mpx.size(), ys = mpy.size();
    for(int i = 0; i < n; i++) {
        int v = (mpx.find(x[i]) == mpx.end()? xs : mpx[x[i]]),
            u = (mpy.find(y[i]) == mpy.end()? ys : mpy[y[i]]);
        addEdge(v, xs + 1 + u, 1, i);
        cntx[v]++;
        cnty[u]++;
    }
    int ss = xs + 1 + ys + 1, tt = ss + 1, s = tt + 1, t = s + 1, needf = 0;
    for(int i = 0; i < xs; i++)
        if(dx[i] >= cntx[i])
            addEdge(ss, i, cntx[i], -1);
        else {
            int l = (cntx[i] - dx[i] + 1) / 2, r = (cntx[i] + dx[i]) / 2;
            if(l > r) {
                cout << -1 << '\n';
                return 0;
            }
            needf += l;
            addEdge(ss, i, r - l, -1);
            addEdge(ss, t, l, -1);
            addEdge(s, i, l, -1);
        }
    addEdge(ss, xs, cntx[xs], -1);
    for(int i = 0; i < ys; i++)
        if(dy[i] >= cnty[i])
            addEdge(xs + 1 + i, tt, cnty[i], -1);
        else {
            int l = (cnty[i] - dy[i] + 1) / 2, r = (cnty[i] + dy[i]) / 2;
            if(l > r) {
                cout << -1 << '\n';
                return 0;
            }
            needf += l;
            addEdge(xs + 1 + i, tt, r - l, -1);
            addEdge(xs + 1 + i, t, l, -1);
            addEdge(s, tt, l, -1);
        }
    addEdge(xs + 1 + ys, tt, cnty[ys], -1);
    int l = -1, r = n;
    while(l < r - 1) {
        int mid = (l + r) / 2;
        addEdge(tt, ss, mid, -1);
        if(maxFlow(s, t, t + 1) == needf)
            r = mid;
        else
            l = mid;
        g[tt].pop_back();
        g[ss].pop_back();
        e.pop_back();
        e.pop_back();
    }
    addEdge(tt, ss, r, -1);
    if(maxFlow(s, t, t + 1) != needf) {
        cout << -1 << '\n';
        return 0;
    }
    cout << (long long)r * max(red, blue) +
        (long long)(n - r) * min(red, blue) << '\n';
    for(int i = 0; i <= xs; i++)
        for(size_t j = 0; j < g[i].size(); j++) {
            int id = e[g[i][j]].id, f = e[g[i][j]].f;
            if(id != -1) {
                if(f)
                    ans[id] = (red > blue? 'r' : 'b');
                else
                    ans[id] = (red > blue? 'b' : 'r');
            }
        }
    for(int i = 0; i < n; i++)
        cout << ans[i];
    cout << '\n';
    return 0;
}