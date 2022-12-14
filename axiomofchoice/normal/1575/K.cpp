// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i, a, b) for (int i = (a), ib = (b); i < ib; i++)
#define repeat_back(i, a, b) for (int i = (b) - 1, ib = (a);i >= ib; i--)
#define fi first
#define se second
#define int ll
namespace start {
    typedef long long ll; const int inf = INT_MAX >> 1; const ll INF = INT64_MAX >> 1;
    typedef double lf; const lf pi = acos(-1); typedef pair<int, int> pii;
    mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        template <int fast = 0> ll read() { // will detect EOF
            if (!fast) { ll x; if (scanf("%lld", &x) != 1) exit(0); return x; }
            ll x = 0, tag = 1; int c = getchar(); for (; !isdigit(c); c = getchar()) { if (c == '-') tag = -1; if (c == EOF) exit(0); }
            for (; isdigit(c); c = getchar()) { x = x * 10 + c - 48; } if (c != EOF) ungetc(c, stdin);
            return x * tag;
        }
        lf readf() { double x; if (scanf("%lf", &x) != 1) exit(0); return x; } // will detect EOF
        template <class T> void write(T x) { if (x < 0) { x = -x, putchar('-'); } if (x >= 10) { write(x / 10); } putchar(x % 10 + 48); }
        void write(double x) { printf("%.12f", x); } void write(long double x) { printf("%.12f", double(x)); }
        template <class A, class B> void write(const pair<A, B> &x) { write(x.first); putchar(' '); write(x.second); }
        template <class T> void print(T x, int e = 1) { write(x); putchar(" \n"[e]); }
        template <class T> void print(const initializer_list<T> &a, int e = 1) { for (auto i = a.begin(), last = prev(a.end()); i != a.end(); i++) print(*i, e && i == last); }
        template <class T> void printArray(const T &a, int e = 1) { for (auto i = a.begin(), last = prev(a.end()); i != a.end(); i++) print(*i, e && i == last); }
        template <class T, int N> void mst(T (&a)[N], char c) { memset(a, c, sizeof a); }
        template <class T> T &MAX(T &a, const T &b) { if (a < b) a = b; return a; } template <class T> T &MIN(T &a, const T &b) { if (b < a) a = b; return a; }
        template <class T> vector<T> &operator<<(vector<T> &a, const T &b) { a.push_back(b); return a; }
        template <class T> T sqr(const T &x) { return x * x; }
        template <class T> void sortunique(T &a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }
        void OK(const char *msg = "Yes") { puts(msg); throw 0; } void GG(const char *msg = "No") { puts(msg); throw 0; }
        // int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
    const int N = 400010;
    const lf eps = 1e-9;
    const int mod = (1 ? 1000000007 : 998244353);
        int D(int x, int m = mod) { return x >= m ? x - m : x; }
        int mul(int a, int b, int m = mod) { return 1ll * a * b % m; }
        template <class T> int qpow(int a, T b, int m = mod) {
            int ans = 1;
            for (; b; a = mul(a, a, m), b >>= 1) if (b & 1)
                ans = mul(ans, a, m);
            return ans;
        }
} using namespace start;
const int debug = 1;struct zkw {
    ll U(ll x, ll y) { return max(x, y); }
    const ll a0 = 0;
    int n; ll a[N * 4];
    void init(int inn, ll in[] = nullptr) { // A[x] = a0 or in[x]
        n = 1; while (n < inn) n <<= 1;
        fill(a + n, a + n * 2, a0);
        if (in) repeat (i, 0, inn) a[n + i] = in[i];
        repeat_back (i, 1, n) up(i);
    }
    void up(int x) { // private
        a[x] = U(a[x * 2], a[x * 2 + 1]);
    }
    void assign(int x, ll k) { // A[x] = k
        a[x += n] = k;
        while (x >>= 1) up(x);
    }
    void add(int x, ll k) { // A[x] += k
        a[x += n] += k;
        while (x >>= 1) up(x);
    }
    ll query(int l, int r) { // U(A[l, r])
        ll ans = a0; l += n - 1, r += n + 1;
        while (l + 1 < r){
            if (~l & 1) ans = U(ans, a[l + 1]);
            if ( r & 1) ans = U(ans, a[r - 1]);
            l >>= 1, r >>= 1;
        }
        return ans;
    }
} tr;
vector<pii> mp[N];
void Solve() {
    int n = read(), m = read();
    int k = read();
    int r = read(), c = read();
    int x1 = read(), y1 = read(), x2 = read(), y2 = read();
    if (x1 == x2 && y1 == y2) {
        print(qpow(k, n * m));
    } else {
        print(qpow(k, n * m - r * c));
    }
}
signed main() {
    // freopen("data.txt", "r", stdin);
    int T = 1; // T = read();
    repeat (ca, 1, T + 1) {
        try { Solve(); } catch (signed) { }
    }
    return 0;
}