#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 3e5 + 5;

vector <int> adj[N], ans;
queue <int> q;
int used[N];
int T, n, m;

void dfs1(int u) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (!used[v]) {
            used[v] = 1;
            ans.push_back(v);
            vector <int> tmp;
            for (int j = 0; j < (int)adj[v].size(); j++) {
                if (!used[adj[v][j]]) {
                    used[adj[v][j]] = 1;
                    tmp.push_back(adj[v][j]);
                }
            }
            for (int j = 0; j < (int)tmp.size(); j++) dfs1(tmp[j]);
        }
    }
}

int main() {
    read(T);
    while (T--) {
        read(n); read(m); ans.clear();
        for (int i = 1; i <= n; i++) {
            used[i] = 0;
            adj[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            read(u); read(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        used[1] = 1; ans.push_back(1);
        vector <int> tmp;
        for (int i = 0; i < (int)adj[1].size(); i++) {
            if (!used[adj[1][i]]) {
                used[adj[1][i]] = 1;
                tmp.push_back(adj[1][i]);
            }
        }
        for (int i = 0; i < (int)tmp.size(); i++) dfs1(tmp[i]);
        int cando = 1;
        for (int i = 1; i <= n; i++) cando &= used[i];
        if (cando) {
            printf("YES\n");
            print((int)ans.size(), '\n');
            for (auto i : ans) print(i, ' ');
            putchar('\n');
        } else printf("NO\n");
    }
    return 0;
}