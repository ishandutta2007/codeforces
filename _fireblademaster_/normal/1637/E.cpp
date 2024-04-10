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
constexpr int N = 300005;
int n, m, k = 0;
array<int, 2> a[N];
map<int, int> Map;
map<int, vector<int>> G;
priority_queue<int> q[N], Q[N];

void init() {
    scanf("%d%d", &n, &m), k = 0;
    Map.clear();
    G.clear();
    for (int i = 1; i <= n; ++i) {
        while (!q[i].empty()) q[i].pop();
        while (!Q[i].empty()) Q[i].pop();
    }
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        Map[x] += 1;
    }
    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void ins(int x) {
    //see("ins"); outln(x);
    int oc = Map[x];
    q[oc].push(x);
}

void del(int x) {
    //see("del"); outln(x);
    int oc = Map[x];
    Q[oc].push(x);
}

ll calc(int x, int oc0, int oc) {
    while (!q[oc].empty() && !Q[oc].empty() && q[oc].top() == Q[oc].top()) {
        q[oc].pop();
        Q[oc].pop();
    }
    if (q[oc].empty()) return 0;
    return (ll)(oc0 + oc) * (x + q[oc].top());
}

void solve() {
    for (auto &[x, oc] : Map) ins(x);
    ll ans = 0;
    for (auto &[x, oc] : Map) {
        del(x);
        for (auto &ele : G[x]) del(ele);
        for (int i = 1; i <= oc; ++i) {
            checkmax(ans, calc(x, oc, i));
        }
        for (auto &ele : G[x]) ins(ele);
        ins(x);
    }
    printf("%lld\n", ans);
}

#define CASES_WITH_T
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