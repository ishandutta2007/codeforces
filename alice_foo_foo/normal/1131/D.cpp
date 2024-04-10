#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 2005;

vector <int> adj[N], adj2[N];
char c[N][N];
int n, m;

int low[N], dfn[N], col[N], st[N], top, inst[N], f[N], in[N], cnt, color, gs;
void tarjan(int u) {
    low[u] = dfn[u] = ++cnt; st[++top] = u; inst[u] = 1;
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++color;
        while(st[top + 1] != u) {
            int tmp = st[top--];
            col[tmp] = color;
            inst[tmp] = 0;
        }
    }
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            if(c[i][j] == '=') {
                adj[i].push_back(j + n);
                adj[j + n].push_back(i);
            }
        }
    }
    for(register int i = 1; i <= n + m; i++) if(!dfn[i]) tarjan(i);
    for(register int i = 1; i <= n + m; i++) adj[i].clear();
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            if(c[i][j] == '<') {
                if(col[i] == col[j + n]) {
                    cout << "No" << endl;
                    return 0;
                }
                adj[col[i]].push_back(col[j + n]);
                ++in[col[j + n]];
            }
            if(c[i][j] == '>') {
                if(col[i] == col[j + n]) {
                    cout << "No" << endl;
                    return 0;
                }
                adj[col[j + n]].push_back(col[i]);
                ++in[col[i]];
            }
        }
    }
    queue <int> q;
    for(register int i = 1; i <= color; i++) {
        if(!in[i]) {
            q.push(i);
            f[i] = 1;
        }
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        ++gs;
        for(register unsigned i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            --in[v];
            f[v] = max(f[v], f[u] + 1);
            if(!in[v]) q.push(v);
        }
    }
    if(gs != color) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(register int i = 1; i <= n; i++) print(f[col[i]], ' ');
    putchar('\n');
    for(register int i = 1; i <= m; i++) print(f[col[i + n]], ' ');
    putchar('\n');
    return 0;
}