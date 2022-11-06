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

struct edge {
    int from, to, z, id;
};

bool on_way[111111];
int p[111111];
int pr[111111];
vector<edge> g[111111][2];
int d[111111];
int k1[111111];

edge es[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 0; i < m; i++) {
        scid(x, y, z);
        --x; --y;
        g[x][z].push_back({x, y, z, i});
        g[y][z].push_back({y, x, z, i});
        es[i] = {x, y, z, i};
    }

    fill(d, d + n, 1e9);
    fill(p, p + n, -1);
    d[0] = 0;

    vector<int> q;
    q.push_back(0);

    vector<int> nq;

    while (!q.empty()) {
        for (int z = 1; z >= 0; z--) {
            for (auto v : q) {
                for (edge &e : g[v][z]) {
                    if (d[e.to] > d[v] + 1) {
                        d[e.to] = d[v] + 1;
                        p[e.to] = e.id;
                        pr[e.to] = v;
                        nq.push_back(e.to);
                        k1[e.to] = k1[v] + z;
                    }
                    if (d[e.to] == d[v] + 1 && k1[e.to] < k1[v] + z) {
                        p[e.to] = e.id;
                        pr[e.to] = v;
                        k1[e.to] = k1[v] + z;
                    }
                }
            }
        }
        q = nq;
        nq.clear();
    }

    int cur = n - 1;
    while (cur != 0) {
        edge& e = es[p[cur]];
        on_way[e.id] = true;
        cur = pr[cur];
    }

    vector<edge> ans;
    for (int i = 0; i < m; i++) {
        if (on_way[i] && es[i].z == 0) {
            ans.push_back({es[i].from, es[i].to, 1});
        }
        if (!on_way[i] && es[i].z == 1) {
            ans.push_back({es[i].from, es[i].to, 0});
        }
    }

    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.from + 1 << " " << i.to + 1 << " " << i.z << "\n";
    }



    return 0;
}