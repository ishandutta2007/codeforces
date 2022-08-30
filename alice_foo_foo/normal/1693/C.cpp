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

const int N = 2e5 + 5;

priority_queue <pii> Q;
vector <int> adj[N];
int dis[N], cnt[N], deg[N];
int n, m;

int main() {
    memset(dis, 0x3f, sizeof(dis));
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        ++deg[u];
        adj[v].push_back(u);
    }
    dis[n] = 0; Q.push(make_pair(0, n));
    while (!Q.empty()) {
        pii t = Q.top(); Q.pop();
        if (-t.first != dis[t.second]) continue;
        for (auto v : adj[t.second]) {
            ++cnt[v];
            int tmp = dis[t.second] + deg[v] - cnt[v] + 1;
            if (dis[v] > tmp) {
                dis[v] = tmp;
                Q.push(make_pair(-dis[v], v));
            }
        }
    }
    print(dis[1], '\n');
    return 0;
}