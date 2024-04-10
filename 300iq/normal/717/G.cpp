#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

struct edge {
    int v, to, cap, cost;
    edge(int a, int b, int c, int e) {
        v = a, to = b, cap = c, cost = e;
    }
    edge() {}
};

const int N = (int) 500 + 7;
const int M = (int) 3e5 + 7;
const int INF = (int) 1e9 + 7;
int d[N], pr[N];
edge e[M];
char s[N];
char t[N];
int n, m, p, q, x;

void add_edge(int v, int to, int cap, int cost) {
    e[m++] = {v, to, cap, cost};
    e[m++] = {to, v, 0, -cost};
    return;
}

int mincost() {
    for (int i = 0; i <= n; i++) {
        d[i] = INF;
        pr[i] = -1;
    }
    d[0] = 0;
    pr[0] = -1;
    bool good = 1;
    while (good) {
        good = 0;
        for (int i = 0; i < m; i++) {
            if (e[i].cap > 0 && d[e[i].v] + e[i].cost < d[e[i].to]) {
                d[e[i].to] = d[e[i].v] + e[i].cost;
                pr[e[i].to] = i;
                good = 1;
            }
        }
    }
    int v = n;
    while (pr[v] != -1) {
        e[pr[v]].cap--;
        e[pr[v] ^ 1].cap++;
        v = e[pr[v]].v;
    }
    return d[n];
}

int main() {
    scanf("%d", &n);
    scanf(" %s", s);
    scanf("%d", &q);
    while (q--) {
        scanf(" %s", t);
        scanf("%d", &p);
        int f = strlen(t);
        for (int i = 0; i + f - 1 < n; i++) {
            bool eq = 1;
            for (int j = i; j < i + f; j++) {
                eq &= (t[j - i] == s[j]); 
            }
            if (eq) {
                add_edge(i, i + f, 1, -p);
            }
        }
    }
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        add_edge(i, i + 1, INF, 0);
    }
    int ans = 0; 
    for (int i = 0; i < x; i++) {
        ans += -mincost();
    }
    printf("%d\n", ans);
}