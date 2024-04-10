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

const int N = 2e5 + 5;

struct ele {
    int x, y;
    ele (int a = 0, int b = 0) : x(a), y(b) {}
};

queue <ele> q;
vector <int> adj[N];
int f[205][205], cnt[70];
ll a[N];
int n, ans = 0x7f7f7f7f;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        read(a[i]);
        if(a[i] == 0) { --i; --n; continue; }
        for(register int j = 0; j <= 62; j++) {
            if((a[i] >> j) & 1) ++cnt[j];
        }
    }
    for(register int i = 0; i <= 62; i++) if(cnt[i] >= 3) { print(3, '\n'); return 0; }
    memset(f, 0x3f, sizeof(f));
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(a[i] & a[j]) adj[i].push_back(j);
        }
    }
    for(register int i = 1; i <= n; i++) {
        memset(f, 0x7f, sizeof(f));
        for(register int j = 0; j < (int)adj[i].size(); j++) {
            int v = adj[i][j];
            f[v][i] = 1; q.push(ele(v, i));
        }
        while(!q.empty()) {
            ele u = q.front(); q.pop();
            for(register int j = 0; j < (int)adj[u.x].size(); j++) {
                int v = adj[u.x][j];
                if(v == u.y) continue;
                if(f[v][u.x] > f[u.x][u.y] + 1) {
                    f[v][u.x] = f[u.x][u.y] + 1;
                    q.push(ele(v, u.x));
                }
            }
        }
        for(register int j = 1; j <= n; j++) ans = min(ans, f[i][j]);
    }
    if(ans == 0x7f7f7f7f) print(-1, '\n');
    else print(ans, '\n');
    return 0;
}