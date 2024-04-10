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

struct atom {
    int u, v, w;
    atom (int a = 0, int b = 0, int c = 0) : u(a), v(b), w(c) {}
} e[N];

bool operator < (const atom a, const atom b) {
    return a.w < b.w;
}

set <pii> all;
set <int> qwq;
int f[N], g[1000][1000], _u[N], _v[N];
int n, m;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int chkedg(int u, int v) {
    if (u > v) swap(u, v);
    return all.find(make_pair(u, v)) != all.end();
}

int main() {
    read(n); read(m);
    int _xor = 0;
    if (1ll * n * (n - 1) / 2 - m <= n - 1) {
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            read(u); read(v); read(w);
            if (u > v) swap(u, v);
            _xor ^= w;
            g[u][v] = 1;
            e[i] = atom(u, v, w);
        }
        sort(e + 1, e + m + 1);
        int len = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!g[i][j]) {
                    ++len;
                    _u[len] = i;
                    _v[len] = j;
                }
            }
        }
        ll minn = 1e18;
        for (int i = 1; i <= len; i++) {
            ll sum = 0;
            for (int j = 1; j <= n; j++) f[j] = j;
            for (int j = 1; j <= len; j++) {
                if (i == j) continue;
                f[find(_u[j])] = find(_v[j]);
            }
            int flag = 0;
            for (int j = 1; j <= m; j++) {
                if (!flag && e[j].w >= _xor) {
                    int x = find(_u[i]);
                    int y = find(_v[i]);
                    if (x != y) {
                        f[x] = y;
                        sum += _xor;
                    }
                    flag = 1;
                }
                int x = find(e[j].u);
                int y = find(e[j].v);
                if (x != y) {
                    f[x] = y;
                    sum += e[j].w;
                }
            }
            minn = min(minn, sum);
        }
        print(minn, '\n');
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        read(u); read(v); read(w);
        _xor ^= w;
        if (u > v) swap(u, v);
        all.insert(make_pair(u, v));
        e[i] = atom(u, v, w);
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; i++) qwq.insert(i), f[i] = i;
    for (int i = 1; i <= n; i++) {
        if (qwq.find(i) != qwq.end()) {
            qwq.erase(i);
            queue <int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                vector <int> tem;
                for (auto it = qwq.begin(); it != qwq.end(); ++it) {
                    if (chkedg(u, *it) == 0) {
                        tem.push_back(*it);
                        f[find(*it)] = find(u);
                        q.push(*it);
                    }
                }
                for (auto i : tem) qwq.erase(i);
            }
        }
    }
    ll ans = 0;
    for (int j = 1; j <= m; j++) {
        int x = find(e[j].u);
        int y = find(e[j].v);
        if (x != y) {
            f[x] = y;
            ans += e[j].w;
        }
    }
    print(ans, '\n');
    return 0;
}