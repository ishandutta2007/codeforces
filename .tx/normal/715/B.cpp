#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

struct Edge {
    int f, t, w, id;
};

vector<Edge> g[1111];
lint d[1111][1111];

const lint inf = 1e18;
bool done[1111];
int p[1111][1111];

Edge es[22222];
lint nw[11111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, L, s, t);
    for (int i = 0; i < m; i++) {
        scid(x, y, z);
        g[x].push_back(es[i * 2] = Edge{x, y, z, i * 2});
        g[y].push_back(es[i * 2 + 1] = Edge{y, x, z, i * 2 + 1});
        nw[i] = z;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = inf;
        }
    }

    memset(p, -1, sizeof(int) * 1111 * 1111);

    d[0][s] = 0;

    for (int e = 0; e < n; e++) {
        priority_queue<pair<lint, int> > q;
        for (int i = 0; i < n; i++) {
            if (d[e][i] != inf) {
                q.push({-d[e][i], i});
            }
        }
        memset(done, false, sizeof(done));

        while (!q.empty()) {
            int v = q.top().second;
            q.pop();
            if (done[v]) {
                continue;
            }
            done[v] = true;
            for (auto& i : g[v]) {
                int to = i.t;
                int c = i.w;
                int ne = e + (i.w == 0 ? 1 : 0);
                if (d[ne][to] > d[e][v] + c) {
                    d[ne][to] = d[e][v] + c;
                    p[ne][to] = i.id;
                    if (ne == e) {
                        q.push({-d[ne][to], to});
                    }
                }
            }
        }
    }

    if (d[0][t] < L) {
        cout << "NO";
        return 0;
    }

    int ok = -1;
    for (int i = 0; i < n; i++) {
        if (d[i][t] + i <= L) {
            ok = i;
            break;
        }
    }

    if (ok == -1) {
        cout << "NO";
        return 0;
    }

    int x = t;
    int e = ok;
    lint last_w = L - d[ok][t] - (ok - 1);
    int last = -1;
    while (p[e][x] != -1) {
        auto& q = es[p[e][x]];
        if (q.w == 0) {
            nw[q.id >> 1] = 1;
            e--;
            last = q.id;
        }
        x = q.f;
    }
    if (last != -1) {
        nw[last >> 1] = last_w;
    }

    cout << "YES\n";
    for (int i = 0; i < 2 * m; i += 2) {
        cout << es[i].f << " " << es[i].t << " ";
        if (es[i].w != 0) {
            cout << es[i].w;
        } else {
            if (nw[es[i].id >> 1] == 0) {
                cout << inf;
            } else {
                cout << nw[es[i].id >> 1];
            }
        }
        cout << "\n";
    }


    return 0;
}