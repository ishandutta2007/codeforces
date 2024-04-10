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

const int N = 300010;
int n, k, a[N], ch[N * 30][2], val[N * 30], tt = 1;

void insert(int v, int id) {
    int u = 1;
    for (int i = 30; i >= 0; i--) {
        int c = v >> i & 1;
        if (!ch[u][c]) {
            ch[u][c] = ++tt;
        }
        u = ch[u][c];
    }
    val[u] = id;
}

int ans[N], at;

void dfs_one(int u) {
    if (!u) {
        return;
    }
    if (val[u]) {
        ans[++at] = val[u];
        return;
    }
    if (ch[u][0]) {
        dfs_one(ch[u][0]);
    } else {
        dfs_one(ch[u][1]);
    }
}

bool dfs_two(int l, int r, int d) {
    if (!l || !r || d == -1) {
        return false;
    }
    if (k >> d & 1) {
        if (dfs_two(ch[l][0], ch[r][1], d - 1)) {
            return true;
        } else
            if (dfs_two(ch[l][1], ch[r][0], d - 1)) {
                return true;
            } else {
                return false;
            }
    }
    if (ch[l][0] && ch[r][1]) {
        dfs_one(ch[l][0]), dfs_one(ch[r][1]);
        return true;
    }
    if (ch[l][1] && ch[r][0]) {
        dfs_one(ch[l][1]), dfs_one(ch[r][0]);
        return true;
    }
    if (dfs_two(ch[l][0], ch[r][0], d - 1)) {
        return true;
    } else
        if (dfs_two(ch[l][1], ch[r][1], d - 1)) {
            return true;
        }
    return false;
}

void dfs(int u, int d = 30) {
    if (!u) {
        return;
    }
    if (val[u]) {
        ans[++at] = val[u];
        return;
    }
    if (k >> d & 1) {
        if (dfs_two(ch[u][0], ch[u][1], d - 1)) {
            return;
        }
        dfs_one(u);
        return;
    }
    dfs(ch[u][0], d - 1);
    dfs(ch[u][1], d - 1);
}

void init() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
}

void solve() {
    if (k == 0) {
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
        return;
    }
    --k;
    for (int i = 1; i <= n; i++) {
        insert(a[i], i);
    }
    dfs(1);
    if (at == 1) {
        puts("-1");
    } else {
        printf("%d\n", at);
        for (int i = 1; i <= at; i++) {
            printf("%d ", ans[i]);
        }
    }
}

int main() {
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