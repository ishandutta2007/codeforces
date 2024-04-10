#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;
template <typename T>
using heap = priority_queue<T, vector<T>, greater<T>>;

struct edge {
    int to;
    int8_t f, c, w;
};

const int N = 5555;
const int V = 2 * N;

vector<edge> es;
vector<int> g[V];

void add_edge(int f, int t, int c, int w) {
    g[f].push_back(es.size());
    es.push_back(edge{t, 0, c, w});
    g[t].push_back(es.size());
    es.push_back(edge{f, 0, 0, -w});
}

int s, t, n;
int a[N];

int ph[V];
int p[V];
int d[V];
int add_flow() {
    fill(p, p + V, -1);
    fill(d, d + V, int(1e9));
    d[s] = 0;
    heap<pair<int, int>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int cd = q.top().first;
        q.pop();
        if (cd != d[v]) {
            continue;
        }
        for (int i : g[v]) {
            edge e = es[i];
            if (e.f == e.c) {
                continue;
            }
            if (d[e.to] > d[v] + e.w + ph[v] - ph[e.to]) {
                d[e.to] = d[v] + e.w + ph[v] - ph[e.to];
                p[e.to] = i;
                q.push({d[e.to], e.to});
            }
        }
    }

    if (d[t] == 1e9) {
        return 0;
    }
    int mn = 1e9;
    int i = t;
    while (p[i] != -1) {
        edge e = es[p[i]];
        mn = min(mn, e.c - e.f);
        i = es[p[i] ^ 1].to;
    }
    i = t;
    while (p[i] != -1) {
        es[p[i]].f += mn;
        es[p[i] ^ 1].f -= mn;
        i = es[p[i] ^ 1].to;
    }
    int res = mn * (d[t] + ph[t]);
    rep(i, 0, V) {
        ph[i] += d[i];
    }
    return res;
}

void solve(istream& cin, ostream& cout) {
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }

    s = 2 * n;
    t = 2 * n + 1;

    rep(i, 0, n) {
        int ms[1 << 3] = {0};
        rep(j, i + 1, n) {
            int m = 0;
            if (a[i] - a[j] == 1) {
                m |= 1;
            }
            if (a[j] - a[i] == 1) {
                m |= 2;
            }
            if (a[i] % 7 == a[j] % 7) {
                m |= 4;
            }
            if (m && ms[m] < 3) {
                ms[m]++;
                add_edge(i + n, j, 1, 0);
            }
        }
        add_edge(s, i, 1, 0);
        add_edge(i + n, t, 1, 0);
        add_edge(i, i + n, 1, -1);
    }

    int c1 = add_flow();
    int c2 = add_flow();
//    cerr << c1 << " " << c2 << endl;
    cout << -c1 - c2;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//tqcpbs