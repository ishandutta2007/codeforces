#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define gc() getchar()
//#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T> void read(T &x) {
    x = 0; int c = gc(); int flag = 0;
    while (c < '0' || c > '9') flag |= (c == '-'), c = gc();
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
    if (flag) x = -x;
}
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
constexpr int N = 200005;
int n, p;
int a[N], b[N], Max[N];
vector<int> G[N];

void dfs(int x, int f) {
    bool is_leaf = 1; int mx = 0, var = 0;
    for (auto &to : G[x]) if (to != f) {
        is_leaf = 0;
        dfs(to, x);
        if (checkmax(mx, b[Max[to]])) var = Max[to];
    }
    if (is_leaf) {
        Max[x] = x;
        b[x] = a[x];
    } else {
        if (b[var] < a[x]) b[var] = a[x];
        Max[x] = var;
    }
}

void init() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    p = max_element(a + 1, a + n + 1) - a;
    dfs(p, 0);
}

void solve() {
    if (sz(G[p]) == 1) {
        b[p] = a[p];
    } else {
        vector<int> seq;
        for (auto &to : G[p]) seq.push_back(Max[to]);
        sort(seq.begin(), seq.end(), [&](int u, int v) {
            return b[u] > b[v];
        });
        b[seq[0]] = a[p];
        b[seq[1]] = a[p];
    }
    ll ans = accumulate(b + 1, b + n + 1, 0LL);
    printf("%lld\n", ans);
}

int main() {
	//setIO("");
	int t = 1;
#ifdef CASES_WITH_T
	scanf("%d", &t); 
#endif
    while (t--) {
        init();
        solve();
    }
    return 0;
}