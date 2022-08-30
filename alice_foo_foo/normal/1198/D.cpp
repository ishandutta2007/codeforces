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

    void clear() { *this = hash_map_t(mod); }

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

const int N = 55;

int f[N][N][N][N], s[N][N];
char c[N][N];
int n;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c[i] + 1);
        for(register int j = 1; j <= n; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (c[i][j] == '#');
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) {
            for(register int x = 1; x <= n - i + 1; x++) {
                for(register int y = 1; y <= n - j + 1; y++) {
                    int _x = x + i - 1, _y = y + j - 1;
                    if(s[_x][_y] - s[_x][y - 1] - s[x - 1][_y] + s[x - 1][y - 1] == 0) continue;
                    f[x][y][_x][_y] = max(i, j);
                    for(register int k = x; k < _x; k++) f[x][y][_x][_y] = min(f[x][y][_x][_y], f[x][y][k][_y] + f[k + 1][y][_x][_y]);
                    for(register int k = y; k < _y; k++) f[x][y][_x][_y] = min(f[x][y][_x][_y], f[x][y][_x][k] + f[x][k + 1][_x][_y]);
                }
            }
        }
    }
    print(f[1][1][n][n], '\n');
    return 0;
}