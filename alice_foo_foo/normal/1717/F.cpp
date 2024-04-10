#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int INF = 1e9;

struct max_flow_t {
    struct edge_t {
        int u, v, next, cap, flow;
        edge_t () {}
        edge_t (int a, int b, int c, int d, int e) : u(a), v(b), next(c), cap(d), flow(e) {}
    };

    vector <edge_t> G;
    vector <int> head, nowhead, d;
    int n, s, t, tot;

    max_flow_t () { G.clear(); head.clear(); tot = 1; }
    max_flow_t (int nn) {
        n = nn; s = 0; t = n + 1;
        G.clear(); head.clear(); head.resize(n + 2, 0); tot = 1;
    }

    inline void addedge(int u, int v, int cap) {
        // fprintf(stderr, "u = %d, v = %d, cap = %d\n", u, v, cap);
        G.resize(tot + 3);
        G[++tot] = (edge_t) {u, v, head[u], cap, 0}, head[u] = tot;
        G[++tot] = (edge_t) {v, u, head[v], 0, 0}, head[v] = tot;
    }

    int bfs() {
        d.clear(); d.resize(n + 2, 0); d[s] = 1;
        queue <int> q; q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(register int i = head[u]; i; i = G[i].next) {
                int v = G[i].v;
                if(G[i].cap > G[i].flow && d[v] == 0) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t];
    }

    int dfs(int u, int Flow) {
        if(u == t || !Flow) return Flow;
        int flow = 0, f;
        for(register int &i = nowhead[u]; i; i = G[i].next) {
            int v = G[i].v;
            if(d[v] == d[u] + 1 && (f = dfs(v, min(Flow, G[i].cap - G[i].flow))) > 0) {
                G[i].flow += f; G[i ^ 1].flow -= f;
                flow += f; Flow -= f;
                if(!Flow) break;
            }
        }
        return flow;
    }

    int dinic() {
        int ans = 0;
        while(bfs()) {
            nowhead = head;
            ans += dfs(s, INF);
        }
        return ans;
    }
} M;

const int N = 1e4 + 5;

queue <int> q;
int a[N], b[N], ss[N], u[N], v[N], id[N], tmp[N];
int n, m, s, t, need;

int main() {
    read(n); read(m); M = max_flow_t(n + 2);
    for (int i = 1; i <= n; i++) read(ss[i]);
    for (int i = 1; i <= n; i++) read(b[i]);
    for (int i = 1; i <= m; i++) {
        read(u[i]); read(v[i]);
        ++b[u[i]]; --b[v[i]]; id[i] = M.tot + 1;
        M.addedge(v[i], u[i], 1);
    }
    s = n + 1; t = n + 2;
    for (int i = 1; i <= n; i++) {
        // fprintf(stderr, "i = %d, a = %d, b = %d\n", i, a[i], b[i]);
        if (ss[i] == 1) {
            if (abs(a[i] - b[i]) % 2 != 0) {
                printf("NO\n");
                return 0;
            }
            if (a[i] > b[i]) {
                // addedge(s, i, (a[i] - b[i]) / 2);
                tmp[s] -= (a[i] - b[i]) / 2;
                tmp[i] += (a[i] - b[i]) / 2;
            }
            if (a[i] < b[i]) {
                // addedge(i, t, (b[i] - a[i]) / 2);
                tmp[i] -= (b[i] - a[i]) / 2;
                tmp[t] += (b[i] - a[i]) / 2;
            }
        } else {
            M.addedge(s, i, 1e9);
            M.addedge(i, t, 1e9);
        }
    }
    for (int i = 1; i <= n + 2; i++) {
        if (tmp[i] > 0) {
            need += tmp[i];
            M.addedge(M.s, i, tmp[i]);
        } else {
            M.addedge(i, M.t, -tmp[i]);
        }
    }
    M.addedge(t, s, 1e9);
    // fprintf(stderr, "ret = %d, need = %d\n", ret, need);
    if (M.dinic() == need) {
        printf("YES\n");
        for (int i = 1; i <= m; i++) {
            if (!M.G[id[i]].flow) print(u[i], ' '), print(v[i], '\n');
            else print(v[i], ' '), print(u[i], '\n');
        }
    } else {
        printf("NO\n");
    }
    return 0;
}