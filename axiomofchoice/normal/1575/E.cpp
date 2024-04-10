// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i, a, b) for (int i = (a), ib = (b); i < ib; i++)
#define repeat_back(i, a, b) for (int i = (b)-1, ib = (a); i >= ib; i--)
#define fi first
#define se second
#define int ll
namespace start {
typedef long long ll;
const int inf = INT_MAX >> 1;
const ll INF = INT64_MAX >> 1;
typedef double lf;
const lf pi = acos(-1);
typedef pair<int, int> pii;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1},
          dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
template <int fast = 0>
ll read() {  // will detect EOF
    if (!fast) {
        ll x;
        if (scanf("%lld", &x) != 1) exit(0);
        return x;
    }
    ll x = 0, tag = 1;
    int c = getchar();
    for (; !isdigit(c); c = getchar()) {
        if (c == '-') tag = -1;
        if (c == EOF) exit(0);
    }
    for (; isdigit(c); c = getchar()) {
        x = x * 10 + c - 48;
    }
    if (c != EOF) ungetc(c, stdin);
    return x * tag;
}
lf readf() {
    double x;
    if (scanf("%lf", &x) != 1) exit(0);
    return x;
}  // will detect EOF
template <class T>
void write(T x) {
    if (x < 0) {
        x = -x, putchar('-');
    }
    if (x >= 10) {
        write(x / 10);
    }
    putchar(x % 10 + 48);
}
void write(double x) { printf("%.12f", x); }
void write(long double x) { printf("%.12f", double(x)); }
template <class A, class B>
void write(const pair<A, B> &x) {
    write(x.first);
    putchar(' ');
    write(x.second);
}
template <class T>
void print(T x, int e = 1) {
    write(x);
    putchar(" \n"[e]);
}
template <class T>
void print(const initializer_list<T> &a, int e = 1) {
    for (auto i = a.begin(), last = prev(a.end()); i != a.end(); i++)
        print(*i, e && i == last);
}
template <class T>
void printArray(const T &a, int e = 1) {
    for (auto i = a.begin(), last = prev(a.end()); i != a.end(); i++)
        print(*i, e && i == last);
}
template <class T, int N>
void mst(T (&a)[N], char c) {
    memset(a, c, sizeof a);
}
template <class T>
T &MAX(T &a, const T &b) {
    if (a < b) a = b;
    return a;
}
template <class T>
T &MIN(T &a, const T &b) {
    if (b < a) a = b;
    return a;
}
template <class T>
vector<T> &operator<<(vector<T> &a, const T &b) {
    a.push_back(b);
    return a;
}
template <class T>
T sqr(const T &x) {
    return x * x;
}
template <class T>
void sortunique(T &a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}
void OK(const char *msg = "Yes") {
    puts(msg);
    throw 0;
}
void GG(const char *msg = "No") {
    puts(msg);
    throw 0;
}
// int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
const int N = 400010;
const lf eps = 1e-9;
const int mod = (1 ? 1000000007 : 998244353);
int D(int x, int m = mod) { return x >= m ? x - m : x; }
int mul(int a, int b, int m = mod) { return 1ll * a * b % m; }
template <class T>
int qpow(int a, T b, int m = mod) {
    int ans = 1;
    for (; b; a = mul(a, a, m), b >>= 1)
        if (b & 1) ans = mul(ans, a, m);
    return ans;
}
}  // namespace start
using namespace start;
const int debug = 0;
vector<pii> a[N];
bool vis[N];
int w[N];
namespace center {
vector<int> rec;
int sz[N], maxx[N];
void dfs(int x, int fa = -1) {
    rec << x;
    sz[x] = 1;
    maxx[x] = 0;
    for (auto i : a[x]) {
        int p = i.fi;
        if (p != fa && !vis[p]) {
            dfs(p, x);
            sz[x] += sz[p];
            maxx[x] = max(maxx[x], sz[p]);
        }
    }
}
int get(int x) {  // get center
    rec.clear();
    dfs(x);
    int n = sz[x], ans = x;
    for (auto x : rec) {
        maxx[x] = max(maxx[x], n - sz[x]);
        if (maxx[x] < maxx[ans]) ans = x;
    }
    return ans;
}
}  // namespace center
vector<pii> rec;
void getdist(int x, int co, size_t cost, int value, int fa = -1) {
    if (cost >= rec.size()) rec.push_back(pii());
    // orz(cost, value);
    (rec[cost].fi += value) %= mod;
    rec[cost].se++;
    for (auto i : a[x]) {
        int p = i.fi;
        if (p != fa && !vis[p]) {
            getdist(
                p,
                i.se,
                cost + (co != i.se),
                value + w[p],
                x
            );
        }
    }
}
struct pqnode {
    array<vector<pii>, 2> mp;
    pqnode(int co, vector<pii> &mp): mp() {
        this->mp[co] = move(mp);
        this->mp[co ^ 1].push_back({0, 0});
    }
    pqnode(array<vector<pii>, 2> &mp): mp() {
        this->mp[0] = move(mp[0]);
        this->mp[1] = move(mp[1]);
    }
    bool operator<(const pqnode &b) const {
        return mp.size() > b.mp.size();
    }
};
int n, k, ans;
void presum(vector<pii> &a) {
    repeat (i, 1, a.size()) {
        a[i].fi += a[i - 1].fi;
        a[i].se += a[i - 1].se;
    }
}
void prediff(vector<pii> &a) {
    repeat_back (i, 1, a.size()) {
        a[i].fi -= a[i - 1].fi;
        a[i].se -= a[i - 1].se;
    }
}
void mymerge(vector<pii> &A, vector<pii> &B) {
    if (A.size() < B.size())
        swap(A, B);
    repeat (i, 0, B.size()) {
        A[i].fi += B[i].fi;
        A[i].se += B[i].se;
    }
}
#define qB(x) (x < 0 ? pii() : x < (int)B.size() ? B[x] : B.back())
void ask(const vector<pii> &a, const vector<pii> &B, int ex, int wx) {
    repeat (i, 0, a.size()) {
        pii xx = qB(k - ex - i);
        ans += a[i].se * xx.se % mod * wx % mod + a[i].fi * xx.se % mod + a[i].se * xx.fi % mod;
        // orz(i, a[i].se * xx.se * wx + a[i].fi * xx.se + a[i].se * xx.fi);
    }
}
void dfs(int x) {
    x = center::get(x); // orz(x);
    vis[x] = 1;
    priority_queue<pqnode> q;
    for (auto i : a[x]) {  // 
        int p = i.fi;
        if (!vis[p]) {
            rec.clear();
            getdist(p, i.se, 0, w[p]);
            // orz(rec);
            repeat (j, 0, rec.size()) if (j <= k) {
                ans += rec[j].fi + w[x] * rec[j].se % mod;
                // orz("+=", rec[j].fi + w[x] * rec[j].se);
            }
            q.emplace(i.se, rec);
        }
    }
    while (q.size() > 1) {
        pqnode B = q.top();
        q.pop();
        pqnode A = q.top();
        q.pop();

        // orz(A.mp);
        // orz(B.mp);

        presum(B.mp[0]);
        presum(B.mp[1]);

        ask(A.mp[0], B.mp[0], 0, w[x]);
        ask(A.mp[1], B.mp[0], 1, w[x]);
        ask(A.mp[0], B.mp[1], 1, w[x]);
        ask(A.mp[1], B.mp[1], 0, w[x]);

        prediff(B.mp[0]);
        prediff(B.mp[1]);

        mymerge(A.mp[0], B.mp[0]);
        mymerge(A.mp[1], B.mp[1]);
        q.emplace(A);
    }
    ans += w[x];
    // orz(ans);
    // return;  ////////////////////
    for (auto i : a[x]) {  // 
        int p = i.fi;
        if (!vis[p]) {
            dfs(p);
        }
    }
}
void Solve() {
    n = read(), k = read();
    repeat (i, 1, n + 1) {
        w[i] = read();
    }
    repeat (i, 0, n - 1) {
        int x = read(), y = read(), co = read();
        a[x].emplace_back(y, co);
        a[y].emplace_back(x, co);
    }
    dfs(1);
    print(ans % mod);
}
signed main() {
    // freopen("data.txt", "r", stdin);
    int T = 1;  // T = read();
    repeat(ca, 1, T + 1) {
        try {
            Solve();
        } catch (signed) {
        }
    }
    return 0;
}