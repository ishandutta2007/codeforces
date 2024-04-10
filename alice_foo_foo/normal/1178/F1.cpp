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

const int N = 1e6 + 5, M = 505, md = 998244353;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}
 
inline int mul(int x, int y) { return 1ll * x * y % md; }

vector <int> son[N];
int f[M][M], a[N], l[M], r[M], id[M], pre[M];
int n, m, cnt, ans = 1;

bool cmp(int x, int y) { return l[x] < l[y]; }

int dfs(int L, int R) {
    // cout << L << " " << R << endl;
    if(L > R) return 1;
    if(f[L][R]) return f[L][R];
    if(L == R) {
        int u = pre[L];
        if(son[u].size() == 0) return 1;
        // fprintf(stderr, "f[%d][%d] = %d\n", id[son[u][0]], id[son[u][son[u].size() - 1]], dfs(id[son[u][0]], id[son[u][son[u].size() - 1]]));
        int fir = 0, ans = 1;
        for(register int i = 1; i < (int)son[u].size(); i++) {
            if(l[son[u][i]] != r[son[u][i - 1]] + 1) ans = mul(ans, dfs(id[son[u][fir]], id[son[u][i - 1]])), fir = i;
        }
        if(fir == 0) ans = mul(ans, dfs(id[son[u][fir]], id[son[u][son[u].size() - 1]]));
        return f[L][R] = ans;
    }
    int minn = L;
    for(register int i = L + 1; i <= R; i++) if(pre[i] < pre[minn]) minn = i;
    int sum1 = 0, sum2 = 0;
    for(register int i = L; i <= minn; i++) sum1 = add(sum1, mul(dfs(L, i - 1), dfs(i, minn - 1)));
    for(register int i = minn; i <= R; i++) sum2 = add(sum2, mul(dfs(minn + 1, i), dfs(i + 1, R)));
    // fprintf(stderr, "f[%d][%d] = %d\n", L, R, mul(dfs(minn, minn), mul(sum1, sum2)));
    return f[L][R] = mul(dfs(minn, minn), mul(sum1, sum2));
}

int st[M][25], lg[M];

int query(int l, int r) {
    int k = lg[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= m; i++) {
        read(a[i]);
        if(!l[a[i]]) l[a[i]] = i;
        r[a[i]] = i;
        st[i][0] = a[i];
    }
    for(register int j = 1; j <= 20; j++) {
        for(register int i = 1; i <= m - (1 << j) + 1; j++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    lg[0] = -1;
    for(register int i = 1; i <= m; i++) lg[i] = lg[i >> 1] + 1;
    for(register int i = 1; i <= n; i++) {
        int minn = query(l[i], r[i]);
        if(minn < i) {
            print(0, '\n');
            return 0;
        }
    }
    for(register int i = 1; i <= n; i++) {
        bool ok = 0;
        for(register int j = i - 1; j >= 1; j--) {
            if(l[j] <= l[i] && r[i] <= r[j]) {
                son[j].push_back(i);
                // fprintf(stderr, "fa[%d] = %d\n", i, j);
                ok = 1; break;
            }
        }
        if(!ok) son[0].push_back(i);
    }
    for(register int i = 0; i <= n; i++) {
        sort(son[i].begin(), son[i].end(), cmp);
        for(register int j = 0; j < (int)son[i].size(); j++) {
            id[son[i][j]] = ++cnt;
            pre[cnt] = son[i][j];
            // fprintf(stderr, "pre[%d] = %d\n", cnt, son[i][j]);
        }
    }
    int fir = 0;
    for(register int i = 1; i < (int)son[0].size(); i++) {
        if(l[son[0][i]] != r[son[0][i - 1]] + 1) ans = mul(ans, dfs(id[son[0][fir]], id[son[0][i - 1]])), fir = i;
    }
    if(fir == 0) ans = mul(ans, dfs(id[son[0][fir]], id[son[0][son[0].size() - 1]]));
    print(ans, '\n');
    // print(f[1][1], '\n');
    // print(pre[7], '\n');
    // print(f[7][8], '\n');
    return 0;
}