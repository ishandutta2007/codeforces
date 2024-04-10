#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
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

const int N = 1005;

vector <int> adj[N];
vector <pii> now;
int siz[N];
int n;

void dfs1(int u, int fa) {
    siz[u] = 1;
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        dfs1(v, u); siz[u] += siz[v];
    }
}

void dfs2(int u, int fa) {
    int sum = 0;
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        dfs2(v, u);
        print(u, ' '); print(v, ' '); print(sum + 1, '\n');
        sum += siz[v];
    }
}

void dfs3(int u, int fa, int tmp) {
    int sum = 0;
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        dfs3(v, u, tmp);
        print(u, ' '); print(v, ' '); print((sum + 1) * tmp, '\n');
        sum += siz[v];
    }
}

int main() {
    read(n);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(register int i = 1; i <= n; i++) {
        dfs1(i, 0); now.clear();
        for(register int j = 0; j < (int)adj[i].size(); j++) {
            int v = adj[i][j]; now.push_back(make_pair(siz[v], v));
        }
        sort(now.begin(), now.end());
        int sum = 0;
        for(register int j = (int)now.size() - 1; j >= 0; j--) {
            sum += now[j].first;
            if((sum + 1) * (n - sum) - 1 >= 2 * n * n / 9) {
                int s = 0;
                for(register int k = 0; k < j; k++) {
                    dfs3(now[k].second, i, sum + 1);
                    print(i, ' '); print(now[k].second, ' '); print((s + 1) * (sum + 1), '\n');
                    s += now[k].first;
                }
                s = 0;
                for(register int k = j; k < (int)now.size(); k++) {
                    dfs2(now[k].second, i);
                    print(i, ' '); print(now[k].second, ' '); print(s + 1, '\n');
                    s += now[k].first;
                }
                return 0;
            }
        }
    }
    return 0;
}