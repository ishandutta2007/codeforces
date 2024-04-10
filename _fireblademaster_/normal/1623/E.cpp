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
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
const int N = 1000010;
int n, k;
char s[N];
void init() {
    scanf("%d%d%s", &n, &k, s + 1);
}
char t[N];
int tt, l[N], r[N], id[N];
bool can[N];
void build(int u) {
    if (!u) {
        return;
    }
    build(l[u]);
    id[u] = ++tt;
    t[tt] = s[u];
    build(r[u]);
}
bool res[N];
bool solve(int u) {
    if (!u) {
        return false;
    }
    if (!k) {
        return false;
    }
    bool hv = can[id[u]];
    k--;
    if (solve(l[u])) {
        hv = true;
    }
    if (hv) {
        res[id[u]] = true;
    } else {
        k++;
    }
    if (hv) {
        solve(r[u]);
    }
    return hv;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &l[i], &r[i]);
    }
    build(1);
    for (int i = n - 1; i; i--)
        if (t[i] < t[i + 1]) {
            can[i] = true;
        } else
            if (t[i] == t[i + 1]) {
                can[i] = can[i + 1];
            }
    solve(1);
    // printf("%s",t+1);puts("");
    // for(int i=1;i<=n;i++) printf("%d ",can[i]);puts("");
    for (int i = 1; i <= n; i++) {
        putchar(t[i]);
        if (res[i]) {
            putchar(t[i]);
        }
    }
}

int main() {
    int t = 1;
    while (t--) {
        init();
        solve();
    }
    return 0;
}