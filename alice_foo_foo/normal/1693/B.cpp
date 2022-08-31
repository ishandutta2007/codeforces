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

vector <int> adj[N];
int l[N], r[N];
int T, n, ans;

int dfs1(int u) {
    ll sum = 0;
    for (auto v : adj[u]) sum += dfs1(v);
    if (sum >= l[u]) return min((ll)r[u], sum);
    ++ans;
    return r[u];
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 2; i <= n; i++) {
            int x; read(x);
            adj[x].push_back(i);
        }
        for (int i = 1; i <= n; i++) read(l[i]), read(r[i]);
        ans = 0;
        dfs1(1);
        print(ans, '\n');
    }
    return 0;
}